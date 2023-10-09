
/* Code automatically generated by Vult https://github.com/modlfo/vult */
#ifndef CROSSSEQ3_H
#define CROSSSEQ3_H
#include <stdint.h>
#include <math.h>
#include "vultin.h"
#include "CrossSeq3.tables.h"

typedef struct _tuple___real_real_real_real_real_real_real_real_real_real_real__ {
   float field_0;
   float field_1;
   float field_2;
   float field_3;
   float field_4;
   float field_5;
   float field_6;
   float field_7;
   float field_8;
   float field_9;
   float field_10;
} _tuple___real_real_real_real_real_real_real_real_real_real_real__;

typedef struct CrossSeq3__ctx_type_0 {
   float x4;
   float x3;
   float x2;
} CrossSeq3__ctx_type_0;

typedef CrossSeq3__ctx_type_0 CrossSeq3_soft_type;

void CrossSeq3__ctx_type_0_init(CrossSeq3__ctx_type_0 &_output_);

static_inline void CrossSeq3_soft_init(CrossSeq3__ctx_type_0 &_output_){
   CrossSeq3__ctx_type_0_init(_output_);
   return ;
}

float CrossSeq3_soft(CrossSeq3__ctx_type_0 &_ctx, float x1);

typedef struct CrossSeq3__ctx_type_1 {
   uint8_t pre;
} CrossSeq3__ctx_type_1;

typedef CrossSeq3__ctx_type_1 CrossSeq3_edge_type;

static_inline void CrossSeq3__ctx_type_1_init(CrossSeq3__ctx_type_1 &_output_){
   CrossSeq3__ctx_type_1 _ctx;
   _ctx.pre = false;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq3_edge_init(CrossSeq3__ctx_type_1 &_output_){
   CrossSeq3__ctx_type_1_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq3_edge(CrossSeq3__ctx_type_1 &_ctx, uint8_t x){
   uint8_t ret;
   ret = (x && bool_not(_ctx.pre));
   _ctx.pre = x;
   return ret;
}

typedef struct CrossSeq3__ctx_type_2 {
   float pre_x;
} CrossSeq3__ctx_type_2;

typedef CrossSeq3__ctx_type_2 CrossSeq3_change_type;

static_inline void CrossSeq3__ctx_type_2_init(CrossSeq3__ctx_type_2 &_output_){
   CrossSeq3__ctx_type_2 _ctx;
   _ctx.pre_x = 0.0f;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq3_change_init(CrossSeq3__ctx_type_2 &_output_){
   CrossSeq3__ctx_type_2_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq3_change(CrossSeq3__ctx_type_2 &_ctx, float x){
   uint8_t v;
   v = (_ctx.pre_x != x);
   _ctx.pre_x = x;
   return v;
}

typedef struct CrossSeq3__ctx_type_3 {
   int count;
} CrossSeq3__ctx_type_3;

typedef CrossSeq3__ctx_type_3 CrossSeq3_each_type;

static_inline void CrossSeq3__ctx_type_3_init(CrossSeq3__ctx_type_3 &_output_){
   CrossSeq3__ctx_type_3 _ctx;
   _ctx.count = 0;
   _output_ = _ctx;
   return ;
}

static_inline void CrossSeq3_each_init(CrossSeq3__ctx_type_3 &_output_){
   CrossSeq3__ctx_type_3_init(_output_);
   return ;
}

static_inline uint8_t CrossSeq3_each(CrossSeq3__ctx_type_3 &_ctx, int n){
   uint8_t ret;
   ret = (_ctx.count == 0);
   _ctx.count = ((1 + _ctx.count) % n);
   return ret;
}

static_inline float CrossSeq3_lerp(float a, float b, float i){
   return ((a * (1.f + (- i))) + (b * i));
};

typedef struct CrossSeq3__ctx_type_5 {
   float rate;
   float phase;
   float o;
   CrossSeq3__ctx_type_0 _inst823;
   CrossSeq3__ctx_type_1 _inst578;
   CrossSeq3__ctx_type_3 _inst3b5;
   CrossSeq3__ctx_type_2 _inst1b9;
} CrossSeq3__ctx_type_5;

typedef CrossSeq3__ctx_type_5 CrossSeq3_lfo_interp_type;

void CrossSeq3__ctx_type_5_init(CrossSeq3__ctx_type_5 &_output_);

static_inline void CrossSeq3_lfo_interp_init(CrossSeq3__ctx_type_5 &_output_){
   CrossSeq3__ctx_type_5_init(_output_);
   return ;
}

float CrossSeq3_lfo_interp(CrossSeq3__ctx_type_5 &_ctx, float cv, float shape, float amt, float pw, float reset, float sampleTime);

typedef struct CrossSeq3__ctx_type_6 {
   float open;
   CrossSeq3__ctx_type_2 _inst1b9;
} CrossSeq3__ctx_type_6;

typedef CrossSeq3__ctx_type_6 CrossSeq3_cross_detect_type;

void CrossSeq3__ctx_type_6_init(CrossSeq3__ctx_type_6 &_output_);

static_inline void CrossSeq3_cross_detect_init(CrossSeq3__ctx_type_6 &_output_){
   CrossSeq3__ctx_type_6_init(_output_);
   return ;
}

float CrossSeq3_cross_detect(CrossSeq3__ctx_type_6 &_ctx, float a, float b, float st);

float CrossSeq3_cross_detect3(float a, float b, float c);

typedef struct CrossSeq3__ctx_type_8 {
   float sync;
   float shape3;
   float shape2;
   float shape1;
   float rate3;
   float rate2;
   float rate1;
   float pw3;
   float pw2;
   float pw1;
   float process_ret_9;
   float process_ret_8;
   float process_ret_7;
   float process_ret_6;
   float process_ret_5;
   float process_ret_4;
   float process_ret_3;
   float process_ret_2;
   float process_ret_10;
   float process_ret_1;
   float process_ret_0;
   float phase3;
   float phase2;
   float phase1;
   float freqK;
   float freq;
   float amt3;
   float amt2;
   float amt1;
   CrossSeq3__ctx_type_6 _inst6c3;
   CrossSeq3__ctx_type_6 _inst5c3;
   CrossSeq3__ctx_type_6 _inst4c3;
   CrossSeq3__ctx_type_5 _inst32f;
   CrossSeq3__ctx_type_5 _inst22f;
   CrossSeq3__ctx_type_5 _inst12f;
} CrossSeq3__ctx_type_8;

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_type;

void CrossSeq3__ctx_type_8_init(CrossSeq3__ctx_type_8 &_output_);

static_inline void CrossSeq3_process_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

void CrossSeq3_process(CrossSeq3__ctx_type_8 &_ctx, float sampleTime);

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_0_type;

static_inline void CrossSeq3_process_ret_0_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_0(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_0;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_1_type;

static_inline void CrossSeq3_process_ret_1_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_1(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_1;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_2_type;

static_inline void CrossSeq3_process_ret_2_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_2(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_2;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_3_type;

static_inline void CrossSeq3_process_ret_3_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_3(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_3;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_4_type;

static_inline void CrossSeq3_process_ret_4_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_4(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_4;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_5_type;

static_inline void CrossSeq3_process_ret_5_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_5(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_5;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_6_type;

static_inline void CrossSeq3_process_ret_6_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_6(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_6;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_7_type;

static_inline void CrossSeq3_process_ret_7_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_7(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_7;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_8_type;

static_inline void CrossSeq3_process_ret_8_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_8(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_8;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_9_type;

static_inline void CrossSeq3_process_ret_9_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_9(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_9;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_process_ret_10_type;

static_inline void CrossSeq3_process_ret_10_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline float CrossSeq3_process_ret_10(CrossSeq3__ctx_type_8 &_ctx){
   return _ctx.process_ret_10;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setFreq_type;

static_inline void CrossSeq3_setFreq_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setFreq(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.freq = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setSync_type;

static_inline void CrossSeq3_setSync_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setSync(CrossSeq3__ctx_type_8 &_ctx, float value){
   _ctx.sync = value;
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setRate1_type;

static_inline void CrossSeq3_setRate1_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setRate1(CrossSeq3__ctx_type_8 &_ctx, float knob, float input, float phaseKnob){
   _ctx.rate1 = (input + knob + phaseKnob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setRate2_type;

static_inline void CrossSeq3_setRate2_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setRate2(CrossSeq3__ctx_type_8 &_ctx, float knob, float input, float phaseKnob){
   _ctx.rate2 = (input + knob + phaseKnob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setRate3_type;

static_inline void CrossSeq3_setRate3_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setRate3(CrossSeq3__ctx_type_8 &_ctx, float knob, float input, float phaseKnob){
   _ctx.rate3 = (input + knob + phaseKnob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setAmt1_type;

static_inline void CrossSeq3_setAmt1_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setAmt1(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.amt1 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setAmt2_type;

static_inline void CrossSeq3_setAmt2_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setAmt2(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.amt2 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setAmt3_type;

static_inline void CrossSeq3_setAmt3_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setAmt3(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.amt3 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setShape1_type;

static_inline void CrossSeq3_setShape1_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setShape1(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.shape1 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setShape2_type;

static_inline void CrossSeq3_setShape2_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setShape2(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.shape2 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setShape3_type;

static_inline void CrossSeq3_setShape3_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setShape3(CrossSeq3__ctx_type_8 &_ctx, float knob, float input){
   _ctx.shape3 = (input + knob);
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setPw1_type;

static_inline void CrossSeq3_setPw1_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setPw1(CrossSeq3__ctx_type_8 &_ctx, float knob){
   _ctx.pw1 = (-1.f + (2.f * knob));
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setPw2_type;

static_inline void CrossSeq3_setPw2_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setPw2(CrossSeq3__ctx_type_8 &_ctx, float knob){
   _ctx.pw2 = (-1.f + (2.f * knob));
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_setPw3_type;

static_inline void CrossSeq3_setPw3_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

static_inline void CrossSeq3_setPw3(CrossSeq3__ctx_type_8 &_ctx, float knob){
   _ctx.pw3 = (-1.f + (2.f * knob));
};

typedef CrossSeq3__ctx_type_8 CrossSeq3_default_type;

static_inline void CrossSeq3_default_init(CrossSeq3__ctx_type_8 &_output_){
   CrossSeq3__ctx_type_8_init(_output_);
   return ;
}

void CrossSeq3_default(CrossSeq3__ctx_type_8 &_ctx);



#endif // CROSSSEQ3_H
