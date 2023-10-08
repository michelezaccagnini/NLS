#include "plugin.hpp"
#include "TrigLogic.h"


struct TrigLogic : Module {

	enum ParamId {
		TYPE1_SWITCH,
		TYPE2_SWITCH,
		SIGN1_PARAM,
		SIGN2_PARAM,
		OP_SWITCH,
		PARAMS_LEN
	};
	enum InputId {
		TRIG_INPUT,
		LFO1_INPUT,
		LFO2_INPUT,	
		INPUTS_LEN
	};
	enum OutputId {
		TRIG_OUTPUT,
		INVTRIG_OUTPUT,
		OUTPUTS_LEN
	};
	TrigLogic_process_type processor;

	TrigLogic() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN);
		configSwitch(TYPE1_SWITCH, 0.0f, 1.0f, 1.0f, "dir/sign1", { "sign", "dir",});
		configSwitch(TYPE2_SWITCH, 0.0f, 1.0f, 1.0f, "dir/sign2", {"sign","dir"});
		configParam(SIGN1_PARAM, -1, 1, 0, "up/zero/down");
		paramQuantities[SIGN1_PARAM]->snapEnabled = true;
		configParam(SIGN2_PARAM, -1, 1, 0, "up/zero/down");
		paramQuantities[SIGN2_PARAM]->snapEnabled = true;
		configSwitch(OP_SWITCH, 0.0f, 1.0f, 0.0f, "and/or", {"or", "and"});
		configInput(TRIG_INPUT, "trig");
		configInput(LFO1_INPUT, "lfo1");
		configInput(LFO2_INPUT, "lof2");
		configOutput(TRIG_OUTPUT, "parsed trig");
		configOutput(INVTRIG_OUTPUT, "inverted trig");

	}
	void TrigLogic_process_init();

	void process(const ProcessArgs& args) override {
		TrigLogic_setType1(processor, params[TYPE1_SWITCH].value);
		TrigLogic_setType2(processor, params[TYPE2_SWITCH].value);
		TrigLogic_setS1(processor, params[SIGN1_PARAM].value);
		TrigLogic_setS2(processor, params[SIGN2_PARAM].value);
		TrigLogic_setAndOr(processor, params[OP_SWITCH].value);
        float trig = inputs[TRIG_INPUT].value;
        float lfo1 = inputs[LFO1_INPUT].value;
        float lfo2 = inputs[LFO2_INPUT].value;
		TrigLogic_process(processor,trig,lfo1,lfo2);
		float tr = TrigLogic_process_ret_0(processor);
		float invtr = TrigLogic_process_ret_1(processor);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[TRIG_OUTPUT].setVoltage(10.f * tr);
		outputs[INVTRIG_OUTPUT].setVoltage(10.f * invtr);
		
	}
};



struct TrigLogicWidget : ModuleWidget {
	TrigLogicWidget(TrigLogic* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/TrigLogic.svg")));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addInput(createInput<CL1362Port>(Vec(41, 54), module, TrigLogic::TRIG_INPUT));
		addInput(createInput<CL1362Port>(Vec(3,  54), module, TrigLogic::LFO1_INPUT));
		addInput(createInput<CL1362Port>(Vec(77, 54), module, TrigLogic::LFO2_INPUT));
		addParam(createParamCentered<BefacoSwitch>(Vec(19, 112), module, TrigLogic::TYPE1_SWITCH));
		addParam(createParamCentered<BefacoSwitch>(Vec(98, 112), module, TrigLogic::TYPE2_SWITCH));
		addParam(createParamCentered<BefacoTinyKnob>(Vec(19, 155), module, TrigLogic::SIGN1_PARAM));
		addParam(createParamCentered<BefacoTinyKnob>(Vec(98, 155), module, TrigLogic::SIGN2_PARAM));
		addParam(createParamCentered<BefacoSwitch>(Vec(59, 195), module, TrigLogic::OP_SWITCH));
		//addParam(createParamCentered<BefacoSwitch>(Vec(23, 332), module, TrigLogic::INV_SWITCH));
		addOutput(createOutput<CL1362Port>(Vec(80, 316), module, TrigLogic::TRIG_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(8, 316), module, TrigLogic::INVTRIG_OUTPUT));

	}
};


Model* modelTrigLogic = createModel<TrigLogic, TrigLogicWidget>("TrigLogic");
