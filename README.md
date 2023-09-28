# NonlinearSequencer_VCV
VCV modules for NLS

## General description
Nonlinear Sequncer is a collection of objects to generate triggers and CVs based on nonlinear functions, initially developed in Cycling74 Max8 and partially implemented in VCV.
In the current VCV version two main modules are present: CrossSeq2, CrossSeq3, TrigEnv and TrigLogic. 
- CrossSeq2 :  generates triggers at the intersection of two LFOs of variable shape, amplitude, rate, phase and duty cycle (rectangular shapes)
In cross_seq2 only one set of triggers is output as well as the LFO curves and the difference between the curves (which will be 0 when a trigger is generated).
- CrossSeq3 is an expanded version of CrossSeq2 that detects intersection of 3 LFOs producing 4 sets of triggers (1-2, 1-3, 2-3, 1-2-3), 4 differences, 3 LFOs.
In both modules there is a master frequency knob and input.
- TrigEnv: generates AD envelopes based on triggers with variable lengths (converting triggers to gates)
- TrigLogic: parses triggers based on two LFOs letting through triggers according to logic tests on the two LFOs


## CONCEPT
The concept of NLS is borne of the idea of harnessing the generating variables of a sequencer in real time and mapping them at will, integrating rhythmic and sound generation at their core.
Cross_seq2 and 3 are capable of producing multiple CVs aside from the triggers and each of these CVs will be fucntionally connected with them. In particular, the difference CV is a sort of predictive envelope that inevitably reaches 0 when the trigger happens.


### CrossSeq2 LFO Inputs & Params
Amt, shape and rate params are added to inputs
2x:
- rate: rate for LFOs (2)
- amt: amplitude of LFOs
- shape: LFO waveform
- phase: phase of LFOs
- pw: duty cycle for triangle and rectangle wave



### CrossSeq2 Outputs
- trig: trigger (LFO intersection)
- lfo1
- lfo2
- diff: running difference of LFOs

### CrossSeq3 Inputs & Params
Amt, shape and rate params are added to inputs
3x:
- rate: rate for LFO
- amt: amplitude of LFOs
- shape: LFO waveform
- phase: phase of LFOs
- pw: duty cycle for triangle and rectangle wave
- sync: reset all phases

### CrossSeq3 General Inputs & Params
- freq: master LFO frequency
- sync: reset all phases

### CrossSeq3 Outputs
- trig: trigger (LFO intersection)
- lfo1
- lfo2
- lfo2
- diff12:  running difference of LFO 1 - 2
- diff13:  running difference of LFO 1 - 3 
- diff23:  running difference of LFO 2 - 3
- diff123: running difference of LFO 1 - 2 - 3