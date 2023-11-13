
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "CrossSeq2.h"

void CrossSeq2__ctx_type_0_init(CrossSeq2__ctx_type_0 &_output_){
   CrossSeq2__ctx_type_0 _ctx;
   _ctx.x4 = 0.0f;
   _ctx.x3 = 0.0f;
   _ctx.x2 = 0.0f;
   _output_ = _ctx;
   return ;
}

float CrossSeq2_soft(CrossSeq2__ctx_type_0 &_ctx, float x1){
   float o;
   o = (0.25f * (_ctx.x2 + _ctx.x3 + _ctx.x4 + x1));
   float _tmp_1_0;
   _tmp_1_0 = x1;
   float _tmp_1_1;
   _tmp_1_1 = _ctx.x2;
   float _tmp_1_2;
   _tmp_1_2 = _ctx.x3;
   _ctx.x2 = _tmp_1_0;
   _ctx.x3 = _tmp_1_1;
   _ctx.x4 = _tmp_1_2;
   return o;
}

void CrossSeq2__ctx_type_5_init(CrossSeq2__ctx_type_5 &_output_){
   CrossSeq2__ctx_type_5 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   _ctx.phOff = 0.0f;
   _ctx.o = 0.0f;
   CrossSeq2__ctx_type_2_init(_ctx._inst75d);
   CrossSeq2__ctx_type_3_init(_ctx._inst57b);
   CrossSeq2__ctx_type_1_init(_ctx._inst393);
   CrossSeq2__ctx_type_1_init(_ctx._inst193);
   CrossSeq2__ctx_type_0_init(_ctx._inst109);
   CrossSeq2_initPhase(_ctx);
   _output_ = _ctx;
   return ;
}

float CrossSeq2_lfo_interp(CrossSeq2__ctx_type_5 &_ctx, float cv, float shape, float amt, float pw, float reset, float phaseOff, float sampleTime){
   if(CrossSeq2_change(_ctx._inst193,phaseOff)){
      _ctx.phOff = phaseOff;
   }
   float updateRate;
   if(cv > 0.5f){
      updateRate = 8.f;
   }
   else
   {
      updateRate = 1.f;
   }
   if(CrossSeq2_change(_ctx._inst393,cv)){
      _ctx.rate = (2.f * cv * sampleTime * updateRate);
   }
   uint8_t update;
   update = CrossSeq2_each(_ctx._inst57b,float_to_int(updateRate));
   if(update){
      _ctx.phase = (_ctx.phase + _ctx.rate);
   }
   if(_ctx.phase > 2.f){
      _ctx.phase = (-2.f + _ctx.phase);
   }
   float ph;
   if((_ctx.phOff + _ctx.phase) > 2.f){
      ph = (-2.f + _ctx.phOff + _ctx.phase);
   }
   else
   {
      ph = (_ctx.phOff + _ctx.phase);
   }
   uint8_t breset;
   breset = (reset > 0.0f);
   if(CrossSeq2_edge(_ctx._inst75d,breset)){
      _ctx.phase = 1.f;
   }
   float saw;
   saw = (-1.f + ph);
   if(update){
      if(shape < 1.f){
         _ctx.o = (amt * CrossSeq2_lerp(sinf((3.14159265359f * (-0.5f + ph))),(-1.f * (-1.f + (2.f * fabsf(saw)))),fmodf(shape,1.f)));
      }
      else
      {
         if(shape < 2.f){
            _ctx.o = (amt * CrossSeq2_lerp((-1.f * (-1.f + (2.f * fabsf(saw)))),saw,fmodf(shape,1.f)));
         }
         else
         {
            if(shape < 3.f){
               _ctx.o = (amt * CrossSeq2_lerp(saw,((saw > pw)?1.f:-1.f),fmodf(shape,1.f)));
            }
            else
            {
               _ctx.o = (amt * ((saw > pw)?1.f:-1.f));
            }
         }
      }
   }
   return CrossSeq2_soft(_ctx._inst109,_ctx.o);
}

void CrossSeq2__ctx_type_6_init(CrossSeq2__ctx_type_6 &_output_){
   CrossSeq2__ctx_type_6 _ctx;
   _ctx.open = 0.0f;
   CrossSeq2__ctx_type_1_init(_ctx._inst193);
   _output_ = _ctx;
   return ;
}

float CrossSeq2_cross_detect(CrossSeq2__ctx_type_6 &_ctx, float a, float b, float st){
   _ctx.open = (_ctx.open + st);
   float diff;
   diff = (a + (- b));
   float sign;
   if(diff > 0.0f){
      sign = 1.f;
   }
   else
   {
      sign = 0.0f;
   }
   if(CrossSeq2_change(_ctx._inst193,sign)){
      _ctx.open = 0.0f;
   }
   float _if_4;
   if(_ctx.open > 0.001f){
      _if_4 = 0.0f;
   }
   else
   {
      _if_4 = 1.f;
   }
   return _if_4;
}

void CrossSeq2__ctx_type_7_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7 _ctx;
   _ctx.sync = 0.0f;
   _ctx.shape2 = 0.0f;
   _ctx.shape1 = 0.0f;
   _ctx.rate2 = 0.0f;
   _ctx.rate1 = 0.0f;
   _ctx.pw2 = 0.0f;
   _ctx.pw1 = 0.0f;
   _ctx.process_ret_3 = 0.0f;
   _ctx.process_ret_2 = 0.0f;
   _ctx.process_ret_1 = 0.0f;
   _ctx.process_ret_0 = 0.0f;
   _ctx.phaseOff2 = 0.0f;
   _ctx.phaseOff1 = 0.0f;
   _ctx.freq = 0.0f;
   _ctx.amt2 = 0.0f;
   _ctx.amt1 = 0.0f;
   CrossSeq2__ctx_type_6_init(_ctx._inst36b);
   CrossSeq2__ctx_type_5_init(_ctx._inst27f);
   CrossSeq2__ctx_type_5_init(_ctx._inst17f);
   CrossSeq2__ctx_type_5_init(_ctx._inst14c3);
   CrossSeq2_default(_ctx);
   _output_ = _ctx;
   return ;
}

void CrossSeq2_process(CrossSeq2__ctx_type_7 &_ctx, float sampleTime){
   float lfo1;
   lfo1 = CrossSeq2_lfo_interp(_ctx._inst17f,(_ctx.freq * _ctx.rate1),_ctx.shape1,_ctx.amt1,_ctx.pw1,_ctx.sync,_ctx.phaseOff1,sampleTime);
   float lfo2;
   lfo2 = CrossSeq2_lfo_interp(_ctx._inst27f,(_ctx.freq * _ctx.rate2),_ctx.shape2,_ctx.amt2,_ctx.pw2,_ctx.sync,_ctx.phaseOff2,sampleTime);
   float gate;
   gate = CrossSeq2_cross_detect(_ctx._inst36b,lfo1,lfo2,sampleTime);
   float trig;
   trig = gate;
   float diff;
   diff = (lfo1 + (- lfo2));
   _ctx.process_ret_0 = trig;
   _ctx.process_ret_1 = lfo1;
   _ctx.process_ret_2 = lfo2;
   _ctx.process_ret_3 = diff;
   return ;
}

void CrossSeq2_default(CrossSeq2__ctx_type_7 &_ctx){
   CrossSeq2_initPhase(_ctx._inst14c3);
   _ctx.freq = 1.f;
   _ctx.sync = 0.0f;
   _ctx.rate1 = 1.f;
   _ctx.rate2 = 1.f;
   _ctx.amt1 = 1.f;
   _ctx.amt2 = 1.f;
   _ctx.shape1 = 0.0f;
   _ctx.shape2 = 1.f;
   _ctx.phaseOff1 = 0.0f;
   _ctx.phaseOff2 = 0.0f;
   _ctx.pw1 = 0.5f;
   _ctx.pw2 = 0.5f;
}


