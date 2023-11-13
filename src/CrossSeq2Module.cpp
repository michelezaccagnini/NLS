#include "plugin.hpp"
#include "CrossSeq2.h"


struct CrossSeq2 : Module {

	enum ParamId {
		FREQ_PARAM,	
		RATE1_PARAM,
		RATE2_PARAM,
		AMT1_PARAM,
		AMT2_PARAM,
		SHAPE1_PARAM,
		SHAPE2_PARAM,
		PHASE1_PARAM,
		PHASE2_PARAM,
		PW1_PARAM,
		PW2_PARAM,
		CVR1_PARAM,
		CVR2_PARAM,
		CVAM1_PARAM,
		CVAM2_PARAM,
		CVSH1_PARAM,
		CVSH2_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		FREQ_INPUT,
		RATE1_INPUT,
		RATE2_INPUT,	
		SHAPE1_INPUT,
		SHAPE2_INPUT,
		AMT1_INPUT,
		AMT2_INPUT,
		SYNC_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		TRIG_OUTPUT,
		LFO1_OUTPUT,
		LFO2_OUTPUT,
		DIFF_OUTPUT,
		OUTPUTS_LEN
	};
	CrossSeq2_process_type processor;

	CrossSeq2() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN);
		configParam(FREQ_PARAM, 0.f, 10.f, 1.f,   "freq"      );
		configParam(RATE1_PARAM, 0.f, 10.f, 1.f,  "rate1"     );
		configParam(RATE2_PARAM, 0.f, 10.f, 0.5f, "rate2"     );
		configParam(AMT1_PARAM, 0.f, 1.0f, 1.f,   "amount1"   );
		configParam(AMT2_PARAM, 0.f, 1.f, 1.f,    "amount2"   );
		configParam(SHAPE1_PARAM, 0.f, 3.f, 0.f,  "shape1"    );
		configParam(SHAPE2_PARAM, 0.f, 3.f, 1.f,  "shape2"    );
		configParam(PHASE1_PARAM, 0.f, 1.f, 0.f,  "phase1"    );
		configParam(PHASE2_PARAM, 0.f, 1.f, 0.f,  "phase2"    );
		configParam(PW1_PARAM, 0.f, 1.f, 0.5f,    "pw1"       );
		configParam(PW2_PARAM, 0.f, 1.f, 0.5f,    "pw2"       );
		configParam(CVR1_PARAM, -1.f, 1.f, 0.f,   "cvrate1"  );
		configParam(CVR2_PARAM, -1.f, 1.f, 0.f,   "cvrate2"  );
		configParam(CVAM1_PARAM, -1.f, 1.f, 0.f,  "cvamount1");
		configParam(CVAM2_PARAM, -1.f, 1.f, 0.f,  "cvamount2");
		configParam(CVSH1_PARAM, -1.f, 1.f, 0.f,  "cvshape1" );
		configParam(CVSH2_PARAM, -1.f, 1.f, 0.f,  "cvshape2" );
		
		configInput(FREQ_INPUT, "freq input");
		configInput(RATE1_INPUT, "rate1 input");
		configInput(RATE2_INPUT, "rate2 input");
		configInput(SHAPE1_INPUT, "shape1 input");
		configInput(SHAPE2_INPUT, "shape2 input");
		configInput(AMT1_INPUT, "amt1 input");
		configInput(AMT2_INPUT, "amt2 input");
		configInput(SYNC_INPUT, "sync input");
		configOutput(TRIG_OUTPUT, "trig");
		configOutput(LFO1_OUTPUT, "lfo1");
		configOutput(LFO2_OUTPUT, "lfo2");
		configOutput(DIFF_OUTPUT, "diff");
	}
	void CrossSeq2_process_init() ;
	float sampleTime = 1.0f / 44100.0f;
	
	float freq      ;       
	float rate1    ;   
	float rate2    ;   
	float amount1  ;
	float amount2  ;
	float shape1   ;
	float shape2   ;
	float phase1   ;
	float phase2   ;
	float pw1       ;
	float pw2       ;
	float cvrate1  ;
	float cvrate2  ;
	float cvamount1;
	float cvamount2;
	float cvshape1 ;
	float cvshape2 ;
	void process(const ProcessArgs& args) override {
		freq      = params[FREQ_PARAM].value;
        rate1     = params[RATE1_PARAM].value;
        rate2     = params[RATE2_PARAM].value;
        amount1   = params[AMT1_PARAM].value;
        amount2   = params[AMT2_PARAM].value;
        shape1    = params[SHAPE1_PARAM].value;
        shape2    = params[SHAPE2_PARAM].value;
        phase1    = params[PHASE1_PARAM].value;
        phase2    = params[PHASE2_PARAM].value;
        pw1       = params[PW1_PARAM].value;
        pw2       = params[PW2_PARAM].value;
        cvrate1   = params[CVR1_PARAM].value;
        cvrate2   = params[CVR2_PARAM].value;
        cvamount1 = params[CVAM1_PARAM].value;
        cvamount2 = params[CVAM2_PARAM].value;
        cvshape1  = params[CVSH1_PARAM].value;
        cvshape2  = params[CVSH2_PARAM].value;

		
		CrossSeq2_setFreq(processor, freq, inputs[FREQ_INPUT].value);
		CrossSeq2_setSync(processor, inputs[SYNC_INPUT].value);
		CrossSeq2_setRate1(processor, rate1,   ( inputs[RATE1_INPUT].getVoltage() / 10.0f) * cvrate1);
		CrossSeq2_setRate2(processor, rate2,   ( inputs[RATE2_INPUT].getVoltage() / 10.0f) * cvrate2);
		CrossSeq2_setAmt1(processor, amount1,     (  inputs[AMT1_INPUT].getVoltage() / 10.0f) * cvamount1);
		CrossSeq2_setAmt2(processor, amount2,     (  inputs[AMT2_INPUT].getVoltage() / 10.0f) * cvamount2);
		CrossSeq2_setShape1(processor, shape1, (inputs[SHAPE1_INPUT].getVoltage() / 10.0f) * cvshape1);
		CrossSeq2_setShape2(processor, shape2, (inputs[SHAPE2_INPUT].getVoltage() / 10.0f) * cvshape2);
		CrossSeq2_setPw1(processor, pw1);
		CrossSeq2_setPw2(processor, pw2);
		CrossSeq2_setPhase1(processor, phase1*2.0);
		CrossSeq2_setPhase2(processor, phase2*2.0);
		CrossSeq2_process(processor, sampleTime);
		float trig = CrossSeq2_process_ret_0(processor);
		float lfo1 = CrossSeq2_process_ret_1(processor);
		float lfo2 = CrossSeq2_process_ret_2(processor);
		float diff = CrossSeq2_process_ret_3(processor);
		outputs[TRIG_OUTPUT].setVoltage(10.f * trig);
		outputs[LFO1_OUTPUT].setVoltage(5.f * lfo1);
		outputs[LFO2_OUTPUT].setVoltage(5.f * lfo2);
		outputs[DIFF_OUTPUT].setVoltage(5.f * diff);
	}
	json_t* dataToJson() override {
		json_t* rootJ = json_object();
		json_object_set_new(rootJ, "freq",      json_real(freq     ));
		json_object_set_new(rootJ, "rate1",     json_real(rate1    ));
		json_object_set_new(rootJ, "rate2",     json_real(rate2    ));
		json_object_set_new(rootJ, "amount1",   json_real(amount1  ));
		json_object_set_new(rootJ, "amount2",   json_real(amount2  ));
		json_object_set_new(rootJ, "shape1",    json_real(shape1   ));
		json_object_set_new(rootJ, "shape2",    json_real(shape2   ));
		json_object_set_new(rootJ, "phase1",    json_real(phase1   ));
		json_object_set_new(rootJ, "phase2",    json_real(phase2   ));
		json_object_set_new(rootJ, "pw1",       json_real(pw1      ));
		json_object_set_new(rootJ, "pw2",       json_real(pw2      ));
		json_object_set_new(rootJ, "cvrate1",   json_real(cvrate1  ));
		json_object_set_new(rootJ, "cvrate2",   json_real(cvrate2  ));
		json_object_set_new(rootJ, "cvamount1", json_real(cvamount1));
		json_object_set_new(rootJ, "cvamount2", json_real(cvamount2));
		json_object_set_new(rootJ, "cvshape1",  json_real(cvshape1 ));
		json_object_set_new(rootJ, "cvshape2",  json_real(cvshape2 ));

		return rootJ;
	}
	
	void dataFromJson(json_t* rootJ) override {
		json_t* freqJ = json_object_get(rootJ, 		"freq     ");
		json_t* rate1J = json_object_get(rootJ, 	"rate1    ");
		json_t* rate2J = json_object_get(rootJ, 	"rate2    ");
		json_t* amount1J = json_object_get(rootJ, 	"amount1  ");
		json_t* amount2J = json_object_get(rootJ, 	"amount2  ");
		json_t* shape1J = json_object_get(rootJ, 	"shape1   ");
		json_t* shape2J = json_object_get(rootJ, 	"shape2   ");
		json_t* phase1J = json_object_get(rootJ, 	"phase1   ");
		json_t* phase2J = json_object_get(rootJ, 	"phase2   ");
		json_t* pw1J = json_object_get(rootJ, 		"pw1      ");
		json_t* pw2J = json_object_get(rootJ, 		"pw2      ");
		json_t* cvrate1J = json_object_get(rootJ, 	"cvrate1  ");
		json_t* cvrate2J = json_object_get(rootJ, 	"cvrate2  ");
		json_t* cvamount1J = json_object_get(rootJ, "cvamount1");
		json_t* cvamount2J = json_object_get(rootJ, "cvamount2");
		json_t* cvshape1J = json_object_get(rootJ, "cvshape1 ");
		json_t* cvshape2J = json_object_get(rootJ, "cvshape2 ");
		if (freqJ){
			freq       = json_real_value(freqJ     );
		}
		if (rate1J){
			rate1      = json_real_value(rate1J    );
		}
		if (rate2J){
			rate2      = json_real_value(rate2J    );
		}
		if (amount1J){
			amount1    = json_real_value(amount1J  );
		}
		if (amount2J){
			amount2    = json_real_value(amount2J  );
		}
		if (shape1J){
			shape1     = json_real_value(shape1J   );
		}
		if (shape2J){
			shape2     = json_real_value(shape2J   );
		}
		if (phase1J){
			phase1     = json_real_value(phase1J   );
		}
		if (phase2J){
			phase2     = json_real_value(phase2J   );
		}
		if (pw1J){
			pw1        = json_real_value(pw1J      );
		}
		if (pw2J){
			pw2        = json_real_value(pw2J      );
		}
		if (cvrate1J){
			cvrate1   =  json_real_value(cvrate1J  );
		}
		if (cvrate2J){
			cvrate2   =  json_real_value(cvrate2J  );
		}
		if (cvamount1J){
			cvamount1 =  json_real_value(cvamount1J);
		}
		if (cvamount2J){
			cvamount2 =  json_real_value(cvamount2J);
		}
		if (cvshape1J){
			cvshape1  =  json_real_value(cvshape1J );
		}
		if (cvshape2J){
			cvshape2  =  json_real_value(cvshape2J );
		}
		
	}
	void onSampleRateChange(const SampleRateChangeEvent& e) override {
        sampleTime = 1.0f / e.sampleRate;
    }
	//void paramsFromJson(json_t* rootJ) override {
	//	params[FREQ_PARAM].setValue(1.f);
	//	params[RATE1_PARAM].setValue(1.f);
	//	params[RATE2_PARAM].setValue(1.f);
	//	params[AMT1_PARAM].setValue(1.f);
	//	params[AMT2_PARAM].setValue(1.f);
	//	params[SHAPE1_PARAM].setValue(0.f);
	//	params[SHAPE2_PARAM].setValue(1.f);
	//	params[PW1_PARAM].setValue(0.5f);
	//	params[PW2_PARAM].setValue(0.5f);
	//	params[PHASE1_PARAM].setValue(0.f);
	//	params[PHASE2_PARAM].setValue(0.f);
	//	params[	CVR1_PARAM].setValue(0.f);
	//	params[	CVR2_PARAM].setValue(0.f);
	//	params[	CVAM1_PARAM].setValue(0.f);
	//	params[	CVAM2_PARAM].setValue(0.f);
	//	params[	CVSH1_PARAM].setValue(0.f);
	//	params[	CVSH2_PARAM].setValue(0.f);
//
	//	Module::paramsFromJson(rootJ);
	//}

};



struct CrossSeq2Widget : ModuleWidget {
	CrossSeq2Widget(CrossSeq2* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/cross2New.svg")));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParam<RoundSmallBlackKnob> (Vec(194, 266), module, CrossSeq2::FREQ_PARAM));
		addParam(createParam<RoundSmallBlackKnob>  (Vec(73, 46), module, CrossSeq2::RATE1_PARAM));
		addParam(createParam<BefacoTinyKnob>  (Vec(6, 46), module, CrossSeq2::CVR1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>  (Vec(127, 46), module, CrossSeq2::RATE2_PARAM));
		addParam(createParam<BefacoTinyKnob>  (Vec(193, 46), module, CrossSeq2::CVR2_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(73, 80), module, CrossSeq2::AMT1_PARAM));
		addParam(createParam<BefacoTinyKnob> (Vec(6, 80), module, CrossSeq2::CVAM1_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(127, 80), module, CrossSeq2::AMT2_PARAM));
		addParam(createParam<BefacoTinyKnob> (Vec(193, 80), module, CrossSeq2::CVAM2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(73, 121), module, CrossSeq2::SHAPE1_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(6, 121), module, CrossSeq2::CVSH1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(127, 121), module, CrossSeq2::SHAPE2_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(193, 121), module, CrossSeq2::CVSH2_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(73, 162), module, CrossSeq2::PHASE1_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(127, 162), module, CrossSeq2::PHASE2_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(73, 203), module, CrossSeq2::PW1_PARAM));
		addParam(createParam<RoundSmallBlackKnob> (Vec(130, 203), module, CrossSeq2::PW2_PARAM));

		addInput(createInput<CL1362Port>(Vec(156, 262), module, CrossSeq2::FREQ_INPUT));
		addInput(createInput<CL1362Port>(Vec(36, 262), module, CrossSeq2::SYNC_INPUT));
		addInput(createInput<CL1362Port>(Vec(36,  39) , module, CrossSeq2::RATE1_INPUT));
		addInput(createInput<CL1362Port>(Vec(154, 39) , module, CrossSeq2::RATE2_INPUT));
		addInput(createInput<CL1362Port>(Vec(36,  76), module, CrossSeq2::AMT1_INPUT));
		addInput(createInput<CL1362Port>(Vec(154, 76), module, CrossSeq2::AMT2_INPUT));
		addInput(createInput<CL1362Port>(Vec(36,  117), module, CrossSeq2::SHAPE1_INPUT));
		addInput(createInput<CL1362Port>(Vec(154, 117), module, CrossSeq2::SHAPE2_INPUT));
		
		addOutput(createOutput<CL1362Port>(Vec(23,    325), module, CrossSeq2::TRIG_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(72,    325), module, CrossSeq2::LFO1_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(120,   325), module, CrossSeq2::LFO2_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(169,   325), module, CrossSeq2::DIFF_OUTPUT));

	}
};


Model* modelCrossSeq2 = createModel<CrossSeq2, CrossSeq2Widget>("CrossSeq2");
