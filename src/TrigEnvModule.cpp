#include "plugin.hpp"
#include "TrigEnv.h"


struct TrigEnv : Module {

	enum ParamId {
		LEN_PARAM,	
		ATK_PARAM,
		DEC_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		TRIG_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		ENV_OUTPUT,
		OUTPUTS_LEN
	};
	TrigEnv_process_type processor;

	TrigEnv() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN);
		configParam(LEN_PARAM, 0.f, 10.f, 1.f, "gate lenght");
		configParam(ATK_PARAM, 0.f, 1.f, 0.1f, "attack");
		configParam(DEC_PARAM, 0.f, 1.f, 0.1f, "decay");
        configInput(TRIG_INPUT, "trigger input");

	}
	TrigEnv_process_init();

	void process(const ProcessArgs& args) override {
		TrigEnv_setGateLen(processor, params[LEN_PARAM].value);
		TrigEnv_setA(processor, inputs[ATK_PARAM].value);
		TrigEnv_setD(processor, params[DEC_PARAM].value);
        float trig = inputs[TRIG_INPUT].value;
		float env = TrigEnv_process(processor,trig,args.sampleTime);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[ENV_OUTPUT].setVoltage(10.f * env);
		
	}
};



struct TrigEnvWidget : ModuleWidget {
	TrigEnvWidget(TrigEnv* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/TrigEnv.svg")));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParam<Rogan1PSBlue>(Vec(13, 110), module, TrigEnv::LEN_PARAM));
		addParam(createParam<Rogan1PSBlue>(Vec(13, 166), module, TrigEnv::ATK_PARAM));
		addParam(createParam<Rogan1PSBlue>(Vec(13, 218), module, TrigEnv::DEC_PARAM));

		addInput(createInput<CL1362Port>(Vec(10, 63), module, TrigEnv::TRIG_INPUT));
        addOutput(createOutput<CL1362Port>(Vec(11, 322), module, TrigEnv::ENV_OUTPUT));

	}
};


Model* modelTrigEnv = createModel<TrigEnv, TrigEnvWidget>("TrigEnv");