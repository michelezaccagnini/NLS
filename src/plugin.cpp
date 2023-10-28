#include "plugin.hpp"


Plugin* pluginInstance;


void init(Plugin* p) {
	pluginInstance = p;

	// Add modules here
	 p->addModel(modelCrossSeq2);
	 p->addModel(modelTrigGate);
	 p->addModel(modelCrossSeq3);
	 p->addModel(modelTrigLogic);
	 p->addModel(modelGraviHarm);

	// Any other plugin initialization may go here.
	// As an alternative, consider lazy-loading assets and lookup tables when your module is created to reduce startup times of Rack.
}
