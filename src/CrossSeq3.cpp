
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#include "CrossSeq3.h"

void CrossSeq3__ctx_type_0_init(CrossSeq3__ctx_type_0 &_output_){
   CrossSeq3__ctx_type_0 _ctx;
   _ctx.x4 = 0.0f;
   _ctx.x3 = 0.0f;
   _ctx.x2 = 0.0f;
   _output_ = _ctx;
   return ;
}

float CrossSeq3_soft(CrossSeq3__ctx_type_0 &_ctx, float x1){
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

void CrossSeq3__ctx_type_5_init(CrossSeq3__ctx_type_5 &_output_){
   CrossSeq3__ctx_type_5 _ctx;
   _ctx.rate = 0.0f;
   _ctx.phase = 0.0f;
   _ctx.o = 0.0f;
   CrossSeq3__ctx_type_0_init(_ctx._inst823);
   CrossSeq3__ctx_type_1_init(_ctx._inst578);
   CrossSeq3__ctx_type_3_init(_ctx._inst3b5);
   CrossSeq3__ctx_type_2_init(_ctx._inst1b9);
   _output_ = _ctx;
   return ;
}

float CrossSeq3_lfo_interp(CrossSeq3__ctx_type_5 &_ctx, float cv, float shape, float amt, float pw, float reset, float sampleTime){
   if(CrossSeq3_change(_ctx._inst1b9,cv)){
      _ctx.rate = (16.f * cv * sampleTime);
   }
   uint8_t update;
   update = CrossSeq3_each(_ctx._inst3b5,8);
   if(update){
      _ctx.phase = (_ctx.phase + _ctx.rate);
   }
   if(_ctx.phase > 2.f){
      _ctx.phase = (-2.f + _ctx.phase);
   }
   uint8_t breset;
   breset = (reset > 0.0f);
   if(CrossSeq3_edge(_ctx._inst578,breset)){
      _ctx.phase = 0.0f;
   }
   float tmp;
   tmp = (-1.f + _ctx.phase);
   if(update){
      if(shape < 1.f){
         _ctx.o = (amt * CrossSeq3_lerp(sinf((3.14159265359f * _ctx.phase)),(-1.f + (2.f * fabsf(tmp))),fmodf(shape,1.f)));
      }
      else
      {
         if(shape < 2.f){
            _ctx.o = (amt * CrossSeq3_lerp((-1.f + (2.f * fabsf(tmp))),tmp,fmodf(shape,1.f)));
         }
         else
         {
            if(shape < 3.f){
               _ctx.o = (amt * CrossSeq3_lerp(tmp,((tmp > pw)?1.f:-1.f),fmodf(shape,1.f)));
            }
            else
            {
               _ctx.o = (amt * ((tmp > pw)?1.f:-1.f));
            }
         }
      }
   }
   return CrossSeq3_soft(_ctx._inst823,_ctx.o);
}

float CrossSeq3_cross_detect(CrossSeq3__ctx_type_6 &_ctx, float a, float b){
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
   float trig;
   if(CrossSeq3_change(_ctx._inst1b9,sign)){
      trig = 1.f;
   }
   else
   {
      trig = 0.0f;
   }
   return trig;
}

float CrossSeq3_cross_detect3(float a, float b, float c){
   float diff12;
   diff12 = (a + (- b));
   float diff13;
   diff13 = (a + (- c));
   float diff23;
   diff23 = (b + (- c));
   float adiff;
   adiff = (fabsf(diff12) + fabsf(diff13) + fabsf(diff23));
   float ret;
   if(adiff < 0.1f){
      ret = 1.f;
   }
   else
   {
      ret = 0.0f;
   }
   return ret;
}

void CrossSeq3__ctx_type_8_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8 _ctx;
   _ctx.sync = 0.0f;
   _ctx.shape3 = 0.0f;
   _ctx.shape2 = 0.0f;
   _ctx.shape1 = 0.0f;
   _ctx.rate3 = 0.0f;
   _ctx.rate2 = 0.0f;
   _ctx.rate1 = 0.0f;
   _ctx.pw3 = 0.0f;
   _ctx.pw2 = 0.0f;
   _ctx.pw1 = 0.0f;
   _ctx.process_ret_9 = 0.0f;
   _ctx.process_ret_8 = 0.0f;
   _ctx.process_ret_7 = 0.0f;
   _ctx.process_ret_6 = 0.0f;
   _ctx.process_ret_5 = 0.0f;
   _ctx.process_ret_4 = 0.0f;
   _ctx.process_ret_3 = 0.0f;
   _ctx.process_ret_2 = 0.0f;
   _ctx.process_ret_10 = 0.0f;
   _ctx.process_ret_1 = 0.0f;
   _ctx.process_ret_0 = 0.0f;
   _ctx.phase3 = 0.0f;
   _ctx.phase2 = 0.0f;
   _ctx.phase1 = 0.0f;
   _ctx.freqK = 0.0f;
   _ctx.freq = 0.0f;
   _ctx.amt3 = 0.0f;
   _ctx.amt2 = 0.0f;
   _ctx.amt1 = 0.0f;
   CrossSeq3__ctx_type_6_init(_ctx._inst6c3);
   CrossSeq3__ctx_type_6_init(_ctx._inst5c3);
   CrossSeq3__ctx_type_6_init(_ctx._inst4c3);
   CrossSeq3__ctx_type_5_init(_ctx._inst32f);
   CrossSeq3__ctx_type_5_init(_ctx._inst22f);
   CrossSeq3__ctx_type_5_init(_ctx._inst12f);
   _output_ = _ctx;
   return ;
}

void CrossSeq3_process(CrossSeq3__ctx_type_8 &_ctx, float sampleTime){
   float lfo1;
   lfo1 = CrossSeq3_lfo_interp(_ctx._inst12f,(_ctx.freq * _ctx.rate1),_ctx.shape1,_ctx.amt1,_ctx.pw1,_ctx.sync,sampleTime);
   float lfo2;
   lfo2 = CrossSeq3_lfo_interp(_ctx._inst22f,(_ctx.freq * _ctx.rate2),_ctx.shape2,_ctx.amt2,_ctx.pw2,_ctx.sync,sampleTime);
   float lfo3;
   lfo3 = CrossSeq3_lfo_interp(_ctx._inst32f,(_ctx.freq * _ctx.rate3),_ctx.shape3,_ctx.amt3,_ctx.pw3,_ctx.sync,sampleTime);
   float tr12;
   tr12 = CrossSeq3_cross_detect(_ctx._inst4c3,lfo1,lfo2);
   float tr13;
   tr13 = CrossSeq3_cross_detect(_ctx._inst5c3,lfo1,lfo3);
   float tr23;
   tr23 = CrossSeq3_cross_detect(_ctx._inst6c3,lfo2,lfo3);
   float tr123;
   tr123 = CrossSeq3_cross_detect3(lfo1,lfo2,lfo3);
   float diff12;
   diff12 = ((lfo1 + (- lfo2)) / (0.01f + _ctx.amt1 + _ctx.amt2));
   float diff13;
   diff13 = ((lfo1 + (- lfo3)) / (0.01f + _ctx.amt1 + _ctx.amt3));
   float diff23;
   diff23 = ((lfo2 + (- lfo3)) / (0.01f + _ctx.amt2 + _ctx.amt3));
   float diff123;
   diff123 = ((lfo1 + (- lfo2) + (- lfo3)) / (0.01f + _ctx.amt1 + _ctx.amt2 + _ctx.amt3));
   lfo1 = (lfo1 / _ctx.amt1);
   lfo2 = (lfo2 / _ctx.amt2);
   lfo3 = (lfo1 / _ctx.amt3);
   _ctx.process_ret_0 = tr12;
   _ctx.process_ret_1 = tr13;
   _ctx.process_ret_2 = tr23;
   _ctx.process_ret_3 = tr123;
   _ctx.process_ret_4 = lfo1;
   _ctx.process_ret_5 = lfo2;
   _ctx.process_ret_6 = lfo3;
   _ctx.process_ret_7 = diff12;
   _ctx.process_ret_8 = diff13;
   _ctx.process_ret_9 = diff23;
   _ctx.process_ret_10 = diff123;
   return ;
}

void CrossSeq3_default(CrossSeq3__ctx_type_8 &_ctx){
   _ctx.freqK = 1.f;
   _ctx.sync = 0.0f;
   _ctx.rate1 = 1.f;
   _ctx.rate2 = 1.f;
   _ctx.rate3 = 1.f;
   _ctx.amt1 = 1.f;
   _ctx.amt2 = 1.f;
   _ctx.amt3 = 1.f;
   _ctx.shape1 = 0.0f;
   _ctx.shape2 = 1.f;
   _ctx.shape3 = 1.f;
   _ctx.phase1 = 0.0f;
   _ctx.phase2 = 0.0f;
   _ctx.phase3 = 0.0f;
   _ctx.pw1 = 0.5f;
   _ctx.pw2 = 0.5f;
   _ctx.pw3 = 0.5f;
}


