#include "plugin.hpp"
#include "CrossSeq3.h"


struct CrossSeq3 : Module {

	enum ParamId {
		FREQ_PARAM,	
		RATE1_PARAM,
		RATE2_PARAM,
		RATE3_PARAM,
		CVRT1_PARAM,
		CVRT2_PARAM,
		CVRT3_PARAM,
		AMT1_PARAM,
		AMT2_PARAM,
		AMT3_PARAM,
		CVAM1_PARAM,
		CVAM2_PARAM,
		CVAM3_PARAM,
		SHAPE1_PARAM,
		SHAPE2_PARAM,
		SHAPE3_PARAM,
		CVSH1_PARAM,
		CVSH2_PARAM,
		CVSH3_PARAM,
		PHASE1_PARAM,
		PHASE2_PARAM,
		PHASE3_PARAM,
		PW1_PARAM,
		PW2_PARAM,
		PW3_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		FREQ_INPUT,
		RATE1_INPUT,
		RATE2_INPUT,	
		RATE3_INPUT,	
		SHAPE1_INPUT,
		SHAPE2_INPUT,
		SHAPE3_INPUT,
		AMT1_INPUT,
		AMT2_INPUT,
		AMT3_INPUT,
		SYNC_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		TRIG12_OUTPUT,
		TRIG13_OUTPUT,
		TRIG23_OUTPUT,
		TRIG123_OUTPUT,
		LFO1_OUTPUT,
		LFO2_OUTPUT,
		LFO3_OUTPUT,
		DIFF12_OUTPUT,
		DIFF13_OUTPUT,
		DIFF23_OUTPUT,
		DIFF123_OUTPUT,
		OUTPUTS_LEN
	};
	CrossSeq3_process_type processor;

	CrossSeq3() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN);
		configParam(FREQ_PARAM, 0.f, 10.f, 1.f, "freq");
		configParam(RATE1_PARAM, 0.f, 10.f, 1.f, "rate1");
		configParam(RATE2_PARAM, 0.f, 10.f, 0.5f, "rate2");
		configParam(RATE3_PARAM, 0.f, 10.f, 0.5f, "rate3");
		configParam(CVRT1_PARAM, -1.f, 1.f, 0.f, "CV rate1");
		configParam(CVRT2_PARAM, -1.f, 1.f, 0.f, "CV rate2");
		configParam(CVRT3_PARAM, -1.f, 1.f, 0.f, "CV rate3");
		configParam(AMT1_PARAM, 0.f, 1.0f, 1.f, "amount1");
		configParam(AMT2_PARAM, 0.f, 1.f, 1.f, "amount2");
		configParam(AMT3_PARAM, 0.f, 1.f, 1.f, "amount3");
		configParam(CVAM1_PARAM, -1.f, 1.f, 0.f, "CV amount1");
		configParam(CVAM2_PARAM, -1.f, 1.f, 0.f, "CV amount2");
		configParam(CVAM3_PARAM, -1.f, 1.f, 0.f, "CV amount3");
		configParam(SHAPE1_PARAM, 0.f, 3.f, 0.f, "shape1");
		configParam(SHAPE2_PARAM, 0.f, 3.f, 1.f, "shape2");
		configParam(SHAPE3_PARAM, 0.f, 3.f, 1.f, "shape3");
		configParam(CVSH1_PARAM, -3.f, 3.f, 0.f, "CV shape1");
		configParam(CVSH2_PARAM, -3.f, 3.f, 0.f, "CV shape2");
		configParam(CVSH3_PARAM, -3.f, 3.f, 0.f, "CV shape3");
		configParam(PHASE1_PARAM, 0.f, 1.f, 0.f, "phase1");
		configParam(PHASE2_PARAM, 0.f, 1.f, 0.f, "phase2");
		configParam(PHASE3_PARAM, 0.f, 1.f, 0.f, "phase3");
		configParam(PW1_PARAM, 0.f, 1.f, 0.5f, "pw1");
		configParam(PW2_PARAM, 0.f, 1.f, 0.5f, "pw2");
		configParam(PW3_PARAM, 0.f, 1.f, 0.5f, "pw3");
		configInput(FREQ_INPUT, "freq input");
		configInput(RATE1_INPUT, "rate1 input");
		configInput(RATE2_INPUT, "rate2 input");
		configInput(RATE3_INPUT, "rate3 input");
		configInput(SHAPE1_INPUT, "shape1 input");
		configInput(SHAPE2_INPUT, "shape2 input");
		configInput(SHAPE3_INPUT, "shape3 input");
		configInput(AMT1_INPUT, "amt1 input");
		configInput(AMT2_INPUT, "amt2 input");
		configInput(AMT3_INPUT, "amt3 input");
		configInput(SYNC_INPUT, "sync input");
		configOutput(TRIG12_OUTPUT, "trig 12");
		configOutput(TRIG13_OUTPUT, "trig 13");
		configOutput(TRIG23_OUTPUT, "trig 23");
		configOutput(TRIG123_OUTPUT, "trig 123");
		configOutput(LFO1_OUTPUT, "lfo1");
		configOutput(LFO2_OUTPUT, "lfo2");
		configOutput(LFO3_OUTPUT, "lfo3");
		configOutput(DIFF12_OUTPUT, "diff12");
		configOutput(DIFF13_OUTPUT, "diff13");
		configOutput(DIFF23_OUTPUT, "diff23");
		configOutput(DIFF123_OUTPUT, "diff123");
	}
	void CrossSeq3_process_init();
	float sampleTime = 1.0f / 44100.0f;

	void process(const ProcessArgs& args) override {
		CrossSeq3_setFreq(processor, params[FREQ_PARAM].value, inputs[FREQ_INPUT].value);
		CrossSeq3_setSync(processor, inputs[SYNC_INPUT].value);
		CrossSeq3_setRate1(processor, params[RATE1_PARAM].value,   ( inputs[RATE1_INPUT].getVoltage() / 10.0f) * params[CVRT1_PARAM].value);
		CrossSeq3_setRate2(processor, params[RATE2_PARAM].value,   ( inputs[RATE2_INPUT].getVoltage() / 10.0f) * params[CVRT2_PARAM].value);
		CrossSeq3_setRate3(processor, params[RATE3_PARAM].value,   ( inputs[RATE3_INPUT].getVoltage() / 10.0f) * params[CVRT3_PARAM].value);
		CrossSeq3_setAmt1(processor, params[AMT1_PARAM].value,     (  inputs[AMT1_INPUT].getVoltage() / 10.0f) *  params[CVAM1_PARAM].value);
		CrossSeq3_setAmt2(processor, params[AMT2_PARAM].value,     (  inputs[AMT2_INPUT].getVoltage() / 10.0f) *  params[CVAM2_PARAM].value);
		CrossSeq3_setAmt3(processor, params[AMT3_PARAM].value,     (  inputs[AMT3_INPUT].getVoltage() / 10.0f) *  params[CVAM3_PARAM].value);
		CrossSeq3_setShape1(processor, params[SHAPE1_PARAM].value, (inputs[SHAPE1_INPUT].getVoltage() / 10.0f) *  params[CVSH1_PARAM].value);
		CrossSeq3_setShape2(processor, params[SHAPE2_PARAM].value, (inputs[SHAPE2_INPUT].getVoltage() / 10.0f) *  params[CVSH2_PARAM].value);
		CrossSeq3_setShape3(processor, params[SHAPE3_PARAM].value, (inputs[SHAPE3_INPUT].getVoltage() / 10.0f) *  params[CVSH3_PARAM].value);
		CrossSeq3_setPw1(processor, params[PW1_PARAM].value);
		CrossSeq3_setPw2(processor, params[PW2_PARAM].value);
		CrossSeq3_setPw3(processor, params[PW3_PARAM].value);
		CrossSeq3_setPhase1(processor, params[PHASE1_PARAM].value);
		CrossSeq3_setPhase2(processor, params[PHASE2_PARAM].value);
		CrossSeq3_setPhase3(processor, params[PHASE3_PARAM].value);
		CrossSeq3_process(processor,sampleTime);
		float trig12 = CrossSeq3_process_ret_0(processor);
		float trig13 = CrossSeq3_process_ret_1(processor);
		float trig23 = CrossSeq3_process_ret_2(processor);
		float trig123 = CrossSeq3_process_ret_3(processor);
		float lfo1 = CrossSeq3_process_ret_4(processor);
		float lfo2 = CrossSeq3_process_ret_5(processor);
		float lfo3 = CrossSeq3_process_ret_6(processor);
		float diff12 = CrossSeq3_process_ret_7(processor);
		float diff13 = CrossSeq3_process_ret_8(processor);
		float diff23 = CrossSeq3_process_ret_9(processor);
		float diff123 = CrossSeq3_process_ret_10(processor);
		outputs[TRIG12_OUTPUT].setVoltage (10.f * trig12);
		outputs[TRIG13_OUTPUT].setVoltage (10.f * trig13);
		outputs[TRIG23_OUTPUT].setVoltage (10.f * trig23);
		outputs[TRIG123_OUTPUT].setVoltage(10.f * trig123);
		outputs[LFO1_OUTPUT].setVoltage(5.f * lfo1);
		outputs[LFO2_OUTPUT].setVoltage(5.f * lfo2);
		outputs[LFO3_OUTPUT].setVoltage(5.f * lfo3);
		outputs[DIFF12_OUTPUT].setVoltage(5.f * diff12);
		outputs[DIFF13_OUTPUT].setVoltage(5.f * diff13);
		outputs[DIFF23_OUTPUT].setVoltage(5.f * diff23);
		outputs[DIFF123_OUTPUT].setVoltage(5.f * diff123);
	}

	void paramsFromJson(json_t* rootJ) override {
		params[FREQ_PARAM].setValue(1.f);
		params[RATE1_PARAM].setValue(1.f);
		params[RATE2_PARAM].setValue(1.f);
		params[RATE3_PARAM].setValue(1.f);
		params[AMT1_PARAM].setValue(1.f);
		params[AMT2_PARAM].setValue(1.f);
		params[AMT3_PARAM].setValue(1.f);
		params[SHAPE1_PARAM].setValue(0.f);
		params[SHAPE2_PARAM].setValue(1.f);
		params[SHAPE3_PARAM].setValue(1.f);
		params[PW1_PARAM].setValue(0.5f);
		params[PW2_PARAM].setValue(0.5f);
		params[PW3_PARAM].setValue(0.5f);
		params[PHASE1_PARAM].setValue(0.f);
		params[PHASE2_PARAM].setValue(0.f);
		params[PHASE3_PARAM].setValue(0.f);
		params[	CVRT1_PARAM].setValue(0.f);
		params[	CVRT2_PARAM].setValue(0.f);
		params[	CVRT3_PARAM].setValue(0.f);
		params[	CVAM1_PARAM].setValue(0.f);
		params[	CVAM2_PARAM].setValue(0.f);
		params[	CVAM3_PARAM].setValue(0.f);
		params[	CVSH1_PARAM].setValue(0.f);
		params[	CVSH2_PARAM].setValue(0.f);
		params[	CVSH3_PARAM].setValue(0.f);

		Module::paramsFromJson(rootJ);
	}

	void onSampleRateChange(const SampleRateChangeEvent& e) override {
    sampleTime = 1.0f / e.sampleRate;
	}
};





struct CrossSeq3Widget : ModuleWidget {
	CrossSeq3Widget(CrossSeq3* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/cross3New.svg")));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParam<RoundSmallBlackKnob>   (Vec(98, 234), module, CrossSeq3::FREQ_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(37 , 39), module, CrossSeq3::RATE1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(132, 39), module, CrossSeq3::RATE2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(227, 39), module, CrossSeq3::RATE3_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(37 , 78), module, CrossSeq3::AMT1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(132, 78), module, CrossSeq3::AMT2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(227, 78), module, CrossSeq3::AMT3_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(37 , 118), module, CrossSeq3::SHAPE1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(132, 118), module, CrossSeq3::SHAPE2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(227, 118), module, CrossSeq3::SHAPE3_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(37,  150), module, CrossSeq3::PHASE1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(132, 150), module, CrossSeq3::PHASE2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(227, 150), module, CrossSeq3::PHASE3_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(37,  188), module, CrossSeq3::PW1_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(132, 188), module, CrossSeq3::PW2_PARAM));
		addParam(createParam<RoundSmallBlackKnob>   (Vec(227, 188), module, CrossSeq3::PW3_PARAM));

		addParam(createParam<BefacoTinyKnob>   (Vec(104, 39)  - Vec(1 , 0), module, CrossSeq3::CVRT1_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(198, 39)  - Vec(1 , 0), module, CrossSeq3::CVRT2_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(293, 39)  - Vec(0 , 0), module, CrossSeq3::CVRT3_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(104, 80)  - Vec(1 , 0), module, CrossSeq3::CVAM1_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(198, 80)  - Vec(1 , 0), module, CrossSeq3::CVAM2_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(293, 80)  - Vec(0 , 0), module, CrossSeq3::CVAM3_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(104, 118) - Vec(1 , 0), module, CrossSeq3::CVSH1_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(198, 118) - Vec(1 , 0), module, CrossSeq3::CVSH2_PARAM));
		addParam(createParam<BefacoTinyKnob>   (Vec(293, 118) - Vec(0 , 0), module, CrossSeq3::CVSH3_PARAM));

		addInput(createInput<CL1362Port>(  Vec(24, 230 ), module, CrossSeq3::FREQ_INPUT));
		addInput(createInput<CL1362Port>(  Vec(24, 271  ), module, CrossSeq3::SYNC_INPUT));
		addInput(createInput<CL1362Port>(  Vec(64 , 36   ), module, CrossSeq3::RATE1_INPUT));
		addInput(createInput<CL1362Port>(  Vec(160, 36   ), module, CrossSeq3::RATE2_INPUT));
		addInput(createInput<CL1362Port>(  Vec(255, 36   ), module, CrossSeq3::RATE3_INPUT));
		addInput(createInput<CL1362Port>(  Vec(64 , 74   ), module, CrossSeq3::AMT1_INPUT));
		addInput(createInput<CL1362Port>(  Vec(160, 74   ), module, CrossSeq3::AMT2_INPUT));
		addInput(createInput<CL1362Port>(  Vec(255, 74   ), module, CrossSeq3::AMT3_INPUT));
		addInput(createInput<CL1362Port>(  Vec(64 , 112  ), module, CrossSeq3::SHAPE1_INPUT));
		addInput(createInput<CL1362Port>(  Vec(160, 112  ), module, CrossSeq3::SHAPE2_INPUT));
		addInput(createInput<CL1362Port>(  Vec(255, 112  ), module, CrossSeq3::SHAPE3_INPUT));

		addOutput(createOutput<CL1362Port>(Vec(25,    325), module, CrossSeq3::TRIG12_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(65,    325), module, CrossSeq3::TRIG13_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(106,   325), module, CrossSeq3::TRIG23_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(147,   325), module, CrossSeq3::TRIG123_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(188,   325), module, CrossSeq3::LFO1_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(229,   325), module, CrossSeq3::LFO2_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(270,   325), module, CrossSeq3::LFO3_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(147,   274), module, CrossSeq3::DIFF12_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(188,   274), module, CrossSeq3::DIFF13_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(229,   274), module, CrossSeq3::DIFF23_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(270,   274), module, CrossSeq3::DIFF123_OUTPUT));

	}
};


Model* modelCrossSeq3 = createModel<CrossSeq3, CrossSeq3Widget>("CrossSeq3");
