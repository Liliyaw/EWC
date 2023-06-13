// tvm target: c -keys=arm_cpu,cpu -mcpu=cortex-m85
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_divide(float* p0, float* p1, float* T_divide, uint8_t* global_const_workspace_86_var, uint8_t* global_workspace_87_var) {
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 80; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 25; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 4; ++ax2_inner) {
        if (((ax2_outer * 4) + ax2_inner) < 97) {
          int32_t cse_var_1 = (((ax0_ax1_fused * 97) + (ax2_outer * 4)) + ax2_inner);
          T_divide[cse_var_1] = (p0[cse_var_1] / p1[ax0_ax1_fused]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_max(float* p0, float* p0_red, uint8_t* global_const_workspace_80_var, uint8_t* global_workspace_81_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 80; ++ax0_ax1_fused_ax2_fused) {
    p0_red[ax0_ax1_fused_ax2_fused] = -3.402823e+38f;
    for (int32_t k2 = 0; k2 < 97; ++k2) {
      float v_ = p0_red[ax0_ax1_fused_ax2_fused];
      float v__1 = p0[((ax0_ax1_fused_ax2_fused * 97) + k2)];
      p0_red[ax0_ax1_fused_ax2_fused] = ((v_) > (v__1) ? (v_) : (v__1));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_adaptive_avg_pool2d(float* p0, float* adaptive_pool_avg, uint8_t* global_const_workspace_50_var, uint8_t* global_workspace_51_var) {
  void* adaptive_pool_sum_let = (&(global_workspace_51_var[229120]));
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 179; ++ax0_ax1_fused) {
    ((float*)adaptive_pool_sum_let)[ax0_ax1_fused] = 0.000000e+00f;
    for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
      for (int32_t rv1 = 0; rv1 < 160; ++rv1) {
        ((float*)adaptive_pool_sum_let)[ax0_ax1_fused] = (((float*)adaptive_pool_sum_let)[ax0_ax1_fused] + p0[(((ax0_ax1_fused * 320) + (rv0 * 160)) + rv1)]);
      }
    }
  }
  for (int32_t ax0_ax1_fused_1 = 0; ax0_ax1_fused_1 < 179; ++ax0_ax1_fused_1) {
    adaptive_pool_avg[ax0_ax1_fused_1] = (((float*)adaptive_pool_sum_let)[ax0_ax1_fused_1] * 3.125000e-03f);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_adaptive_avg_pool2d_1(float* p0, float* adaptive_pool_avg, uint8_t* global_const_workspace_62_var, uint8_t* global_workspace_63_var) {
  void* adaptive_pool_sum_let = (&(global_workspace_63_var[0]));
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 358; ++ax0_ax1_fused) {
    ((float*)adaptive_pool_sum_let)[ax0_ax1_fused] = 0.000000e+00f;
    for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
      for (int32_t rv1 = 0; rv1 < 160; ++rv1) {
        ((float*)adaptive_pool_sum_let)[ax0_ax1_fused] = (((float*)adaptive_pool_sum_let)[ax0_ax1_fused] + p0[(((ax0_ax1_fused * 320) + (rv0 * 160)) + rv1)]);
      }
    }
  }
  for (int32_t ax0_ax1_fused_1 = 0; ax0_ax1_fused_1 < 358; ++ax0_ax1_fused_1) {
    adaptive_pool_avg[ax0_ax1_fused_1] = (((float*)adaptive_pool_sum_let)[ax0_ax1_fused_1] * 3.125000e-03f);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip(float* p0, float* compute, uint8_t* global_const_workspace_54_var, uint8_t* global_workspace_55_var) {
  void* fused_nn_conv2d_constant_25_let = (&(global_const_workspace_54_var[2150976]));
  void* fused_constant_25_let = (&(global_const_workspace_54_var[1934928]));
  void* data_vec_let = (&(global_workspace_55_var[230016]));
  for (int32_t ci = 0; ci < 44; ++ci) {
    ((float*)data_vec_let)[ci] = p0[ci];
  }
  for (int32_t i1_outer = 0; i1_outer < 179; ++i1_outer) {
    void* conv_let = (&(global_workspace_55_var[229840]));
    ((float*)conv_let)[0] = 0.000000e+00f;
    for (int32_t ci_1 = 0; ci_1 < 44; ++ci_1) {
      ((float*)conv_let)[0] = (((float*)conv_let)[0] + (((float*)data_vec_let)[ci_1] * ((float*)fused_constant_25_let)[((i1_outer * 44) + ci_1)]));
    }
    float v_ = ((float*)conv_let)[0] + ((float*)fused_nn_conv2d_constant_25_let)[i1_outer];
    float v__1 = (v_) < (1.000000e+00f) ? (v_) : (1.000000e+00f);
    compute[i1_outer] = ((v__1) > (0.000000e+00f) ? (v__1) : (0.000000e+00f));
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_1(float* p0, float* compute, uint8_t* global_const_workspace_66_var, uint8_t* global_workspace_67_var) {
  void* fused_nn_conv2d_constant_29_let = (&(global_const_workspace_66_var[2143680]));
  void* fused_constant_29_let = (&(global_const_workspace_66_var[1548784]));
  void* data_vec_let = (&(global_workspace_67_var[0]));
  for (int32_t ci = 0; ci < 89; ++ci) {
    ((float*)data_vec_let)[ci] = p0[ci];
  }
  for (int32_t i1_outer = 0; i1_outer < 179; ++i1_outer) {
    void* conv_let = (&(global_workspace_67_var[368]));
    for (int32_t vc_init = 0; vc_init < 2; ++vc_init) {
      ((float*)conv_let)[vc_init] = 0.000000e+00f;
    }
    for (int32_t ci_1 = 0; ci_1 < 89; ++ci_1) {
      for (int32_t vc = 0; vc < 2; ++vc) {
        ((float*)conv_let)[vc] = (((float*)conv_let)[vc] + (((float*)data_vec_let)[ci_1] * ((float*)fused_constant_29_let)[(((i1_outer * 178) + (ci_1 * 2)) + vc)]));
      }
    }
    for (int32_t i1_inner = 0; i1_inner < 2; ++i1_inner) {
      int32_t cse_var_1 = ((i1_outer * 2) + i1_inner);
      float v_ = ((float*)conv_let)[i1_inner] + ((float*)fused_nn_conv2d_constant_29_let)[cse_var_1];
      float v__1 = (v_) < (1.000000e+00f) ? (v_) : (1.000000e+00f);
      compute[cse_var_1] = ((v__1) > (0.000000e+00f) ? (v__1) : (0.000000e+00f));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply(float* p0, float* T_multiply, uint8_t* global_const_workspace_2_var, uint8_t* global_workspace_3_var) {
  void* fused_nn_conv2d_constant_let = (&(global_const_workspace_2_var[2164096]));
  void* fused_constant_let = (&(global_const_workspace_2_var[2148000]));
  void* data_vec_let = (&(global_workspace_3_var[0]));
  for (int32_t h = 0; h < 16; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 3; ++ci) {
        for (int32_t vh = 0; vh < 3; ++vh) {
          for (int32_t vw = 0; vw < 11; ++vw) {
            int32_t cse_var_1 = (w * 10);
            ((float*)data_vec_let)[(((((h * 3168) + (w * 99)) + (ci * 33)) + (vh * 11)) + vw)] = (((1 <= ((h * 2) + vh)) && (1 <= (cse_var_1 + vw))) ? p0[((((((ci * 10240) + (h * 640)) + (vh * 320)) + cse_var_1) + vw) - 321)] : 0.000000e+00f);
          }
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 11; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 16; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_3_var[315392]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 3; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_1 * 2))] * ((float*)fused_constant_let)[((ax1_outer * 27) + (ci_1 * 9))]));
          }
          for (int32_t vw_2 = 0; vw_2 < 5; ++vw_2) {
            ((float*)conv_let)[vw_2] = (((float*)conv_let)[vw_2] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_2 * 2)) + 1)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 1)]));
          }
          for (int32_t vw_3 = 0; vw_3 < 5; ++vw_3) {
            ((float*)conv_let)[vw_3] = (((float*)conv_let)[vw_3] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_3 * 2)) + 2)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 2)]));
          }
          for (int32_t vw_4 = 0; vw_4 < 5; ++vw_4) {
            ((float*)conv_let)[vw_4] = (((float*)conv_let)[vw_4] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_4 * 2)) + 11)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 3)]));
          }
          for (int32_t vw_5 = 0; vw_5 < 5; ++vw_5) {
            ((float*)conv_let)[vw_5] = (((float*)conv_let)[vw_5] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_5 * 2)) + 12)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 4)]));
          }
          for (int32_t vw_6 = 0; vw_6 < 5; ++vw_6) {
            ((float*)conv_let)[vw_6] = (((float*)conv_let)[vw_6] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_6 * 2)) + 13)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 5)]));
          }
          for (int32_t vw_7 = 0; vw_7 < 5; ++vw_7) {
            ((float*)conv_let)[vw_7] = (((float*)conv_let)[vw_7] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_7 * 2)) + 22)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 6)]));
          }
          for (int32_t vw_8 = 0; vw_8 < 5; ++vw_8) {
            ((float*)conv_let)[vw_8] = (((float*)conv_let)[vw_8] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_8 * 2)) + 23)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 7)]));
          }
          for (int32_t vw_9 = 0; vw_9 < 5; ++vw_9) {
            ((float*)conv_let)[vw_9] = (((float*)conv_let)[vw_9] + (((float*)data_vec_let)[(((((ax2_outer * 3168) + (ax3_outer * 99)) + (ci_1 * 33)) + (vw_9 * 2)) + 24)] * ((float*)fused_constant_let)[(((ax1_outer * 27) + (ci_1 * 9)) + 8)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 2560) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_1(float* p0, float* T_multiply, uint8_t* global_const_workspace_4_var, uint8_t* global_workspace_5_var) {
  void* fused_nn_conv2d_constant_1_let = (&(global_const_workspace_4_var[2164048]));
  void* fused_constant_1_let = (&(global_const_workspace_4_var[2160336]));
  void* fused_constant_1_global_global_let = (&(global_workspace_5_var[116528]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 11; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 9) + (ax2_c * 3)) + ax3_c);
        ((float*)fused_constant_1_global_global_let)[cse_var_1] = ((float*)fused_constant_1_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_5_var[0]));
  for (int32_t c_outer_c = 0; c_outer_c < 11; ++c_outer_c) {
    for (int32_t i_c_outer = 0; i_c_outer < 4; ++i_c_outer) {
      void* PaddedInput_global_global_let = (&(global_workspace_5_var[112640]));
      for (int32_t ax2_c_1 = 0; ax2_c_1 < 6; ++ax2_c_1) {
        for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
          int32_t cse_var_2 = ((i_c_outer * 4) + ax2_c_1);
          ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 162) + ax3_c_1)] = (((((1 <= cse_var_2) && (cse_var_2 < 17)) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[(((((c_outer_c * 2560) + (i_c_outer * 640)) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
        }
      }
      for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
        for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
          ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 2560) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 2560) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 2560) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 2560) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
        }
        for (int32_t di = 0; di < 3; ++di) {
          for (int32_t dj = 0; dj < 3; ++dj) {
            for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
              int32_t cse_var_4 = (j_c_outer * 2);
              int32_t cse_var_3 = ((((c_outer_c * 2560) + (i_c_outer * 640)) + cse_var_4) + j_c_inner);
              ((float*)DepthwiseConv2d_global_let)[cse_var_3] = (((float*)DepthwiseConv2d_global_let)[cse_var_3] + (((float*)PaddedInput_global_global_let)[((((di * 162) + cse_var_4) + j_c_inner) + dj)] * ((float*)fused_constant_1_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
              int32_t cse_var_6 = (j_c_outer * 2);
              int32_t cse_var_5 = (((((c_outer_c * 2560) + (i_c_outer * 640)) + cse_var_6) + j_c_inner_1) + 160);
              ((float*)DepthwiseConv2d_global_let)[cse_var_5] = (((float*)DepthwiseConv2d_global_let)[cse_var_5] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_6) + j_c_inner_1) + dj) + 162)] * ((float*)fused_constant_1_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
              int32_t cse_var_8 = (j_c_outer * 2);
              int32_t cse_var_7 = (((((c_outer_c * 2560) + (i_c_outer * 640)) + cse_var_8) + j_c_inner_2) + 320);
              ((float*)DepthwiseConv2d_global_let)[cse_var_7] = (((float*)DepthwiseConv2d_global_let)[cse_var_7] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_8) + j_c_inner_2) + dj) + 324)] * ((float*)fused_constant_1_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
              int32_t cse_var_10 = (j_c_outer * 2);
              int32_t cse_var_9 = (((((c_outer_c * 2560) + (i_c_outer * 640)) + cse_var_10) + j_c_inner_3) + 480);
              ((float*)DepthwiseConv2d_global_let)[cse_var_9] = (((float*)DepthwiseConv2d_global_let)[cse_var_9] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_10) + j_c_inner_3) + dj) + 486)] * ((float*)fused_constant_1_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 11; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 16; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_11 = (((ax1 * 2560) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_11] + ((float*)fused_nn_conv2d_constant_1_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_11] = ((((float*)DepthwiseConv2d_global_let)[cse_var_11] + ((float*)fused_nn_conv2d_constant_1_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_10(float* p0, float* T_multiply, uint8_t* global_const_workspace_22_var, uint8_t* global_workspace_23_var) {
  void* fused_nn_conv2d_constant_10_let = (&(global_const_workspace_22_var[2162608]));
  void* fused_constant_10_let = (&(global_const_workspace_22_var[1903232]));
  void* data_vec_let = (&(global_workspace_23_var[455680]));
  for (int32_t h = 0; h < 8; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 89; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 14240) + (w * 445)) + (ci * 5)) + vw)] = p0[((((ci * 1280) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 89; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 8; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_23_var[911360]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 89; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 14240) + (ax3_outer * 445)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_10_let)[((ax1_outer * 89) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_10_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 1280) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_10_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_11(float* p0, float* T_multiply, uint8_t* global_const_workspace_24_var, uint8_t* global_workspace_25_var) {
  void* fused_nn_conv2d_constant_11_let = (&(global_const_workspace_24_var[2162240]));
  void* fused_constant_11_let = (&(global_const_workspace_24_var[2135856]));
  void* fused_constant_11_global_global_let = (&(global_workspace_25_var[689360]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 89; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 9) + (ax2_c * 3)) + ax3_c);
        ((float*)fused_constant_11_global_global_let)[cse_var_1] = ((float*)fused_constant_11_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_25_var[455680]));
  for (int32_t c_outer_c = 0; c_outer_c < 89; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_25_var[683520]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 9; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 162) + ax3_c_1)] = ((((1 <= ax2_c_1) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[((((c_outer_c * 1280) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 3; ++di) {
        for (int32_t dj = 0; dj < 3; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 162) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_11_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_5) + j_c_inner_1) + dj) + 324)] * ((float*)fused_constant_11_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_7) + j_c_inner_2) + dj) + 648)] * ((float*)fused_constant_11_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_9) + j_c_inner_3) + dj) + 972)] * ((float*)fused_constant_11_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 89; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_11_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_11_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_12(float* p0, float* T_multiply, uint8_t* global_const_workspace_26_var, uint8_t* global_workspace_27_var) {
  void* fused_nn_conv2d_constant_12_let = (&(global_const_workspace_26_var[2159616]));
  void* fused_constant_12_let = (&(global_const_workspace_26_var[1803696]));
  void* data_vec_let = (&(global_workspace_27_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 89; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 14240) + (w * 445)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_27_var[686080]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 89; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 14240) + (ax3_outer * 445)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_12_let)[((ax1_outer * 89) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_12_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_12_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_13(float* p0, float* T_multiply, uint8_t* global_const_workspace_28_var, uint8_t* global_workspace_29_var) {
  void* fused_nn_conv2d_constant_13_let = (&(global_const_workspace_28_var[2158896]));
  void* fused_constant_13_let = (&(global_const_workspace_28_var[2087456]));
  void* fused_constant_13_global_global_let = (&(global_workspace_29_var[916480]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_13_global_global_let)[cse_var_1] = ((float*)fused_constant_13_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_29_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_29_var[934384]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 8; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_13_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 164)] * ((float*)fused_constant_13_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_7) + j_c_inner_2) + dj) + 328)] * ((float*)fused_constant_13_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_9) + j_c_inner_3) + dj) + 492)] * ((float*)fused_constant_13_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_13_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_13_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_14(float* p0, float* T_multiply, uint8_t* global_const_workspace_30_var, uint8_t* global_workspace_31_var) {
  void* fused_nn_conv2d_constant_14_let = (&(global_const_workspace_30_var[2158176]));
  void* fused_constant_14_let = (&(global_const_workspace_30_var[1420608]));
  void* data_vec_let = (&(global_workspace_31_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_31_var[916480]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_14_let)[((ax1_outer * 179) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_14_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_14_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_15(float* p0, float* T_multiply, uint8_t* global_const_workspace_32_var, uint8_t* global_workspace_33_var) {
  void* fused_nn_conv2d_constant_15_let = (&(global_const_workspace_32_var[2157456]));
  void* fused_constant_15_let = (&(global_const_workspace_32_var[2069552]));
  void* fused_constant_15_global_global_let = (&(global_workspace_33_var[916480]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_15_global_global_let)[cse_var_1] = ((float*)fused_constant_15_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_33_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_33_var[934384]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 8; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_15_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 164)] * ((float*)fused_constant_15_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_7) + j_c_inner_2) + dj) + 328)] * ((float*)fused_constant_15_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_9) + j_c_inner_3) + dj) + 492)] * ((float*)fused_constant_15_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_15_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_15_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_16(float* p0, float* T_multiply, uint8_t* global_const_workspace_34_var, uint8_t* global_workspace_35_var) {
  void* fused_nn_conv2d_constant_16_let = (&(global_const_workspace_34_var[2156736]));
  void* fused_constant_16_let = (&(global_const_workspace_34_var[1292432]));
  void* data_vec_let = (&(global_workspace_35_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_35_var[916480]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_16_let)[((ax1_outer * 179) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_16_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_16_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_17(float* p0, float* T_multiply, uint8_t* global_const_workspace_36_var, uint8_t* global_workspace_37_var) {
  void* fused_nn_conv2d_constant_17_let = (&(global_const_workspace_36_var[2156016]));
  void* fused_constant_17_let = (&(global_const_workspace_36_var[2051648]));
  void* fused_constant_17_global_global_let = (&(global_workspace_37_var[916480]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_17_global_global_let)[cse_var_1] = ((float*)fused_constant_17_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_37_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_37_var[934384]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 8; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_17_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 164)] * ((float*)fused_constant_17_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_7) + j_c_inner_2) + dj) + 328)] * ((float*)fused_constant_17_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_9) + j_c_inner_3) + dj) + 492)] * ((float*)fused_constant_17_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_17_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_17_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_18(float* p0, float* T_multiply, uint8_t* global_const_workspace_38_var, uint8_t* global_workspace_39_var) {
  void* fused_nn_conv2d_constant_18_let = (&(global_const_workspace_38_var[2155296]));
  void* fused_constant_18_let = (&(global_const_workspace_38_var[1164256]));
  void* data_vec_let = (&(global_workspace_39_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_39_var[916480]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_18_let)[((ax1_outer * 179) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_18_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_18_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_19(float* p0, float* T_multiply, uint8_t* global_const_workspace_40_var, uint8_t* global_workspace_41_var) {
  void* fused_nn_conv2d_constant_19_let = (&(global_const_workspace_40_var[2154576]));
  void* fused_constant_19_let = (&(global_const_workspace_40_var[2033744]));
  void* fused_constant_19_global_global_let = (&(global_workspace_41_var[916480]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_19_global_global_let)[cse_var_1] = ((float*)fused_constant_19_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_41_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_41_var[934384]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 8; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_19_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 164)] * ((float*)fused_constant_19_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_7) + j_c_inner_2) + dj) + 328)] * ((float*)fused_constant_19_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_9) + j_c_inner_3) + dj) + 492)] * ((float*)fused_constant_19_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_19_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_19_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_2(float* p0, float* T_multiply, uint8_t* global_const_workspace_6_var, uint8_t* global_workspace_7_var) {
  void* fused_nn_conv2d_constant_2_let = (&(global_const_workspace_6_var[2163952]));
  void* fused_constant_2_let = (&(global_const_workspace_6_var[2149200]));
  void* data_vec_let = (&(global_workspace_7_var[225280]));
  for (int32_t h = 0; h < 16; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 11; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 1760) + (w * 55)) + (ci * 5)) + vw)] = p0[((((ci * 2560) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 11; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 16; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_7_var[337920]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          for (int32_t vc_init = 0; vc_init < 2; ++vc_init) {
            ((float*)conv_let)[((vw_init * 2) + vc_init)] = 0.000000e+00f;
          }
        }
        for (int32_t ci_1 = 0; ci_1 < 11; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            for (int32_t vc = 0; vc < 2; ++vc) {
              int32_t cse_var_1 = ((vw_1 * 2) + vc);
              ((float*)conv_let)[cse_var_1] = (((float*)conv_let)[cse_var_1] + (((float*)data_vec_let)[((((ax2_outer * 1760) + (ax3_outer * 55)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_2_let)[(((ax1_outer * 22) + (ci_1 * 2)) + vc)]));
            }
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          for (int32_t ax1_inner = 0; ax1_inner < 2; ++ax1_inner) {
            int32_t cse_var_3 = ((ax3_inner * 2) + ax1_inner);
            int32_t cse_var_2 = ((ax1_outer * 2) + ax1_inner);
            float v_ = ((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_2_let)[cse_var_2];
            float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
            T_multiply[(((((ax1_outer * 5120) + (ax1_inner * 2560)) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_2_let)[cse_var_2]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_20(float* p0, float* T_multiply, uint8_t* global_const_workspace_42_var, uint8_t* global_workspace_43_var) {
  void* fused_nn_conv2d_constant_20_let = (&(global_const_workspace_42_var[2153856]));
  void* fused_constant_20_let = (&(global_const_workspace_42_var[1036080]));
  void* data_vec_let = (&(global_workspace_43_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_43_var[916480]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_20_let)[((ax1_outer * 179) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_20_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_20_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_21(float* p0, float* T_multiply, uint8_t* global_const_workspace_44_var, uint8_t* global_workspace_45_var) {
  void* fused_nn_conv2d_constant_21_let = (&(global_const_workspace_44_var[2153136]));
  void* fused_constant_21_let = (&(global_const_workspace_44_var[2015840]));
  void* fused_constant_21_global_global_let = (&(global_workspace_45_var[916480]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_21_global_global_let)[cse_var_1] = ((float*)fused_constant_21_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_45_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_45_var[934384]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 8; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 640) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_21_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 640) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 164)] * ((float*)fused_constant_21_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
            int32_t cse_var_7 = (j_c_outer * 2);
            int32_t cse_var_6 = ((((c_outer_c * 640) + cse_var_7) + j_c_inner_2) + 320);
            ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_7) + j_c_inner_2) + dj) + 328)] * ((float*)fused_constant_21_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
            int32_t cse_var_9 = (j_c_outer * 2);
            int32_t cse_var_8 = ((((c_outer_c * 640) + cse_var_9) + j_c_inner_3) + 480);
            ((float*)DepthwiseConv2d_global_let)[cse_var_8] = (((float*)DepthwiseConv2d_global_let)[cse_var_8] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_9) + j_c_inner_3) + dj) + 492)] * ((float*)fused_constant_21_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 4; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((ax1 * 640) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_21_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_10] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_21_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_22(float* p0, float* T_multiply, uint8_t* global_const_workspace_46_var, uint8_t* global_workspace_47_var) {
  void* fused_nn_conv2d_constant_22_let = (&(global_const_workspace_46_var[2152416]));
  void* fused_constant_22_let = (&(global_const_workspace_46_var[907904]));
  void* data_vec_let = (&(global_workspace_47_var[458240]));
  for (int32_t h = 0; h < 4; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 640) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 4; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_47_var[916480]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_22_let)[((ax1_outer * 179) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_22_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 640) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_22_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_23(float* p0, float* T_multiply, uint8_t* global_const_workspace_48_var, uint8_t* global_workspace_49_var) {
  void* fused_nn_conv2d_constant_23_let = (&(global_const_workspace_48_var[2151696]));
  void* fused_constant_23_let = (&(global_const_workspace_48_var[1997936]));
  void* fused_constant_23_global_global_let = (&(global_workspace_49_var[687360]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 25) + (ax2_c * 5)) + ax3_c);
        ((float*)fused_constant_23_global_global_let)[cse_var_1] = ((float*)fused_constant_23_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_49_var[458240]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_49_var[705264]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 7; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 164) + ax3_c_1)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 6)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[((((c_outer_c * 640) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        ((float*)DepthwiseConv2d_global_let)[(((c_outer_c * 320) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 320) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            int32_t cse_var_3 = (j_c_outer * 2);
            int32_t cse_var_2 = (((c_outer_c * 320) + cse_var_3) + j_c_inner);
            ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[((((di * 164) + cse_var_3) + j_c_inner) + dj)] * ((float*)fused_constant_23_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            int32_t cse_var_5 = (j_c_outer * 2);
            int32_t cse_var_4 = ((((c_outer_c * 320) + cse_var_5) + j_c_inner_1) + 160);
            ((float*)DepthwiseConv2d_global_let)[cse_var_4] = (((float*)DepthwiseConv2d_global_let)[cse_var_4] + (((float*)PaddedInput_global_global_let)[(((((di * 164) + cse_var_5) + j_c_inner_1) + dj) + 328)] * ((float*)fused_constant_23_global_global_let)[(((c_outer_c * 25) + (di * 5)) + dj)]));
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 179; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 2; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_6 = (((ax1 * 320) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_6] + ((float*)fused_nn_conv2d_constant_23_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_6] = ((((float*)DepthwiseConv2d_global_let)[cse_var_6] + ((float*)fused_nn_conv2d_constant_23_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_24(float* p0, float* p1, float* T_multiply, uint8_t* global_const_workspace_58_var, uint8_t* global_workspace_59_var) {
  void* fused_nn_conv2d_constant_26_let = (&(global_const_workspace_58_var[2146560]));
  void* data_vec_let = (&(global_workspace_59_var[714576]));
  for (int32_t h = 0; h < 2; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 179; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 28640) + (w * 895)) + (ci * 5)) + vw)] = p0[((((ci * 320) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 2; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_59_var[943696]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          for (int32_t vc_init = 0; vc_init < 2; ++vc_init) {
            ((float*)conv_let)[((vw_init * 2) + vc_init)] = 0.000000e+00f;
          }
        }
        for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            for (int32_t vc = 0; vc < 2; ++vc) {
              int32_t cse_var_1 = ((vw_1 * 2) + vc);
              ((float*)conv_let)[cse_var_1] = (((float*)conv_let)[cse_var_1] + (((float*)data_vec_let)[((((ax2_outer * 28640) + (ax3_outer * 895)) + (ci_1 * 5)) + vw_1)] * p1[(((ax1_outer * 358) + (ci_1 * 2)) + vc)]));
            }
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          for (int32_t ax1_inner = 0; ax1_inner < 2; ++ax1_inner) {
            int32_t cse_var_3 = ((ax3_inner * 2) + ax1_inner);
            int32_t cse_var_2 = ((ax1_outer * 2) + ax1_inner);
            float v_ = ((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_26_let)[cse_var_2];
            float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
            T_multiply[(((((ax1_outer * 640) + (ax1_inner * 320)) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_26_let)[cse_var_2]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_25(float* p0, float* T_multiply, uint8_t* global_const_workspace_60_var, uint8_t* global_workspace_61_var) {
  void* fused_nn_conv2d_constant_27_let = (&(global_const_workspace_60_var[2145120]));
  void* fused_constant_27_let = (&(global_const_workspace_60_var[1867424]));
  void* fused_constant_27_global_global_let = (&(global_workspace_61_var[458240]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 179; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 5; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 5; ++ax3_c) {
        for (int32_t ax0_inner_c = 0; ax0_inner_c < 2; ++ax0_inner_c) {
          int32_t cse_var_1 = (ax0_outer_c * 50);
          ((float*)fused_constant_27_global_global_let)[(((cse_var_1 + (ax2_c * 10)) + (ax3_c * 2)) + ax0_inner_c)] = ((float*)fused_constant_27_let)[(((cse_var_1 + (ax0_inner_c * 25)) + (ax2_c * 5)) + ax3_c)];
        }
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_61_var[970896]));
  for (int32_t c_outer_c = 0; c_outer_c < 179; ++c_outer_c) {
    void* PaddedInput_global_global_let = (&(global_workspace_61_var[494048]));
    for (int32_t ax2_c_1 = 0; ax2_c_1 < 6; ++ax2_c_1) {
      for (int32_t ax3_c_1 = 0; ax3_c_1 < 164; ++ax3_c_1) {
        for (int32_t ax1_inner_c = 0; ax1_inner_c < 2; ++ax1_inner_c) {
          ((float*)PaddedInput_global_global_let)[(((ax2_c_1 * 328) + (ax3_c_1 * 2)) + ax1_inner_c)] = (((((2 <= ax2_c_1) && (ax2_c_1 < 4)) && (2 <= ax3_c_1)) && (ax3_c_1 < 162)) ? p0[(((((c_outer_c * 640) + (ax1_inner_c * 320)) + (ax2_c_1 * 160)) + ax3_c_1) - 322)] : 0.000000e+00f);
        }
      }
    }
    for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
      for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
        for (int32_t c_inner_c_init = 0; c_inner_c_init < 2; ++c_inner_c_init) {
          ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 640) + (j_c_outer * 4)) + (j_c_inner_init * 2)) + c_inner_c_init)] = 0.000000e+00f;
        }
      }
      for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
        for (int32_t c_inner_c_init_1 = 0; c_inner_c_init_1 < 2; ++c_inner_c_init_1) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 640) + (j_c_outer * 4)) + (j_c_inner_init_1 * 2)) + c_inner_c_init_1) + 320)] = 0.000000e+00f;
        }
      }
      for (int32_t di = 0; di < 5; ++di) {
        for (int32_t dj = 0; dj < 5; ++dj) {
          for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
            for (int32_t c_inner_c = 0; c_inner_c < 2; ++c_inner_c) {
              int32_t cse_var_5 = (j_c_outer * 4);
              int32_t cse_var_4 = (j_c_inner * 2);
              int32_t cse_var_3 = (dj * 2);
              int32_t cse_var_2 = ((((c_outer_c * 640) + cse_var_5) + cse_var_4) + c_inner_c);
              ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[(((((di * 328) + cse_var_5) + cse_var_4) + cse_var_3) + c_inner_c)] * ((float*)fused_constant_27_global_global_let)[((((c_outer_c * 50) + (di * 10)) + cse_var_3) + c_inner_c)]));
            }
          }
          for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
            for (int32_t c_inner_c_1 = 0; c_inner_c_1 < 2; ++c_inner_c_1) {
              int32_t cse_var_9 = (j_c_outer * 4);
              int32_t cse_var_8 = (j_c_inner_1 * 2);
              int32_t cse_var_7 = (dj * 2);
              int32_t cse_var_6 = (((((c_outer_c * 640) + cse_var_9) + cse_var_8) + c_inner_c_1) + 320);
              ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[((((((di * 328) + cse_var_9) + cse_var_8) + cse_var_7) + c_inner_c_1) + 328)] * ((float*)fused_constant_27_global_global_let)[((((c_outer_c * 50) + (di * 10)) + cse_var_7) + c_inner_c_1)]));
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 358; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 2; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_10 = (((((ax1 >> 1) * 640) + (ax2 * 320)) + (ax3 * 2)) + (ax1 & 1));
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_27_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[(((ax1 * 320) + (ax2 * 160)) + ax3)] = ((((float*)DepthwiseConv2d_global_let)[cse_var_10] + ((float*)fused_nn_conv2d_constant_27_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_26(float* p0, float* p1, float* T_multiply, uint8_t* global_const_workspace_70_var, uint8_t* global_workspace_71_var) {
  void* fused_nn_conv2d_constant_30_let = (&(global_const_workspace_70_var[2142240]));
  void* data_vec_let = (&(global_workspace_71_var[970896]));
  for (int32_t h = 0; h < 2; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 358; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 57280) + (w * 1790)) + (ci * 5)) + vw)] = p0[((((ci * 320) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 179; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 2; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_71_var[1429136]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          for (int32_t vc_init = 0; vc_init < 2; ++vc_init) {
            ((float*)conv_let)[((vw_init * 2) + vc_init)] = 0.000000e+00f;
          }
        }
        for (int32_t ci_1 = 0; ci_1 < 358; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            for (int32_t vc = 0; vc < 2; ++vc) {
              int32_t cse_var_1 = ((vw_1 * 2) + vc);
              ((float*)conv_let)[cse_var_1] = (((float*)conv_let)[cse_var_1] + (((float*)data_vec_let)[((((ax2_outer * 57280) + (ax3_outer * 1790)) + (ci_1 * 5)) + vw_1)] * p1[(((ax1_outer * 716) + (ci_1 * 2)) + vc)]));
            }
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          for (int32_t ax1_inner = 0; ax1_inner < 2; ++ax1_inner) {
            int32_t cse_var_3 = ((ax3_inner * 2) + ax1_inner);
            int32_t cse_var_2 = ((ax1_outer * 2) + ax1_inner);
            float v_ = ((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_30_let)[cse_var_2];
            float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
            T_multiply[(((((ax1_outer * 640) + (ax1_inner * 320)) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_30_let)[cse_var_2]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_3(float* p0, float* T_multiply, uint8_t* global_const_workspace_8_var, uint8_t* global_workspace_9_var) {
  void* fused_nn_conv2d_constant_3_let = (&(global_const_workspace_8_var[2163856]));
  void* fused_constant_3_let = (&(global_const_workspace_8_var[2150176]));
  void* fused_constant_3_global_global_let = (&(global_workspace_9_var[458336]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 11; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        for (int32_t ax0_inner_c = 0; ax0_inner_c < 2; ++ax0_inner_c) {
          int32_t cse_var_1 = (ax0_outer_c * 18);
          ((float*)fused_constant_3_global_global_let)[(((cse_var_1 + (ax2_c * 6)) + (ax3_c * 2)) + ax0_inner_c)] = ((float*)fused_constant_3_let)[(((cse_var_1 + (ax0_inner_c * 9)) + (ax2_c * 3)) + ax3_c)];
        }
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_9_var[225280]));
  for (int32_t c_outer_c = 0; c_outer_c < 11; ++c_outer_c) {
    for (int32_t i_c_outer = 0; i_c_outer < 4; ++i_c_outer) {
      void* PaddedInput_global_global_let = (&(global_workspace_9_var[450560]));
      for (int32_t ax2_c_1 = 0; ax2_c_1 < 6; ++ax2_c_1) {
        for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
          for (int32_t ax1_inner_c = 0; ax1_inner_c < 2; ++ax1_inner_c) {
            int32_t cse_var_2 = ((i_c_outer * 4) + ax2_c_1);
            ((float*)PaddedInput_global_global_let)[(((ax2_c_1 * 324) + (ax3_c_1 * 2)) + ax1_inner_c)] = (((((1 <= cse_var_2) && (cse_var_2 < 17)) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[((((((c_outer_c * 5120) + (ax1_inner_c * 2560)) + (i_c_outer * 640)) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
          }
        }
      }
      for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
        for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
          for (int32_t c_inner_c_init = 0; c_inner_c_init < 2; ++c_inner_c_init) {
            ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 5120) + (i_c_outer * 1280)) + (j_c_outer * 4)) + (j_c_inner_init * 2)) + c_inner_c_init)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
          for (int32_t c_inner_c_init_1 = 0; c_inner_c_init_1 < 2; ++c_inner_c_init_1) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 1280)) + (j_c_outer * 4)) + (j_c_inner_init_1 * 2)) + c_inner_c_init_1) + 320)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
          for (int32_t c_inner_c_init_2 = 0; c_inner_c_init_2 < 2; ++c_inner_c_init_2) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 1280)) + (j_c_outer * 4)) + (j_c_inner_init_2 * 2)) + c_inner_c_init_2) + 640)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
          for (int32_t c_inner_c_init_3 = 0; c_inner_c_init_3 < 2; ++c_inner_c_init_3) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 1280)) + (j_c_outer * 4)) + (j_c_inner_init_3 * 2)) + c_inner_c_init_3) + 960)] = 0.000000e+00f;
          }
        }
        for (int32_t di = 0; di < 3; ++di) {
          for (int32_t dj = 0; dj < 3; ++dj) {
            for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
              for (int32_t c_inner_c = 0; c_inner_c < 2; ++c_inner_c) {
                int32_t cse_var_6 = (j_c_outer * 4);
                int32_t cse_var_5 = (j_c_inner * 2);
                int32_t cse_var_4 = (dj * 2);
                int32_t cse_var_3 = (((((c_outer_c * 5120) + (i_c_outer * 1280)) + cse_var_6) + cse_var_5) + c_inner_c);
                ((float*)DepthwiseConv2d_global_let)[cse_var_3] = (((float*)DepthwiseConv2d_global_let)[cse_var_3] + (((float*)PaddedInput_global_global_let)[(((((di * 324) + cse_var_6) + cse_var_5) + cse_var_4) + c_inner_c)] * ((float*)fused_constant_3_global_global_let)[((((c_outer_c * 18) + (di * 6)) + cse_var_4) + c_inner_c)]));
              }
            }
            for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
              for (int32_t c_inner_c_1 = 0; c_inner_c_1 < 2; ++c_inner_c_1) {
                int32_t cse_var_10 = (j_c_outer * 4);
                int32_t cse_var_9 = (j_c_inner_1 * 2);
                int32_t cse_var_8 = (dj * 2);
                int32_t cse_var_7 = ((((((c_outer_c * 5120) + (i_c_outer * 1280)) + cse_var_10) + cse_var_9) + c_inner_c_1) + 320);
                ((float*)DepthwiseConv2d_global_let)[cse_var_7] = (((float*)DepthwiseConv2d_global_let)[cse_var_7] + (((float*)PaddedInput_global_global_let)[((((((di * 324) + cse_var_10) + cse_var_9) + cse_var_8) + c_inner_c_1) + 324)] * ((float*)fused_constant_3_global_global_let)[((((c_outer_c * 18) + (di * 6)) + cse_var_8) + c_inner_c_1)]));
              }
            }
            for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
              for (int32_t c_inner_c_2 = 0; c_inner_c_2 < 2; ++c_inner_c_2) {
                int32_t cse_var_14 = (j_c_outer * 4);
                int32_t cse_var_13 = (j_c_inner_2 * 2);
                int32_t cse_var_12 = (dj * 2);
                int32_t cse_var_11 = ((((((c_outer_c * 5120) + (i_c_outer * 1280)) + cse_var_14) + cse_var_13) + c_inner_c_2) + 640);
                ((float*)DepthwiseConv2d_global_let)[cse_var_11] = (((float*)DepthwiseConv2d_global_let)[cse_var_11] + (((float*)PaddedInput_global_global_let)[((((((di * 324) + cse_var_14) + cse_var_13) + cse_var_12) + c_inner_c_2) + 648)] * ((float*)fused_constant_3_global_global_let)[((((c_outer_c * 18) + (di * 6)) + cse_var_12) + c_inner_c_2)]));
              }
            }
            for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
              for (int32_t c_inner_c_3 = 0; c_inner_c_3 < 2; ++c_inner_c_3) {
                int32_t cse_var_18 = (j_c_outer * 4);
                int32_t cse_var_17 = (j_c_inner_3 * 2);
                int32_t cse_var_16 = (dj * 2);
                int32_t cse_var_15 = ((((((c_outer_c * 5120) + (i_c_outer * 1280)) + cse_var_18) + cse_var_17) + c_inner_c_3) + 960);
                ((float*)DepthwiseConv2d_global_let)[cse_var_15] = (((float*)DepthwiseConv2d_global_let)[cse_var_15] + (((float*)PaddedInput_global_global_let)[((((((di * 324) + cse_var_18) + cse_var_17) + cse_var_16) + c_inner_c_3) + 972)] * ((float*)fused_constant_3_global_global_let)[((((c_outer_c * 18) + (di * 6)) + cse_var_16) + c_inner_c_3)]));
              }
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 22; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 16; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_19 = (((((ax1 >> 1) * 5120) + (ax2 * 320)) + (ax3 * 2)) + (ax1 & 1));
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_19] + ((float*)fused_nn_conv2d_constant_3_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[(((ax1 * 2560) + (ax2 * 160)) + ax3)] = ((((float*)DepthwiseConv2d_global_let)[cse_var_19] + ((float*)fused_nn_conv2d_constant_3_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_4(float* p0, float* T_multiply, uint8_t* global_const_workspace_10_var, uint8_t* global_workspace_11_var) {
  void* fused_nn_conv2d_constant_4_let = (&(global_const_workspace_10_var[2163504]));
  void* fused_constant_4_let = (&(global_const_workspace_10_var[2128768]));
  void* data_vec_let = (&(global_workspace_11_var[450560]));
  for (int32_t h = 0; h < 16; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 22; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 3520) + (w * 110)) + (ci * 5)) + vw)] = p0[((((ci * 2560) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 11; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 16; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_11_var[675840]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          for (int32_t vc_init = 0; vc_init < 4; ++vc_init) {
            ((float*)conv_let)[((vw_init * 4) + vc_init)] = 0.000000e+00f;
          }
        }
        for (int32_t ci_1 = 0; ci_1 < 22; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            for (int32_t vc = 0; vc < 4; ++vc) {
              int32_t cse_var_1 = ((vw_1 * 4) + vc);
              ((float*)conv_let)[cse_var_1] = (((float*)conv_let)[cse_var_1] + (((float*)data_vec_let)[((((ax2_outer * 3520) + (ax3_outer * 110)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_4_let)[(((ax1_outer * 88) + (ci_1 * 4)) + vc)]));
            }
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          for (int32_t ax1_inner = 0; ax1_inner < 4; ++ax1_inner) {
            int32_t cse_var_3 = ((ax3_inner * 4) + ax1_inner);
            int32_t cse_var_2 = ((ax1_outer * 4) + ax1_inner);
            float v_ = ((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_4_let)[cse_var_2];
            float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
            T_multiply[(((((ax1_outer * 10240) + (ax1_inner * 2560)) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_4_let)[cse_var_2]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_5(float* p0, float* T_multiply, uint8_t* global_const_workspace_12_var, uint8_t* global_workspace_13_var) {
  void* fused_nn_conv2d_constant_5_let = (&(global_const_workspace_12_var[2163328]));
  void* fused_constant_5_let = (&(global_const_workspace_12_var[2140656]));
  void* fused_constant_5_global_global_let = (&(global_workspace_13_var[916672]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 11; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        for (int32_t ax0_inner_c = 0; ax0_inner_c < 4; ++ax0_inner_c) {
          int32_t cse_var_1 = (ax0_outer_c * 36);
          ((float*)fused_constant_5_global_global_let)[(((cse_var_1 + (ax2_c * 12)) + (ax3_c * 4)) + ax0_inner_c)] = ((float*)fused_constant_5_let)[(((cse_var_1 + (ax0_inner_c * 9)) + (ax2_c * 3)) + ax3_c)];
        }
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_13_var[450560]));
  for (int32_t c_outer_c = 0; c_outer_c < 11; ++c_outer_c) {
    for (int32_t i_c_outer = 0; i_c_outer < 4; ++i_c_outer) {
      void* PaddedInput_global_global_let = (&(global_workspace_13_var[901120]));
      for (int32_t ax2_c_1 = 0; ax2_c_1 < 6; ++ax2_c_1) {
        for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
          for (int32_t ax1_inner_c = 0; ax1_inner_c < 4; ++ax1_inner_c) {
            int32_t cse_var_2 = ((i_c_outer * 4) + ax2_c_1);
            ((float*)PaddedInput_global_global_let)[(((ax2_c_1 * 648) + (ax3_c_1 * 4)) + ax1_inner_c)] = (((((1 <= cse_var_2) && (cse_var_2 < 17)) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[((((((c_outer_c * 10240) + (ax1_inner_c * 2560)) + (i_c_outer * 640)) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
          }
        }
      }
      for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
        for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
          for (int32_t c_inner_c_init = 0; c_inner_c_init < 4; ++c_inner_c_init) {
            ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 10240) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init * 4)) + c_inner_c_init)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
          for (int32_t c_inner_c_init_1 = 0; c_inner_c_init_1 < 4; ++c_inner_c_init_1) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 10240) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_1 * 4)) + c_inner_c_init_1) + 640)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
          for (int32_t c_inner_c_init_2 = 0; c_inner_c_init_2 < 4; ++c_inner_c_init_2) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 10240) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_2 * 4)) + c_inner_c_init_2) + 1280)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
          for (int32_t c_inner_c_init_3 = 0; c_inner_c_init_3 < 4; ++c_inner_c_init_3) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 10240) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_3 * 4)) + c_inner_c_init_3) + 1920)] = 0.000000e+00f;
          }
        }
        for (int32_t di = 0; di < 3; ++di) {
          for (int32_t dj = 0; dj < 3; ++dj) {
            for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
              for (int32_t c_inner_c = 0; c_inner_c < 4; ++c_inner_c) {
                int32_t cse_var_6 = (j_c_outer * 8);
                int32_t cse_var_5 = (j_c_inner * 4);
                int32_t cse_var_4 = (dj * 4);
                int32_t cse_var_3 = (((((c_outer_c * 10240) + (i_c_outer * 2560)) + cse_var_6) + cse_var_5) + c_inner_c);
                ((float*)DepthwiseConv2d_global_let)[cse_var_3] = (((float*)DepthwiseConv2d_global_let)[cse_var_3] + (((float*)PaddedInput_global_global_let)[(((((di * 648) + cse_var_6) + cse_var_5) + cse_var_4) + c_inner_c)] * ((float*)fused_constant_5_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_4) + c_inner_c)]));
              }
            }
            for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
              for (int32_t c_inner_c_1 = 0; c_inner_c_1 < 4; ++c_inner_c_1) {
                int32_t cse_var_10 = (j_c_outer * 8);
                int32_t cse_var_9 = (j_c_inner_1 * 4);
                int32_t cse_var_8 = (dj * 4);
                int32_t cse_var_7 = ((((((c_outer_c * 10240) + (i_c_outer * 2560)) + cse_var_10) + cse_var_9) + c_inner_c_1) + 640);
                ((float*)DepthwiseConv2d_global_let)[cse_var_7] = (((float*)DepthwiseConv2d_global_let)[cse_var_7] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_10) + cse_var_9) + cse_var_8) + c_inner_c_1) + 648)] * ((float*)fused_constant_5_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_8) + c_inner_c_1)]));
              }
            }
            for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
              for (int32_t c_inner_c_2 = 0; c_inner_c_2 < 4; ++c_inner_c_2) {
                int32_t cse_var_14 = (j_c_outer * 8);
                int32_t cse_var_13 = (j_c_inner_2 * 4);
                int32_t cse_var_12 = (dj * 4);
                int32_t cse_var_11 = ((((((c_outer_c * 10240) + (i_c_outer * 2560)) + cse_var_14) + cse_var_13) + c_inner_c_2) + 1280);
                ((float*)DepthwiseConv2d_global_let)[cse_var_11] = (((float*)DepthwiseConv2d_global_let)[cse_var_11] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_14) + cse_var_13) + cse_var_12) + c_inner_c_2) + 1296)] * ((float*)fused_constant_5_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_12) + c_inner_c_2)]));
              }
            }
            for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
              for (int32_t c_inner_c_3 = 0; c_inner_c_3 < 4; ++c_inner_c_3) {
                int32_t cse_var_18 = (j_c_outer * 8);
                int32_t cse_var_17 = (j_c_inner_3 * 4);
                int32_t cse_var_16 = (dj * 4);
                int32_t cse_var_15 = ((((((c_outer_c * 10240) + (i_c_outer * 2560)) + cse_var_18) + cse_var_17) + c_inner_c_3) + 1920);
                ((float*)DepthwiseConv2d_global_let)[cse_var_15] = (((float*)DepthwiseConv2d_global_let)[cse_var_15] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_18) + cse_var_17) + cse_var_16) + c_inner_c_3) + 1944)] * ((float*)fused_constant_5_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_16) + c_inner_c_3)]));
              }
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 44; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 16; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_19 = (((((ax1 >> 2) * 10240) + (ax2 * 640)) + (ax3 * 4)) + (ax1 & 3));
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_19] + ((float*)fused_nn_conv2d_constant_5_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[(((ax1 * 2560) + (ax2 * 160)) + ax3)] = ((((float*)DepthwiseConv2d_global_let)[cse_var_19] + ((float*)fused_nn_conv2d_constant_5_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_6(float* p0, float* T_multiply, uint8_t* global_const_workspace_14_var, uint8_t* global_workspace_15_var) {
  void* fused_nn_conv2d_constant_6_let = (&(global_const_workspace_14_var[2163152]));
  void* fused_constant_6_let = (&(global_const_workspace_14_var[2121024]));
  void* data_vec_let = (&(global_workspace_15_var[450560]));
  for (int32_t h = 0; h < 16; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 44; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 7040) + (w * 220)) + (ci * 5)) + vw)] = p0[((((ci * 2560) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 11; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 16; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_15_var[901120]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          for (int32_t vc_init = 0; vc_init < 4; ++vc_init) {
            ((float*)conv_let)[((vw_init * 4) + vc_init)] = 0.000000e+00f;
          }
        }
        for (int32_t ci_1 = 0; ci_1 < 44; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            for (int32_t vc = 0; vc < 4; ++vc) {
              int32_t cse_var_1 = ((vw_1 * 4) + vc);
              ((float*)conv_let)[cse_var_1] = (((float*)conv_let)[cse_var_1] + (((float*)data_vec_let)[((((ax2_outer * 7040) + (ax3_outer * 220)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_6_let)[(((ax1_outer * 176) + (ci_1 * 4)) + vc)]));
            }
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          for (int32_t ax1_inner = 0; ax1_inner < 4; ++ax1_inner) {
            int32_t cse_var_3 = ((ax3_inner * 4) + ax1_inner);
            int32_t cse_var_2 = ((ax1_outer * 4) + ax1_inner);
            float v_ = ((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_6_let)[cse_var_2];
            float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
            T_multiply[(((((ax1_outer * 10240) + (ax1_inner * 2560)) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[cse_var_3] + ((float*)fused_nn_conv2d_constant_6_let)[cse_var_2]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
          }
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_7(float* p0, float* T_multiply, uint8_t* global_const_workspace_16_var, uint8_t* global_workspace_17_var) {
  void* fused_nn_conv2d_constant_7_let = (&(global_const_workspace_16_var[2162976]));
  void* fused_constant_7_let = (&(global_const_workspace_16_var[2139072]));
  void* fused_constant_7_global_global_let = (&(global_workspace_17_var[699168]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 11; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        for (int32_t ax0_inner_c = 0; ax0_inner_c < 4; ++ax0_inner_c) {
          int32_t cse_var_1 = (ax0_outer_c * 36);
          ((float*)fused_constant_7_global_global_let)[(((cse_var_1 + (ax2_c * 12)) + (ax3_c * 4)) + ax0_inner_c)] = ((float*)fused_constant_7_let)[(((cse_var_1 + (ax0_inner_c * 9)) + (ax2_c * 3)) + ax3_c)];
        }
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_17_var[450560]));
  for (int32_t c_outer_c = 0; c_outer_c < 11; ++c_outer_c) {
    for (int32_t i_c_outer = 0; i_c_outer < 2; ++i_c_outer) {
      void* PaddedInput_global_global_let = (&(global_workspace_17_var[675840]));
      for (int32_t ax2_c_1 = 0; ax2_c_1 < 9; ++ax2_c_1) {
        for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
          for (int32_t ax1_inner_c = 0; ax1_inner_c < 4; ++ax1_inner_c) {
            ((float*)PaddedInput_global_global_let)[(((ax2_c_1 * 648) + (ax3_c_1 * 4)) + ax1_inner_c)] = ((((1 <= ((i_c_outer * 8) + ax2_c_1)) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[((((((c_outer_c * 10240) + (ax1_inner_c * 2560)) + (i_c_outer * 1280)) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
          }
        }
      }
      for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
        for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
          for (int32_t c_inner_c_init = 0; c_inner_c_init < 4; ++c_inner_c_init) {
            ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 5120) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init * 4)) + c_inner_c_init)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
          for (int32_t c_inner_c_init_1 = 0; c_inner_c_init_1 < 4; ++c_inner_c_init_1) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_1 * 4)) + c_inner_c_init_1) + 640)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
          for (int32_t c_inner_c_init_2 = 0; c_inner_c_init_2 < 4; ++c_inner_c_init_2) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_2 * 4)) + c_inner_c_init_2) + 1280)] = 0.000000e+00f;
          }
        }
        for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
          for (int32_t c_inner_c_init_3 = 0; c_inner_c_init_3 < 4; ++c_inner_c_init_3) {
            ((float*)DepthwiseConv2d_global_let)[((((((c_outer_c * 5120) + (i_c_outer * 2560)) + (j_c_outer * 8)) + (j_c_inner_init_3 * 4)) + c_inner_c_init_3) + 1920)] = 0.000000e+00f;
          }
        }
        for (int32_t di = 0; di < 3; ++di) {
          for (int32_t dj = 0; dj < 3; ++dj) {
            for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
              for (int32_t c_inner_c = 0; c_inner_c < 4; ++c_inner_c) {
                int32_t cse_var_5 = (j_c_outer * 8);
                int32_t cse_var_4 = (j_c_inner * 4);
                int32_t cse_var_3 = (dj * 4);
                int32_t cse_var_2 = (((((c_outer_c * 5120) + (i_c_outer * 2560)) + cse_var_5) + cse_var_4) + c_inner_c);
                ((float*)DepthwiseConv2d_global_let)[cse_var_2] = (((float*)DepthwiseConv2d_global_let)[cse_var_2] + (((float*)PaddedInput_global_global_let)[(((((di * 648) + cse_var_5) + cse_var_4) + cse_var_3) + c_inner_c)] * ((float*)fused_constant_7_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_3) + c_inner_c)]));
              }
            }
            for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
              for (int32_t c_inner_c_1 = 0; c_inner_c_1 < 4; ++c_inner_c_1) {
                int32_t cse_var_9 = (j_c_outer * 8);
                int32_t cse_var_8 = (j_c_inner_1 * 4);
                int32_t cse_var_7 = (dj * 4);
                int32_t cse_var_6 = ((((((c_outer_c * 5120) + (i_c_outer * 2560)) + cse_var_9) + cse_var_8) + c_inner_c_1) + 640);
                ((float*)DepthwiseConv2d_global_let)[cse_var_6] = (((float*)DepthwiseConv2d_global_let)[cse_var_6] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_9) + cse_var_8) + cse_var_7) + c_inner_c_1) + 1296)] * ((float*)fused_constant_7_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_7) + c_inner_c_1)]));
              }
            }
            for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
              for (int32_t c_inner_c_2 = 0; c_inner_c_2 < 4; ++c_inner_c_2) {
                int32_t cse_var_13 = (j_c_outer * 8);
                int32_t cse_var_12 = (j_c_inner_2 * 4);
                int32_t cse_var_11 = (dj * 4);
                int32_t cse_var_10 = ((((((c_outer_c * 5120) + (i_c_outer * 2560)) + cse_var_13) + cse_var_12) + c_inner_c_2) + 1280);
                ((float*)DepthwiseConv2d_global_let)[cse_var_10] = (((float*)DepthwiseConv2d_global_let)[cse_var_10] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_13) + cse_var_12) + cse_var_11) + c_inner_c_2) + 2592)] * ((float*)fused_constant_7_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_11) + c_inner_c_2)]));
              }
            }
            for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
              for (int32_t c_inner_c_3 = 0; c_inner_c_3 < 4; ++c_inner_c_3) {
                int32_t cse_var_17 = (j_c_outer * 8);
                int32_t cse_var_16 = (j_c_inner_3 * 4);
                int32_t cse_var_15 = (dj * 4);
                int32_t cse_var_14 = ((((((c_outer_c * 5120) + (i_c_outer * 2560)) + cse_var_17) + cse_var_16) + c_inner_c_3) + 1920);
                ((float*)DepthwiseConv2d_global_let)[cse_var_14] = (((float*)DepthwiseConv2d_global_let)[cse_var_14] + (((float*)PaddedInput_global_global_let)[((((((di * 648) + cse_var_17) + cse_var_16) + cse_var_15) + c_inner_c_3) + 3888)] * ((float*)fused_constant_7_global_global_let)[((((c_outer_c * 36) + (di * 12)) + cse_var_15) + c_inner_c_3)]));
              }
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 44; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 8; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_18 = (((((ax1 >> 2) * 5120) + (ax2 * 640)) + (ax3 * 4)) + (ax1 & 3));
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_18] + ((float*)fused_nn_conv2d_constant_7_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[(((ax1 * 1280) + (ax2 * 160)) + ax3)] = ((((float*)DepthwiseConv2d_global_let)[cse_var_18] + ((float*)fused_nn_conv2d_constant_7_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_8(float* p0, float* T_multiply, uint8_t* global_const_workspace_18_var, uint8_t* global_workspace_19_var) {
  void* fused_nn_conv2d_constant_8_let = (&(global_const_workspace_18_var[2161504]));
  void* fused_constant_8_let = (&(global_const_workspace_18_var[2105360]));
  void* data_vec_let = (&(global_workspace_19_var[455680]));
  for (int32_t h = 0; h < 8; ++h) {
    for (int32_t w = 0; w < 32; ++w) {
      for (int32_t ci = 0; ci < 44; ++ci) {
        for (int32_t vw = 0; vw < 5; ++vw) {
          ((float*)data_vec_let)[((((h * 7040) + (w * 220)) + (ci * 5)) + vw)] = p0[((((ci * 1280) + (h * 160)) + (w * 5)) + vw)];
        }
      }
    }
  }
  for (int32_t ax1_outer = 0; ax1_outer < 89; ++ax1_outer) {
    for (int32_t ax2_outer = 0; ax2_outer < 8; ++ax2_outer) {
      for (int32_t ax3_outer = 0; ax3_outer < 32; ++ax3_outer) {
        void* conv_let = (&(global_workspace_19_var[680960]));
        for (int32_t vw_init = 0; vw_init < 5; ++vw_init) {
          ((float*)conv_let)[vw_init] = 0.000000e+00f;
        }
        for (int32_t ci_1 = 0; ci_1 < 44; ++ci_1) {
          for (int32_t vw_1 = 0; vw_1 < 5; ++vw_1) {
            ((float*)conv_let)[vw_1] = (((float*)conv_let)[vw_1] + (((float*)data_vec_let)[((((ax2_outer * 7040) + (ax3_outer * 220)) + (ci_1 * 5)) + vw_1)] * ((float*)fused_constant_8_let)[((ax1_outer * 44) + ci_1)]));
          }
        }
        for (int32_t ax3_inner = 0; ax3_inner < 5; ++ax3_inner) {
          float v_ = ((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_8_let)[ax1_outer];
          float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
          T_multiply[((((ax1_outer * 1280) + (ax2_outer * 160)) + (ax3_outer * 5)) + ax3_inner)] = ((((float*)conv_let)[ax3_inner] + ((float*)fused_nn_conv2d_constant_8_let)[ax1_outer]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_9(float* p0, float* T_multiply, uint8_t* global_const_workspace_20_var, uint8_t* global_workspace_21_var) {
  void* fused_nn_conv2d_constant_9_let = (&(global_const_workspace_20_var[2161136]));
  void* fused_constant_9_let = (&(global_const_workspace_20_var[2132640]));
  void* fused_constant_9_global_global_let = (&(global_workspace_21_var[915248]));
  for (int32_t ax0_outer_c = 0; ax0_outer_c < 89; ++ax0_outer_c) {
    for (int32_t ax2_c = 0; ax2_c < 3; ++ax2_c) {
      for (int32_t ax3_c = 0; ax3_c < 3; ++ax3_c) {
        int32_t cse_var_1 = (((ax0_outer_c * 9) + (ax2_c * 3)) + ax3_c);
        ((float*)fused_constant_9_global_global_let)[cse_var_1] = ((float*)fused_constant_9_let)[cse_var_1];
      }
    }
  }
  void* DepthwiseConv2d_global_let = (&(global_workspace_21_var[455680]));
  for (int32_t c_outer_c = 0; c_outer_c < 89; ++c_outer_c) {
    for (int32_t i_c_outer = 0; i_c_outer < 2; ++i_c_outer) {
      void* PaddedInput_global_global_let = (&(global_workspace_21_var[911360]));
      for (int32_t ax2_c_1 = 0; ax2_c_1 < 6; ++ax2_c_1) {
        for (int32_t ax3_c_1 = 0; ax3_c_1 < 162; ++ax3_c_1) {
          int32_t cse_var_2 = ((i_c_outer * 4) + ax2_c_1);
          ((float*)PaddedInput_global_global_let)[((ax2_c_1 * 162) + ax3_c_1)] = (((((1 <= cse_var_2) && (cse_var_2 < 9)) && (1 <= ax3_c_1)) && (ax3_c_1 < 161)) ? p0[(((((c_outer_c * 1280) + (i_c_outer * 640)) + (ax2_c_1 * 160)) + ax3_c_1) - 161)] : 0.000000e+00f);
        }
      }
      for (int32_t j_c_outer = 0; j_c_outer < 80; ++j_c_outer) {
        for (int32_t j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
          ((float*)DepthwiseConv2d_global_let)[((((c_outer_c * 1280) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_1 = 0; j_c_inner_init_1 < 2; ++j_c_inner_init_1) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 1280) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_1) + 160)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_2 = 0; j_c_inner_init_2 < 2; ++j_c_inner_init_2) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 1280) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_2) + 320)] = 0.000000e+00f;
        }
        for (int32_t j_c_inner_init_3 = 0; j_c_inner_init_3 < 2; ++j_c_inner_init_3) {
          ((float*)DepthwiseConv2d_global_let)[(((((c_outer_c * 1280) + (i_c_outer * 640)) + (j_c_outer * 2)) + j_c_inner_init_3) + 480)] = 0.000000e+00f;
        }
        for (int32_t di = 0; di < 3; ++di) {
          for (int32_t dj = 0; dj < 3; ++dj) {
            for (int32_t j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
              int32_t cse_var_4 = (j_c_outer * 2);
              int32_t cse_var_3 = ((((c_outer_c * 1280) + (i_c_outer * 640)) + cse_var_4) + j_c_inner);
              ((float*)DepthwiseConv2d_global_let)[cse_var_3] = (((float*)DepthwiseConv2d_global_let)[cse_var_3] + (((float*)PaddedInput_global_global_let)[((((di * 162) + cse_var_4) + j_c_inner) + dj)] * ((float*)fused_constant_9_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_1 = 0; j_c_inner_1 < 2; ++j_c_inner_1) {
              int32_t cse_var_6 = (j_c_outer * 2);
              int32_t cse_var_5 = (((((c_outer_c * 1280) + (i_c_outer * 640)) + cse_var_6) + j_c_inner_1) + 160);
              ((float*)DepthwiseConv2d_global_let)[cse_var_5] = (((float*)DepthwiseConv2d_global_let)[cse_var_5] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_6) + j_c_inner_1) + dj) + 162)] * ((float*)fused_constant_9_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_2 = 0; j_c_inner_2 < 2; ++j_c_inner_2) {
              int32_t cse_var_8 = (j_c_outer * 2);
              int32_t cse_var_7 = (((((c_outer_c * 1280) + (i_c_outer * 640)) + cse_var_8) + j_c_inner_2) + 320);
              ((float*)DepthwiseConv2d_global_let)[cse_var_7] = (((float*)DepthwiseConv2d_global_let)[cse_var_7] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_8) + j_c_inner_2) + dj) + 324)] * ((float*)fused_constant_9_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
            for (int32_t j_c_inner_3 = 0; j_c_inner_3 < 2; ++j_c_inner_3) {
              int32_t cse_var_10 = (j_c_outer * 2);
              int32_t cse_var_9 = (((((c_outer_c * 1280) + (i_c_outer * 640)) + cse_var_10) + j_c_inner_3) + 480);
              ((float*)DepthwiseConv2d_global_let)[cse_var_9] = (((float*)DepthwiseConv2d_global_let)[cse_var_9] + (((float*)PaddedInput_global_global_let)[(((((di * 162) + cse_var_10) + j_c_inner_3) + dj) + 486)] * ((float*)fused_constant_9_global_global_let)[(((c_outer_c * 9) + (di * 3)) + dj)]));
            }
          }
        }
      }
    }
  }
  for (int32_t ax1 = 0; ax1 < 89; ++ax1) {
    for (int32_t ax2 = 0; ax2 < 8; ++ax2) {
      for (int32_t ax3 = 0; ax3 < 160; ++ax3) {
        int32_t cse_var_11 = (((ax1 * 1280) + (ax2 * 160)) + ax3);
        float v_ = ((float*)DepthwiseConv2d_global_let)[cse_var_11] + ((float*)fused_nn_conv2d_constant_9_let)[ax1];
        float v__1 = (v_) < (3.000000e+00f) ? (v_) : (3.000000e+00f);
        T_multiply[cse_var_11] = ((((float*)DepthwiseConv2d_global_let)[cse_var_11] + ((float*)fused_nn_conv2d_constant_9_let)[ax1]) * ((((v__1) > (-3.000000e+00f) ? (v__1) : (-3.000000e+00f)) * 1.666667e-01f) + 5.000000e-01f));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_nn_relu(float* p0, float* T_relu, uint8_t* global_const_workspace_52_var, uint8_t* global_workspace_53_var) {
  void* fused_nn_conv2d_constant_24_let = (&(global_const_workspace_52_var[2163680]));
  void* fused_constant_24_let = (&(global_const_workspace_52_var[1966432]));
  void* data_vec_let = (&(global_workspace_53_var[229120]));
  for (int32_t ci = 0; ci < 179; ++ci) {
    ((float*)data_vec_let)[ci] = p0[ci];
  }
  for (int32_t ax1_outer = 0; ax1_outer < 11; ++ax1_outer) {
    void* conv_let = (&(global_workspace_53_var[230016]));
    for (int32_t vc_init = 0; vc_init < 4; ++vc_init) {
      ((float*)conv_let)[vc_init] = 0.000000e+00f;
    }
    for (int32_t ci_1 = 0; ci_1 < 179; ++ci_1) {
      for (int32_t vc = 0; vc < 4; ++vc) {
        ((float*)conv_let)[vc] = (((float*)conv_let)[vc] + (((float*)data_vec_let)[ci_1] * ((float*)fused_constant_24_let)[(((ax1_outer * 716) + (ci_1 * 4)) + vc)]));
      }
    }
    for (int32_t ax1_inner = 0; ax1_inner < 4; ++ax1_inner) {
      int32_t cse_var_1 = ((ax1_outer * 4) + ax1_inner);
      float v_ = ((float*)conv_let)[ax1_inner] + ((float*)fused_nn_conv2d_constant_24_let)[cse_var_1];
      T_relu[cse_var_1] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_conv2d_add_nn_relu_1(float* p0, float* T_relu, uint8_t* global_const_workspace_64_var, uint8_t* global_workspace_65_var) {
  void* fused_nn_conv2d_constant_28_let = (&(global_const_workspace_64_var[2161872]));
  void* fused_constant_28_let = (&(global_const_workspace_64_var[1676240]));
  void* data_vec_let = (&(global_workspace_65_var[0]));
  for (int32_t ci = 0; ci < 358; ++ci) {
    ((float*)data_vec_let)[ci] = p0[ci];
  }
  for (int32_t ax1_outer = 0; ax1_outer < 89; ++ax1_outer) {
    void* conv_let = (&(global_workspace_65_var[1808]));
    ((float*)conv_let)[0] = 0.000000e+00f;
    for (int32_t ci_1 = 0; ci_1 < 358; ++ci_1) {
      ((float*)conv_let)[0] = (((float*)conv_let)[0] + (((float*)data_vec_let)[ci_1] * ((float*)fused_constant_28_let)[((ax1_outer * 358) + ci_1)]));
    }
    float v_ = ((float*)conv_let)[0] + ((float*)fused_nn_conv2d_constant_28_let)[ax1_outer];
    T_relu[ax1_outer] = ((v_) > (0.000000e+00f) ? (v_) : (0.000000e+00f));
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_dense(float* p0, float* T_matmul_NT, uint8_t* global_const_workspace_76_var, uint8_t* global_workspace_77_var) {
  void* fused_constant_31_let = (&(global_const_workspace_76_var[768992]));
  for (int32_t i = 0; i < 80; ++i) {
    for (int32_t j = 0; j < 97; ++j) {
      T_matmul_NT[((i * 97) + j)] = 0.000000e+00f;
      for (int32_t k = 0; k < 358; ++k) {
        int32_t cse_var_1 = ((i * 97) + j);
        T_matmul_NT[cse_var_1] = (T_matmul_NT[cse_var_1] + (p0[((i * 358) + k)] * ((float*)fused_constant_31_let)[((j * 358) + k)]));
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_nn_max_pool2d(float* p0, float* pool_max, uint8_t* global_const_workspace_72_var, uint8_t* global_workspace_73_var) {
  for (int32_t ax1 = 0; ax1 < 358; ++ax1) {
    for (int32_t ax3 = 0; ax3 < 80; ++ax3) {
      pool_max[((ax1 * 80) + ax3)] = -3.402823e+38f;
      for (int32_t rv0 = 0; rv0 < 2; ++rv0) {
        for (int32_t rv1 = 0; rv1 < 2; ++rv1) {
          int32_t cse_var_1 = ((ax1 * 80) + ax3);
          float v_ = pool_max[cse_var_1];
          float v__1 = p0[((((ax1 * 320) + (rv0 * 160)) + (ax3 * 2)) + rv1)];
          pool_max[cse_var_1] = ((v_) > (v__1) ? (v_) : (v__1));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_reshape_add(float* p0, float* T_add, uint8_t* global_const_workspace_78_var, uint8_t* global_workspace_79_var) {
  void* fused_reshape_constant_let = (&(global_const_workspace_78_var[2160736]));
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 80; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 25; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 4; ++ax2_inner) {
        if (((ax2_outer * 4) + ax2_inner) < 97) {
          int32_t cse_var_2 = (ax2_outer * 4);
          int32_t cse_var_1 = (((ax0_ax1_fused * 97) + cse_var_2) + ax2_inner);
          T_add[cse_var_1] = (p0[cse_var_1] + ((float*)fused_reshape_constant_let)[(cse_var_2 + ax2_inner)]);
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_squeeze_expand_dims_multiply_layout_transform(float* p0, float* T_layout_trans, uint8_t* global_const_workspace_56_var, uint8_t* global_workspace_57_var) {
  void* fused_constant_26_let = (&(global_const_workspace_56_var[512656]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 32041; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax4_inner = 0; ax4_inner < 2; ++ax4_inner) {
      int32_t cse_var_1 = (ax0_ax1_fused_ax2_fused % 179);
      T_layout_trans[((ax0_ax1_fused_ax2_fused * 2) + ax4_inner)] = (((float*)fused_constant_26_let)[((((ax0_ax1_fused_ax2_fused / 179) * 358) + (ax4_inner * 179)) + cse_var_1)] * p0[cse_var_1]);
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_squeeze_expand_dims_multiply_layout_transform_1(float* p0, float* T_layout_trans, uint8_t* global_const_workspace_68_var, uint8_t* global_workspace_69_var) {
  void* fused_constant_30_let = (&(global_const_workspace_68_var[0]));
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 64082; ++ax0_ax1_fused_ax2_fused) {
    for (int32_t ax4_inner = 0; ax4_inner < 2; ++ax4_inner) {
      int32_t cse_var_1 = (ax0_ax1_fused_ax2_fused % 358);
      T_layout_trans[((ax0_ax1_fused_ax2_fused * 2) + ax4_inner)] = (((float*)fused_constant_30_let)[((((ax0_ax1_fused_ax2_fused / 358) * 716) + (ax4_inner * 358)) + cse_var_1)] * p0[cse_var_1]);
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_squeeze_transpose_reshape(float* p0, float* T_reshape, uint8_t* global_const_workspace_74_var, uint8_t* global_workspace_75_var) {
  for (int32_t ax0 = 0; ax0 < 80; ++ax0) {
    for (int32_t ax1_outer = 0; ax1_outer < 90; ++ax1_outer) {
      for (int32_t ax1_inner = 0; ax1_inner < 4; ++ax1_inner) {
        if (((ax1_outer * 2) + (ax1_inner >> 1)) < 179) {
          T_reshape[(((ax0 * 358) + (ax1_outer * 4)) + ax1_inner)] = p0[(((ax1_outer * 320) + (ax1_inner * 80)) + ax0)];
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_subtract_exp(float* p0, float* p1, float* T_exp, uint8_t* global_const_workspace_82_var, uint8_t* global_workspace_83_var) {
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 80; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 25; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 4; ++ax2_inner) {
        if (((ax2_outer * 4) + ax2_inner) < 97) {
          int32_t cse_var_1 = (((ax0_ax1_fused * 97) + (ax2_outer * 4)) + ax2_inner);
          T_exp[cse_var_1] = expf((p0[cse_var_1] - p1[ax0_ax1_fused]));
        }
      }
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec_fused_sum(float* p0, float* p0_red, uint8_t* global_const_workspace_84_var, uint8_t* global_workspace_85_var) {
  for (int32_t ax0_ax1_fused_ax2_fused = 0; ax0_ax1_fused_ax2_fused < 80; ++ax0_ax1_fused_ax2_fused) {
    p0_red[ax0_ax1_fused_ax2_fused] = 0.000000e+00f;
    for (int32_t k2 = 0; k2 < 97; ++k2) {
      p0_red[ax0_ax1_fused_ax2_fused] = (p0_red[ax0_ax1_fused_ax2_fused] + p0[((ax0_ax1_fused_ax2_fused * 97) + k2)]);
    }
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_rec___tvm_main__(float* x_buffer_var, float* output_buffer_var, uint8_t* global_const_workspace_0_var, uint8_t* global_workspace_1_var) {
  void* sid_28_let = (&(global_workspace_1_var[458240]));
  void* sid_23_let = (&(global_workspace_1_var[0]));
  void* sid_20_let = (&(global_workspace_1_var[0]));
  void* sid_17_let = (&(global_workspace_1_var[0]));
  void* sid_26_let = (&(global_workspace_1_var[229840]));
  void* sid_6_let = (&(global_workspace_1_var[0]));
  void* sid_21_let = (&(global_workspace_1_var[0]));
  void* sid_5_let = (&(global_workspace_1_var[0]));
  void* sid_2_let = (&(global_workspace_1_var[112640]));
  void* sid_19_let = (&(global_workspace_1_var[0]));
  void* sid_18_let = (&(global_workspace_1_var[0]));
  void* sid_16_let = (&(global_workspace_1_var[0]));
  void* sid_22_let = (&(global_workspace_1_var[0]));
  void* sid_1_let = (&(global_workspace_1_var[202752]));
  void* sid_4_let = (&(global_workspace_1_var[0]));
  void* sid_7_let = (&(global_workspace_1_var[0]));
  void* sid_8_let = (&(global_workspace_1_var[0]));
  void* sid_29_let = (&(global_workspace_1_var[0]));
  void* sid_15_let = (&(global_workspace_1_var[0]));
  void* sid_3_let = (&(global_workspace_1_var[0]));
  void* sid_9_let = (&(global_workspace_1_var[0]));
  void* sid_27_let = (&(global_workspace_1_var[229120]));
  void* sid_10_let = (&(global_workspace_1_var[0]));
  void* sid_25_let = (&(global_workspace_1_var[229840]));
  void* sid_11_let = (&(global_workspace_1_var[0]));
  void* sid_12_let = (&(global_workspace_1_var[0]));
  void* sid_13_let = (&(global_workspace_1_var[0]));
  void* sid_24_let = (&(global_workspace_1_var[0]));
  void* sid_14_let = (&(global_workspace_1_var[0]));
  void* sid_30_let = (&(global_workspace_1_var[512656]));
  void* sid_31_let = (&(global_workspace_1_var[1440]));
  void* sid_32_let = (&(global_workspace_1_var[1440]));
  void* sid_33_let = (&(global_workspace_1_var[970896]));
  void* sid_34_let = (&(global_workspace_1_var[0]));
  void* sid_35_let = (&(global_workspace_1_var[512656]));
  void* sid_36_let = (&(global_workspace_1_var[114560]));
  void* sid_37_let = (&(global_workspace_1_var[0]));
  void* sid_38_let = (&(global_workspace_1_var[114560]));
  void* sid_39_let = (&(global_workspace_1_var[31040]));
  void* sid_40_let = (&(global_workspace_1_var[62080]));
  void* sid_41_let = (&(global_workspace_1_var[0]));
  void* sid_42_let = (&(global_workspace_1_var[31040]));
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply(x_buffer_var, sid_1_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_1(sid_1_let, sid_2_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_2(sid_2_let, sid_3_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_3(sid_3_let, sid_4_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_4(sid_4_let, sid_5_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_5(sid_5_let, sid_6_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_6(sid_6_let, sid_7_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_7(sid_7_let, sid_8_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_8(sid_8_let, sid_9_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_9(sid_9_let, sid_10_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_10(sid_10_let, sid_11_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_11(sid_11_let, sid_12_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_12(sid_12_let, sid_13_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_13(sid_13_let, sid_14_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_14(sid_14_let, sid_15_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_15(sid_15_let, sid_16_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_16(sid_16_let, sid_17_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_17(sid_17_let, sid_18_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_18(sid_18_let, sid_19_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_19(sid_19_let, sid_20_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_20(sid_20_let, sid_21_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_21(sid_21_let, sid_22_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_22(sid_22_let, sid_23_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_23(sid_23_let, sid_24_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_adaptive_avg_pool2d(sid_24_let, sid_25_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_nn_relu(sid_25_let, sid_26_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip(sid_26_let, sid_27_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_squeeze_expand_dims_multiply_layout_transform(sid_27_let, sid_28_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_24(sid_24_let, sid_28_let, sid_29_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_25(sid_29_let, sid_30_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_adaptive_avg_pool2d_1(sid_30_let, sid_31_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_nn_relu_1(sid_31_let, sid_32_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_1(sid_32_let, sid_33_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_squeeze_expand_dims_multiply_layout_transform_1(sid_33_let, sid_34_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_conv2d_add_clip_divide_add_multiply_26(sid_30_let, sid_34_let, sid_35_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_max_pool2d(sid_35_let, sid_36_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_squeeze_transpose_reshape(sid_36_let, sid_37_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_nn_dense(sid_37_let, sid_38_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_reshape_add(sid_38_let, sid_39_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_max(sid_39_let, sid_40_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_subtract_exp(sid_39_let, sid_40_let, sid_41_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_sum(sid_41_let, sid_42_let, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  if (tvmgen_rec_fused_divide(sid_41_let, sid_42_let, output_buffer_var, global_const_workspace_0_var, global_workspace_1_var) != 0 ) return -1;
  return 0;
}

