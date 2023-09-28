#include "plugin.hpp"
#include "CrossSeq2v.h"


struct CrossSeq2 : Module {
	enum ParamId {
		PITCH_PARAM,
		PARAMS_LEN
	};
	enum InputId {
		PITCH_INPUT,
		INPUTS_LEN
	};
	enum OutputId {
		SINE_OUTPUT,
		OUTPUTS_LEN
	};
	enum LightId {
		BLINK_LIGHT,
		LIGHTS_LEN
	};
	float phase = 0.f;
	float blinkPhase = 0.f;
	CrossSeq2_process_type processor;

	CrossSeq2() {
		config(PARAMS_LEN, INPUTS_LEN, OUTPUTS_LEN, LIGHTS_LEN);
		configParam(PITCH_PARAM, 0.f, 1.f, 0.f, "");
		configInput(PITCH_INPUT, "");
		configOutput(SINE_OUTPUT, "");
	}

	void process(const ProcessArgs& args) override {
		// Compute the frequency from the pitch parameter and input
		float pitch = params[PITCH_PARAM].getValue();
		pitch += inputs[PITCH_INPUT].getVoltage();
		// The default frequency is C4 = 261.6256f
		float freq = dsp::FREQ_C4 * std::pow(2.f, pitch);

		// Accumulate the phase
		phase += freq * args.sampleTime;
		if (phase >= 1.f)
			phase -= 1.f;

		// Compute the sine output
		float sine = CrossSeq2_process(processor,phase);
		// Audio signals are typically +/-5V
		// https://vcvrack.com/manual/VoltageStandards
		outputs[SINE_OUTPUT].setVoltage(5.f * sine);

		// Blink light at 1Hz
		blinkPhase += args.sampleTime;
		if (blinkPhase >= 1.f)
			blinkPhase -= 1.f;
		lights[BLINK_LIGHT].setBrightness(blinkPhase < 0.5f ? 1.f : 0.f);
	
	}
};


struct CrossSeq2Widget : ModuleWidget {
	CrossSeq2Widget(CrossSeq2* module) {
		setModule(module);
		setPanel(createPanel(asset::plugin(pluginInstance, "res/MyModule.svg")));

		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
		addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
		addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

		addParam(createParamCentered<RoundBlackKnob>(mm2px(Vec(15.24, 46.063)), module, CrossSeq2::PITCH_PARAM));

		addInput(createInputCentered<PJ301MPort>(mm2px(Vec(15.24, 77.478)), module, CrossSeq2::PITCH_INPUT));

		addOutput(createOutputCentered<PJ301MPort>(mm2px(Vec(15.24, 108.713)), module, CrossSeq2::SINE_OUTPUT));

		addChild(createLightCentered<MediumLight<RedLight>>(mm2px(Vec(15.24, 25.81)), module, CrossSeq2::BLINK_LIGHT));
	}
};


Model* modelCrossSeq2 = createModel<CrossSeq2, CrossSeq2Widget>("CrossSeq2");