#include "plugin.hpp"
#include "TrigLogic.h"


struct TrigLogic : Module {

	enum ParamId {
		TYPE1_SWITCH,
		TYPE2_SWITCH,
		UP1_SWITCH,
		UP2_SWITCH,
		OP_SWITCH,
		INV_SWITCH,
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
		configSwitch(TYPE1_SWITCH, 0.0f, 1.0f, 1.0f, "dir/sign1", {"dir", "sign"});
		configSwitch(TYPE2_SWITCH, 0.0f, 1.0f, 1.0f, "dir/sign2", {"dir", "sign"});
		configSwitch(UP1_SWITCH, 0.0f, 1.0f, 1.0f, "up/down1", {"up", "down"});
		configSwitch(UP2_SWITCH, 0.0f, 1.0f, 1.0f, "up/down2", {"up", "down"});
		configSwitch(OP_SWITCH, 0.0f, 1.0f, 1.0f, "and/or", {"and", "or"});
		configSwitch(INV_SWITCH, 0.0f, 1.0f, 1.0f, "invert", {"not_invert", "invert"});
		configInput(TRIG_INPUT, "trig");
		configInput(LFO1_INPUT, "lfo1");
		configInput(LFO2_INPUT, "lof2");
		configOutput(TRIG_OUTPUT, "parsed trig");
		configOutput(INVTRIG_OUTPUT, "inverted trig");

	}
	TrigLogic_process_init();

	void process(const ProcessArgs& args) override {
		TrigLogic_setType1(processor, params[TYPE1_SWITCH].value);
		TrigLogic_setType1(processor, params[TYPE2_SWITCH].value);
		TrigLogic_setS1(processor, params[UP1_SWITCH].value);
		TrigLogic_setS2(processor, params[UP2_SWITCH].value);
		TrigLogic_setAndOr(processor, params[OP_SWITCH].value);
		TrigLogic_setInv(processor, params[INV_SWITCH].value);
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
		addParam(createParamCentered<BefacoSwitch>(Vec(19, 155), module, TrigLogic::UP1_SWITCH));
		addParam(createParamCentered<BefacoSwitch>(Vec(98, 155), module, TrigLogic::UP2_SWITCH));
		addParam(createParamCentered<BefacoSwitch>(Vec(59, 195), module, TrigLogic::OP_SWITCH));
		//addParam(createParamCentered<BefacoSwitch>(Vec(23, 332), module, TrigLogic::INV_SWITCH));
		addOutput(createOutput<CL1362Port>(Vec(80, 316), module, TrigLogic::TRIG_OUTPUT));
		addOutput(createOutput<CL1362Port>(Vec(8, 316), module, TrigLogic::INVTRIG_OUTPUT));

	}
};


Model* modelTrigLogic = createModel<TrigLogic, TrigLogicWidget>("TrigLogic");