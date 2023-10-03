# NonlinearSequencer_VCV
VCV modules for NLS

## General description
Nonlinear Sequncer is a collection of objects to generate triggers and CVs based on nonlinear functions, initially developed in Cycling74 Max8 and partially implemented in VCV.
In the current VCV version two main modules are present: CrossSeq2, CrossSeq3, TrigGate and TrigLogic. 
- XSeq2 :  generates triggers at the intersection of two LFOs of variable shape, amplitude, rate, phase and duty cycle (rectangular shapes)
In XSeq2 only one set of triggers is output as well as the LFO curves and the difference between the curves (which will be 0 when a trigger is generated).
- XSeq3 is an expanded version of XSeq2 that detects intersection of 3 LFOs producing 4 sets of triggers (1-2, 1-3, 2-3, 1-2-3), 4 differences and 3 LFOs.
In both modules there is a master frequency knob and input.
- TrigGate: Turns triggers into gate of variable lengths.
- TrigLogic: parses triggers based on two signals (usually LFOs) letting through triggers according to logic tests on the signals


## CONCEPT
The concept of NLS is borne of the idea of harnessing the generating variables of a sequencer in real time and mapping them at will, integrating rhythmic and sound generation at their core.
XSeq2 and XSeq3 are capable of producing multiple CVs aside from the triggers and each of these CVs will be fucntionally connected with, and organic to, the genartion of patterns. In particular, the difference CV is a sort of predictive envelope that inevitably reaches 0 when the trigger happens.


### XSeq2 - XSeq3: Inputs & Params
![XSeq2](https://github.com/michelezaccagnini/NLS/blob/main/Images/cross2New.jpg)
![XSeq3]
(https://github.com/michelezaccagnini/NLS/blob/main/Images/cross3New.jpg)
Amt, shape and rate params are added to inputs
2x:
- sync: LFOs phase reset
- frequency: overall frequency of LFOs
- rate: rate for LFOs
- amt: amplitude of LFOs
- shape: LFO waveform (interpolated)
- phase: phase of LFOs
- pw: duty cycle for triangle and rectangle wave

### XSeq2 - XSeq3: Outputs
- triggers: LFO intersections
- lfos
- differences: running differences of LFOs

### TrigLogic : Inputs/Output
![TrigLogic]
(https://github.com/michelezaccagnini/NLS/blob/main/Images/TrigLogic.jpg)
- in : signal 1
- in : signal 2
- in : trigger
- out : parsed trigger
- out : inverted-logic trigger

### TrigLogic : Switches
- dir/sign : check for either direction of the signal or sign
- up/down : check whether the direction is up/down or sign is +/-
- and/or : logic pairing of the two tests

### TrigGate (pair)
![TrigGate]
(https://github.com/michelezaccagnini/NLS/blob/main/Images/TrigGate.jpg)
- in : trigger
- knob : gate length (seconds)
- out : gate


