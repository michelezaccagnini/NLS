#include "plugin.hpp"
#include "GraviHarm.h"

struct GraviHarm : Module {

   enum ParamIds {
      NOTEK,
      CHORK,
      PLANK,
      OCTAK,
      NUM_PARAMS
   };
   enum InputIds {
      TRI_NOTE,
      TRI_CHOR,
      TRI_PLAN,
      RESET,
      IN_NOTE,
      IN_CHOR,
      IN_PLAN,

      NUM_INPUTS
   };
   enum OutputIds {
      VOCT,
      NOTE_IND,
      CHOR_IND,
      PLAN_IND,

      NUM_OUTPUTS
   };
   enum LightIds { NUM_LIGHTS };

   GraviHarm_process_type processor;

   GraviHarm(){
      config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
      configParam(NOTEK, 0, 4, 0, "Note");
      paramQuantities[NOTEK]->snapEnabled = true;
      configParam(CHORK, 0, 4, 0, "Chord");
      paramQuantities[CHORK]->snapEnabled = true;
      configParam(PLANK, 0, 24, 0, "Planet");
      paramQuantities[PLANK]->snapEnabled = true;
      configParam(OCTAK, -5, 5, 0, "Octave");
      paramQuantities[OCTAK]->snapEnabled = true;
      configInput(IN_NOTE, "note"  );
      configInput(IN_CHOR, "chord" );
      configInput(IN_PLAN, "planet");
      configInput(TRI_NOTE, "note trig");
      configInput(TRI_CHOR, "chord trig");
      configInput(TRI_PLAN, "planet trig");
      configInput(RESET, "reset");
   }
   void GraviHarm_process_init() ;
   void process(const ProcessArgs &args) override {
      // Reads all the input values and normalizes the values
      float inNote = (inputs[IN_NOTE].getVoltage() / 10.0f);
      float inChor = (inputs[IN_CHOR].getVoltage() / 10.0f) ;
      float inPlan = (inputs[IN_PLAN].getVoltage() / 10.0f ) ;
      //float  = (inputs[IN4].getVoltage() ) ;

      float trigNote = inputs[TRI_NOTE].getVoltage()/ 10.0f;
      float trigChor = inputs[TRI_CHOR].getVoltage()/ 10.0f;
      float trigPlan = inputs[TRI_PLAN].getVoltage()/ 10.0f;
      float reset = inputs[RESET].getVoltage() / 10.0f;
      // Reads all the parameters and sets them.
      // The parameters could be set at a lower rate if needed
      //{
      float knobNote = params[NOTEK].getValue();
      float knobChor = params[CHORK].getValue();
      float knobPlan = params[PLANK].getValue();
      float knobOcta = params[OCTAK].getValue();

      GraviHarm_setKnobNote(processor, knobNote);
      GraviHarm_setKnobChor(processor, knobChor);
      GraviHarm_setKnobPlan(processor, knobPlan);
      GraviHarm_setKnobOcta(processor, knobOcta);
   //}

      GraviHarm_process(processor, inNote, inChor, inPlan, trigNote, trigChor, trigPlan,  reset, args.sampleRate);

      outputs[VOCT].setVoltage(GraviHarm_process_ret_0(processor));
      outputs[NOTE_IND].setVoltage(GraviHarm_process_ret_1(processor));
      outputs[CHOR_IND].setVoltage(GraviHarm_process_ret_2(processor));
      outputs[PLAN_IND].setVoltage(GraviHarm_process_ret_3(processor));
   }
   //json_t* dataToJson() override {
	//	json_t* rootJ = json_object();

};
struct GraviHarmWidget : ModuleWidget {
   GraviHarmWidget(GraviHarm *module) {
      setModule(module);

      setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/GraviHarm.svg")));

      addChild(createWidget<ScrewBlack>(Vec(15, 3)));
      addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 3)));
      addChild(createWidget<ScrewBlack>(Vec(15, 367)));
      addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 367)));

      addParam(createParam<Rogan3PWhite>(Vec(19, 59), module, GraviHarm::NOTEK));
      addParam(createParam<Rogan3PWhite>(Vec(89, 59), module, GraviHarm::CHORK));
      addParam(createParam<Rogan3PWhite>(Vec(19, 130), module, GraviHarm::PLANK));
      addParam(createParam<Rogan3PWhite>(Vec(89, 130), module, GraviHarm::OCTAK));

      for (int i = 0; i < 4; i++) {
         addInput(createInput<PJ301MPort>(Vec(10 + 35 * i, 238), module, GraviHarm::TRI_NOTE + i));
      }

      for (int i = 0; i < 3; i++)
         addInput(createInput<PJ301MPort>(Vec(20 + 45 * i, 273), module, GraviHarm::IN_NOTE + i));

      for (int i = 0; i < 4; i++)
         addOutput(createOutput<PJ301MPort>(Vec(10 + 35 * i, 313), module, GraviHarm::VOCT + i));
   }
};

Model *modelGraviHarm = createModel<GraviHarm, GraviHarmWidget>("GraviHarm");
