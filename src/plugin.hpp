#pragma once
#include <rack.hpp>


using namespace rack;

// Declare the Plugin, defined in plugin.cpp
extern Plugin* pluginInstance;
extern Model* modelCrossSeq2;
extern Model* modelTrigGate;
extern Model* modelCrossSeq3;
extern Model* modelTrigLogic;
extern Model *modelGraviHarm;
// Declare each Model, defined in each module source file
// extern Model* modelMyModule;
