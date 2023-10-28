#include "plugin.hpp"
#include "GraviHarm.h"

struct GraviHarm : Module {

   enum ParamIds {
      KNOB1,
      KNOB2,
      KNOB3,
      KNOB4,

      MOD1,
      MOD2,
      MOD3,
      MOD4,

      NUM_PARAMS
   };
   enum InputIds {
      MOD_IN1,
      MOD_IN2,
      MOD_IN3,
      MOD_IN4,

      IN1,
      IN2,
      IN3,
      IN4,

      NUM_INPUTS
   };
   enum OutputIds {
      OUT1,
      OUT2,
      OUT3,
      OUT4,

      NUM_OUTPUTS
   };
   enum LightIds { NUM_LIGHTS };

   Processor_process_type processor;

      GraviHarm();
   void process(const ProcessArgs &args) override;
};

GraviHarm::GraviHarm() {
   config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);

   configParam(GraviHarm::KNOB1, 0.0, 4.0, 0.0, "Note", " index", 0, 4);
   paramQuantities[KNOB1]->snapEnabled = true;
   configParam(GraviHarm::KNOB2, 0.0, 4.0, 0.0, "Chord", " index", 0, 4);
   paramQuantities[KNOB2]->snapEnabled = true;
   configParam(GraviHarm::KNOB3, 0.0, 24.0, 0.0, "Planet", " index", 0, 24);
   paramQuantities[KNOB3]->snapEnabled = true;
   configParam(GraviHarm::KNOB4, -5.0, 5.0, 0.0, "Octave", " octave", -5, 5);
   paramQuantities[KNOB4]->snapEnabled = true;

   configParam(GraviHarm::MOD1, -1.0, 1.0, 0.0, "Mod 1", " %", 0.0f, 100.f);
   configParam(GraviHarm::MOD2, -1.0, 1.0, 0.0, "Mod 2", " %", 0.0f, 100.f);
   configParam(GraviHarm::MOD3, -1.0, 1.0, 0.0, "Mod 3", " %", 0.0f, 100.f);
   configParam(GraviHarm::MOD4, -1.0, 1.0, 0.0, "Mod 4", " %", 0.0f, 100.f);

   Processor_process_init(processor);
}

void GraviHarm::process(const ProcessArgs &args) {
   // Reads all the input values and normalizes the values
   float inNote = (inputs[IN1].getVoltage() / 10.0f);
   float inChor = (inputs[IN2].getVoltage() / 10.0f) ;
   //float inPlan = (inputs[IN3].getVoltage() / 10.0f ) ;
   //float  = (inputs[IN4].getVoltage() ) ;
   
   float trigNote = inputs[MOD_IN1].getVoltage();
   float trigChor = inputs[MOD_IN2].getVoltage();
   float trigPlan = inputs[MOD_IN3].getVoltage();
   float reset = inputs[MOD_IN4].getVoltage() / 10.0f;
   // Reads all the parameters and sets them.
   // The parameters could be set at a lower rate if needed
   //{
      float knobNote = params[KNOB1].getValue();
      float knobChor = params[KNOB2].getValue();
      float knobPlan = params[KNOB3].getValue();
      float knobOcta = params[KNOB4].getValue();
      //float mod1 = params[MOD1].getValue();
      //float mod2 = params[MOD2].getValue();
      //float mod3 = params[MOD3].getValue();
      //float mod4 = params[MOD4].getValue();
      Processor_setKnobNote(processor, knobNote);
      Processor_setKnobChor(processor, knobChor);
      Processor_setKnobPlan(processor, knobPlan);
      Processor_setKnobOcta(processor, knobOcta);
   //}

   Processor_process(processor, inNote, inChor, trigNote, trigChor, trigPlan,  reset, args.sampleRate);

   outputs[OUT1].setVoltage(Processor_process_ret_0(processor));
   outputs[OUT2].setVoltage(Processor_process_ret_1(processor));
   outputs[OUT3].setVoltage(Processor_process_ret_2(processor));
   outputs[OUT4].setVoltage(Processor_process_ret_3(processor));
}

struct GraviHarmWidget : ModuleWidget {
   GraviHarmWidget(GraviHarm *module) {
      setModule(module);

      setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/Playground.svg")));

      addChild(createWidget<ScrewBlack>(Vec(15, 3)));
      addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 3)));
      addChild(createWidget<ScrewBlack>(Vec(15, 367)));
      addChild(createWidget<ScrewBlack>(Vec(box.size.x - 30, 367)));

      addParam(createParam<Rogan3PWhite>(Vec(19, 59), module, GraviHarm::KNOB1));
      addParam(createParam<Rogan3PWhite>(Vec(89, 59), module, GraviHarm::KNOB2));
      addParam(createParam<Rogan3PWhite>(Vec(19, 130), module, GraviHarm::KNOB3));
      addParam(createParam<Rogan3PWhite>(Vec(89, 130), module, GraviHarm::KNOB4));

      for (int i = 0; i < 4; i++) {
         addParam(createParam<RoundSmallBlackKnob>(Vec(10 + 35 * i, 204), module, GraviHarm::MOD1 + i));
         addInput(createInput<PJ301MPort>(Vec(10 + 35 * i, 238), module, GraviHarm::MOD_IN1 + i));
      }

      for (int i = 0; i < 4; i++)
         addInput(createInput<PJ301MPort>(Vec(10 + 35 * i, 273), module, GraviHarm::IN1 + i));

      for (int i = 0; i < 4; i++)
         addOutput(createOutput<PJ301MPort>(Vec(10 + 35 * i, 313), module, GraviHarm::OUT1 + i));
   }
};

Model *modelGraviHarm = createModel<GraviHarm, GraviHarmWidget>("GraviHarm");
