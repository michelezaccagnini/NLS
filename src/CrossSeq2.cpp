#include "plugin.hpp"
#include "CrossSeq2v.h"


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
		configInput(FREQ_INPUT, "freq input");
		configInput(RATE1_INPUT, "rate1 input");
		configInput(RATE2_INPUT, "rate2 input");
		configInput(SHAPE1_INPUT, "shape1 input");
		configInput(SHAPE2_INPUT, "shape2 input");
		configInput(AMT1_INPUT, "amt1 input");
		configInput(AMT2_INPUT, "amtt2 input");
		configInput(SYNC_INPUT, "sync input");
		configOutput(TRIG_OUTPUT, "trig");
		configOutput(LFO1_OUTPUT, "lfo1");
		configOutput(LFO2_OUTPUT, "lfo2");
		configOutput(DIFF_OUTPUT, "diff");
	}
	CrossSeq2_process_init();

	void process(const ProcessArgs& args) override {
		CrossSeq2_setFreq(processor, params[FREQ_PARAM].value, inputs[FREQ_INPUT].value);
		CrossSeq2_setSync(processor, inputs[SYNC_INPUT].value);
		CrossSeq2_setRate1(processor, params[RATE1_PARAM].value,   inputs[RATE1_INPUT].value, params[PHASE1_PARAM].value );
		CrossSeq2_setRate2(processor, params[RATE2_PARAM].value,   inputs[RATE2_INPUT].value, params[PHASE2_PARAM].value);
		CrossSeq2_setAmt1(processor, params[AMT1_PARAM].value,     inputs[AMT1_INPUT].value);
		CrossSeq2_setAmt2(processor, params[AMT2_PARAM].value,     inputs[AMT2_INPUT].value);
		CrossSeq2_setShape1(processor, params[SHAPE1_PARAM].value, inputs[SHAPE1_INPUT].value);
		CrossSeq2_setShape2(processor, params[SHAPE2_PARAM].value, inputs[SHAPE2_INPUT].value);
		CrossSeq2_setPw1(processor, params[PW1_PARAM].value);
		CrossSeq2_setPw2(processor, params[PW2_PARAM].value);
		CrossSeq2_process(processor,args.sampleTime);
		float trig = CrossSeq2_process_ret_0(processor);
		float lfo1 = CrossSeq2_process_ret_1(processor);
		float lfo2 = CrossSeq2_process_ret_2(processor);
		float diff = CrossSeq2_process_ret_3(processor);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[TRIG_OUTPUT].setVoltage(5.f * trig);
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

		addParam(createParam<Rogan1PBlue> (Vec(181, 275), module, CrossSeq2::FREQ_PARAM));
		addParam(createParam<Rogan1PBlue>  (Vec(50, 39), module, CrossSeq2::RATE1_PARAM));
		addParam(createParam<Rogan1PBlue>  (Vec(145, 39), module, CrossSeq2::RATE2_PARAM));
		addParam(createParam<Rogan1PGreen> (Vec(50, 80), module, CrossSeq2::AMT1_PARAM));
		addParam(createParam<Rogan1PGreen> (Vec(145, 80), module, CrossSeq2::AMT2_PARAM));
		addParam(createParam<Rogan1PRed>   (Vec(50, 121), module, CrossSeq2::SHAPE1_PARAM));
		addParam(createParam<Rogan1PRed>   (Vec(145, 121), module, CrossSeq2::SHAPE2_PARAM));
		addParam(createParam<Rogan1PWhite> (Vec(50, 162), module, CrossSeq2::PHASE1_PARAM));
		addParam(createParam<Rogan1PWhite> (Vec(145, 162), module, CrossSeq2::PHASE2_PARAM));
		addParam(createParam<Rogan1PWhite> (Vec(50, 203), module, CrossSeq2::PW1_PARAM));
		addParam(createParam<Rogan1PWhite> (Vec(145, 203), module, CrossSeq2::PW2_PARAM));

		addInput(createInput<CL1362Port>(Vec(181, 224), module, CrossSeq2::FREQ_INPUT));
		addInput(createInput<CL1362Port>(Vec(9, 224), module, CrossSeq2::SYNC_INPUT));
		addInput(createInput<CL1362Port>(Vec(9, 39), module, CrossSeq2::RATE1_INPUT));
		addInput(createInput<CL1362Port>(Vec(181, 39) , module, CrossSeq2::RATE2_INPUT));
		addInput(createInput<CL1362Port>(Vec(9, 80), module, CrossSeq2::AMT1_INPUT));
		addInput(createInput<CL1362Port>(Vec(181, 80), module, CrossSeq2::AMT2_INPUT));
		addInput(createInput<CL1362Port>(Vec(9, 121), module, CrossSeq2::SHAPE1_INPUT));
		addInput(createInput<CL1362Port>(Vec(181, 121), module, CrossSeq2::SHAPE2_INPUT));
		addOutput(createOutput<CL1362Port>(Vec(11,  329), module, CrossSeq2::TRIG_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(66,   329), module, CrossSeq2::LFO1_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(121,   329), module, CrossSeq2::LFO2_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(176,   329), module, CrossSeq2::DIFF_OUTPUT));

	}
};


Model* modelCrossSeq2 = createModel<CrossSeq2, CrossSeq2Widget>("CrossSeq2");