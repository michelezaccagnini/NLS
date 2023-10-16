
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef CROSSSEQ2_H
#define CROSSSEQ2_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "CrossSeq2.tables.h"

typedef struct _tuple___real_real_real_real__ {
   float field_0;
   float field_1;
   float field_2;
   float field_3;
} _tuple___real_real_real_real__;

typedef struct CrossSeq2__ctx_type_0 {
   float x4;
   float x3;
   float x2;
} CrossSeq2__ctx_type_0;

typedef CrossSeq2__ctx_type_0 CrossSeq2_soft_type;

void CrossSeq2__ctx_type_0_init(CrossSeq2__ctx_type_0 &_output_);

static_inline void CrossSeq2_soft_init(CrossSeq2__ctx_type_0 &_output_){
   CrossSeq2__ctx_type_0_init(_output_);
   return ;
}

float CrossSeq2_soft(CrossSeq2__ctx_type_0 &_ctx, float x1);

typedef struct CrossSeq2__ctx_type_1 {
   float pre_x;
} CrossSeq2__ctx_type_1;

typedef CrossSeq2__ctx_type_1 CrossSeq2_change_type;

static_inline void CrossSeq2__ctx_type_1_init(CrossSeq2__ctx_type_1 &_output_){
   CrossSeq2__ctx_type_1 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq2_change_init(CrossSeq2__ctx_type_1 &_output_){
   CrossSeq2__ctx_type_1_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq2_change(CrossSeq2__ctx_type_1 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

typedef struct CrossSeq2__ctx_type_2 {
   uint8_t pre;
} CrossSeq2__ctx_type_2;

typedef CrossSeq2__ctx_type_2 CrossSeq2_edge_type;

static_inline void CrossSeq2__ctx_type_2_init(CrossSeq2__ctx_type_2 &_output_){
   CrossSeq2__ctx_type_2 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq2_edge_init(CrossSeq2__ctx_type_2 &_output_){
   CrossSeq2__ctx_type_2_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq2_edge(CrossSeq2__ctx_type_2 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct CrossSeq2__ctx_type_3 {
   int count;
} CrossSeq2__ctx_type_3;

typedef CrossSeq2__ctx_type_3 CrossSeq2_each_type;

static_inline void CrossSeq2__ctx_type_3_init(CrossSeq2__ctx_type_3 &_output_){
   CrossSeq2__ctx_type_3 _ctx;
   _ctx.count = 0;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq2_each_init(CrossSeq2__ctx_type_3 &_output_){
   CrossSeq2__ctx_type_3_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq2_each(CrossSeq2__ctx_type_3 &_ctx, int n){
   uint8_t ret;
   ret = (_ctx.count == 0);
   _ctx.count = ((1 + _ctx.count) % n);
   return ret;
}

static_inline float CrossSeq2_lerp(float a, float b, float i){
   return ((a * (1.f + (- i))) + (b * i));
};

typedef struct CrossSeq2__ctx_type_5 {
   float rate;
   float phase;
   float phOff;
   float o;
   CrossSeq2__ctx_type_2 _inst75d;
   CrossSeq2__ctx_type_3 _inst57b;
   CrossSeq2__ctx_type_1 _inst393;
   CrossSeq2__ctx_type_1 _inst193;
   CrossSeq2__ctx_type_0 _inst109;
} CrossSeq2__ctx_type_5;

typedef CrossSeq2__ctx_type_5 CrossSeq2_lfo_interp_type;

void CrossSeq2__ctx_type_5_init(CrossSeq2__ctx_type_5 &_output_);

static_inline void CrossSeq2_lfo_interp_init(CrossSeq2__ctx_type_5 &_output_){
   CrossSeq2__ctx_type_5_init(_output_);
   return ;
}

float CrossSeq2_lfo_interp(CrossSeq2__ctx_type_5 &_ctx, float cv, float shape, float amt, float pw, float reset, float phaseOff, float sampleTime);

typedef CrossSeq2__ctx_type_5 CrossSeq2_initPhase_type;

static_inline void CrossSeq2_initPhase_init(CrossSeq2__ctx_type_5 &_output_){
   CrossSeq2__ctx_type_5_init(_output_);
   return ;
}

static_inline void CrossSeq2_initPhase(CrossSeq2__ctx_type_5 &_ctx){
   _ctx.phase = 0.0f;
   _ctx.rate = 1.f;
   _ctx.phOff = 0.0f;
}

typedef struct CrossSeq2__ctx_type_6 {
   float open;
   CrossSeq2__ctx_type_1 _inst193;
} CrossSeq2__ctx_type_6;

typedef CrossSeq2__ctx_type_6 CrossSeq2_cross_detect_type;

void CrossSeq2__ctx_type_6_init(CrossSeq2__ctx_type_6 &_output_);

static_inline void CrossSeq2_cross_detect_init(CrossSeq2__ctx_type_6 &_output_){
   CrossSeq2__ctx_type_6_init(_output_);
   return ;
}

float CrossSeq2_cross_detect(CrossSeq2__ctx_type_6 &_ctx, float a, float b, float st);

typedef struct CrossSeq2__ctx_type_7 {
   float sync;
   float shape2;
   float shape1;
   float rate2;
   float rate1;
   float pw2;
   float pw1;
   float process_ret_3;
   float process_ret_2;
   float process_ret_1;
   float process_ret_0;
   float phaseOff2;
   float phaseOff1;
   float freq;
   float amt2;
   float amt1;
   CrossSeq2__ctx_type_6 _inst36b;
   CrossSeq2__ctx_type_5 _inst27f;
   CrossSeq2__ctx_type_5 _inst17f;
} CrossSeq2__ctx_type_7;

typedef CrossSeq2__ctx_type_7 CrossSeq2_process_type;

void CrossSeq2__ctx_type_7_init(CrossSeq2__ctx_type_7 &_output_);

static_inline void CrossSeq2_process_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

void CrossSeq2_process(CrossSeq2__ctx_type_7 &_ctx, float sampleTime);

typedef CrossSeq2__ctx_type_7 CrossSeq2_process_ret_0_type;

static_inline void CrossSeq2_process_ret_0_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline float CrossSeq2_process_ret_0(CrossSeq2__ctx_type_7 &_ctx){
   return _ctx.process_ret_0;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_process_ret_1_type;

static_inline void CrossSeq2_process_ret_1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline float CrossSeq2_process_ret_1(CrossSeq2__ctx_type_7 &_ctx){
   return _ctx.process_ret_1;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_process_ret_2_type;

static_inline void CrossSeq2_process_ret_2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline float CrossSeq2_process_ret_2(CrossSeq2__ctx_type_7 &_ctx){
   return _ctx.process_ret_2;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_process_ret_3_type;

static_inline void CrossSeq2_process_ret_3_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline float CrossSeq2_process_ret_3(CrossSeq2__ctx_type_7 &_ctx){
   return _ctx.process_ret_3;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setFreq_type;

static_inline void CrossSeq2_setFreq_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setFreq(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.freq = (input + knob);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setSync_type;

static_inline void CrossSeq2_setSync_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setSync(CrossSeq2__ctx_type_7 &_ctx, float value){
   _ctx.sync = value;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setRate1_type;

static_inline void CrossSeq2_setRate1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setRate1(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.rate1 = (input + knob);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setRate2_type;

static_inline void CrossSeq2_setRate2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setRate2(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.rate2 = (input + knob);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setPhase1_type;

static_inline void CrossSeq2_setPhase1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setPhase1(CrossSeq2__ctx_type_7 &_ctx, float phaseKnob){
   _ctx.phaseOff1 = phaseKnob;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setPhase2_type;

static_inline void CrossSeq2_setPhase2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setPhase2(CrossSeq2__ctx_type_7 &_ctx, float phaseKnob){
   _ctx.phaseOff2 = phaseKnob;
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setAmt1_type;

static_inline void CrossSeq2_setAmt1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setAmt1(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.amt1 = float_clip((input + knob),0.0f,1.f);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setAmt2_type;

static_inline void CrossSeq2_setAmt2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setAmt2(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.amt2 = float_clip((input + knob),0.0f,1.f);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setShape1_type;

static_inline void CrossSeq2_setShape1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setShape1(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.shape1 = (input + knob);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setShape2_type;

static_inline void CrossSeq2_setShape2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setShape2(CrossSeq2__ctx_type_7 &_ctx, float knob, float input){
   _ctx.shape2 = (input + knob);
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setPw1_type;

static_inline void CrossSeq2_setPw1_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setPw1(CrossSeq2__ctx_type_7 &_ctx, float knob){
   _ctx.pw1 = (-1.f + (2.f * knob));
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_setPw2_type;

static_inline void CrossSeq2_setPw2_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

static_inline void CrossSeq2_setPw2(CrossSeq2__ctx_type_7 &_ctx, float knob){
   _ctx.pw2 = (-1.f + (2.f * knob));
};

typedef CrossSeq2__ctx_type_7 CrossSeq2_default_type;

static_inline void CrossSeq2_default_init(CrossSeq2__ctx_type_7 &_output_){
   CrossSeq2__ctx_type_7_init(_output_);
   return ;
}

void CrossSeq2_default(CrossSeq2__ctx_type_7 &_ctx);



#endif // CROSSSEQ2_H
