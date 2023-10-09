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
		configParam(FREQ_PARAM, 0.f, 10.f, 1.f, "freq");
		configParam(RATE1_PARAM, 0.f, 10.f, 1.f, "rate1");
		configParam(RATE2_PARAM, 0.f, 10.f, 0.5f, "rate2");
		configParam(AMT1_PARAM, 0.f, 1.0f, 1.f, "amount1");
		configParam(AMT2_PARAM, 0.f, 1.f, 1.f, "amount2");
		configParam(SHAPE1_PARAM, 0.f, 3.f, 0.f, "shape1");
		configParam(SHAPE2_PARAM, 0.f, 3.f, 1.f, "shape2");
		configParam(PHASE1_PARAM, 0.f, 1.f, 0.f, "phase1");
		configParam(PHASE2_PARAM, 0.f, 1.f, 0.f, "phase2");
		configParam(PW1_PARAM, 0.f, 1.f, 0.5f, "pw1");
		configParam(PW2_PARAM, 0.f, 1.f, 0.5f, "pw2");
		configParam(CVR1_PARAM, -1.f, 1.f, 0.f, "cv rate1");
		configParam(CVR2_PARAM, -1.f, 1.f, 0.f, "cv rate2");
		configParam(CVAM1_PARAM, -1.f, 1.f, 0.f, "cv amount1");
		configParam(CVAM2_PARAM, -1.f, 1.f, 0.f, "cv amount2");
		configParam(CVSH1_PARAM, -1.f, 1.f, 0.f, "cv shape1");
		configParam(CVSH2_PARAM, -1.f, 1.f, 0.f, "cv shape2");
		
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

	void process(const ProcessArgs& args) override {
		CrossSeq2_setFreq(processor, params[FREQ_PARAM].value, inputs[FREQ_INPUT].value);
		CrossSeq2_setSync(processor, inputs[SYNC_INPUT].value);
		CrossSeq2_setRate1(processor, params[RATE1_PARAM].value,   inputs[RATE1_INPUT].value * params[CVR1_PARAM].value, params[PHASE1_PARAM].value );
		CrossSeq2_setRate2(processor, params[RATE2_PARAM].value,   inputs[RATE2_INPUT].value * params[CVR2_PARAM].value, params[PHASE2_PARAM].value);
		CrossSeq2_setAmt1(processor, params[AMT1_PARAM].value,     inputs[AMT1_INPUT].value * params[CVAM1_PARAM].value);
		CrossSeq2_setAmt2(processor, params[AMT2_PARAM].value,     inputs[AMT2_INPUT].value * params[CVAM2_PARAM].value);
		CrossSeq2_setShape1(processor, params[SHAPE1_PARAM].value, inputs[SHAPE1_INPUT].value * params[CVSH1_PARAM].value);
		CrossSeq2_setShape2(processor, params[SHAPE2_PARAM].value, inputs[SHAPE2_INPUT].value * params[CVSH2_PARAM].value);
		CrossSeq2_setPw1(processor, params[PW1_PARAM].value);
		CrossSeq2_setPw2(processor, params[PW2_PARAM].value);
		CrossSeq2_process(processor,args.sampleTime);
		float trig = CrossSeq2_process_ret_0(processor);
		float lfo1 = CrossSeq2_process_ret_1(processor);
		float lfo2 = CrossSeq2_process_ret_2(processor);
		float diff = CrossSeq2_process_ret_3(processor);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[TRIG_OUTPUT].setVoltage(10.f * trig);
		outputs[LFO1_OUTPUT].setVoltage(5.f * lfo1);
		outputs[LFO2_OUTPUT].setVoltage(5.f * lfo2);
		outputs[DIFF_OUTPUT].setVoltage(5.f * diff);
	}
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
