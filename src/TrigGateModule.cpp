#include "plugin.hpp"
#include "TrigGate.h"


struct TrigGate : Module {

	enum ParamId {
		LEN1_PARAM,	
		LEN2_PARAM,	
		PARAMS_LEN
	};
	enum InputId {
		TRIG1_INPUT,
		TRIG2_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		GATE1_OUTPUT,
		GATE2_OUTPUT,
		OUTPUTS_LEN
	};
	TrigGate_process_type processor;

	TrigGate() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN);
		configParam(LEN1_PARAM, 0.f, 1.f, 0.1f, "gate1 lenght");
		configParam(LEN2_PARAM, 0.f, 1.f, 0.1f, "gate2 lenght");
        configInput(TRIG1_INPUT, "trigger1 input");
        configInput(TRIG2_INPUT, "trigger2 input");
	}
	void TrigGate_process_init();

	void process(const ProcessArgs& args) override {
		TrigGate_setGateLen1(processor, params[LEN1_PARAM].value);
		TrigGate_setGateLen2(processor, params[LEN2_PARAM].value);
		float trig1 = inputs[TRIG1_INPUT].value;
		float trig2 = inputs[TRIG2_INPUT].value;
		TrigGate_process(processor,trig1, trig2, args.sampleTime);
		float gate1 = TrigGate_process_ret_0(processor);
		float gate2 = TrigGate_process_ret_1(processor);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[GATE1_OUTPUT].setVoltage(10.f * gate1);
		outputs[GATE2_OUTPUT].setVoltage(10.f * gate2);
		
	}
};



struct TrigGateWidget : ModuleWidget {
	TrigGateWidget(TrigGate* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/TrigGate.svg")));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

        addInput(createInputCentered<CL1362Port>  (Vec(23, 74) , module, TrigGate::TRIG1_INPUT));
		addParam(createParamCentered<RoundSmallBlackKnob> (Vec(23, 110), module, TrigGate::LEN1_PARAM));
        addOutput(createOutputCentered<CL1362Port>(Vec(23, 158), module, TrigGate::GATE1_OUTPUT));
        addInput(createInputCentered<CL1362Port>  (Vec(23, 251), module, TrigGate::TRIG2_INPUT));
        addParam(createParamCentered<RoundSmallBlackKnob> (Vec(23, 284), module, TrigGate::LEN2_PARAM));
        addOutput(createOutputCentered<CL1362Port>(Vec(23, 330), module, TrigGate::GATE2_OUTPUT));

	}
};


Model* modelTrigGate = createModel<TrigGate, TrigGateWidget>("TrigGate");
