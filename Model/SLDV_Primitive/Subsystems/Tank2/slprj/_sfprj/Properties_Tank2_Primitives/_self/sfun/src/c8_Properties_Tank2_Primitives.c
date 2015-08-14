/* Include files */

#include "blascompat32.h"
#include "Properties_Tank2_Primitives_sfun.h"
#include "c8_Properties_Tank2_Primitives.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Properties_Tank2_Primitives_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[32] = { "tank_height_m",
  "current_volume_m3", "previous_volume_m3", "net_flow_m3dt", "initial_height_m",
  "nargin", "nargout", "previous_height_m", "valve_flow_rate_m3dt",
  "tank_cross_section_area_m2", "p_valve_flow_rate_m3dt",
  "e_valve_flow_rate_m3dt", "max_vol_m3", "current_height_m", "time", "a1", "a2",
  "a3", "a4", "a5", "a6", "a7", "g1", "g2", "g3", "g4", "g5", "g6", "g7", "g8",
  "pre_max_vol_m3", "pre_tank_cross_section_area_m2" };

static const char * c8_b_debug_family_names[5] = { "nargin", "nargout", "a", "b",
  "c" };

static const char * c8_c_debug_family_names[9] = { "UnderThisCondition",
  "ResultShouldBe", "nargin", "nargout", "initial_height_m", "previous_height_m",
  "time", "tank_cross_section_area_m2", "result" };

static const char * c8_d_debug_family_names[8] = { "UnderThisCondition",
  "ResultShouldBe", "nargin", "nargout", "current_volume_m3", "net_flow_m3dt",
  "tank_volume_m3", "result" };

static const char * c8_e_debug_family_names[7] = { "UnderThisCondition",
  "ResultShouldBe", "nargin", "nargout", "current_volume_m3", "net_flow_m3dt",
  "result" };

static const char * c8_f_debug_family_names[9] = { "UnderThisCondition",
  "ResultShouldBe", "nargin", "nargout", "current_volume_m3", "net_flow_m3dt",
  "tank_volume_m3", "previous_volume_m3", "result" };

static const char * c8_g_debug_family_names[5] = { "nargin", "nargout",
  "current_height_m", "tank_height_m", "result" };

static const char * c8_h_debug_family_names[6] = { "nargin", "nargout",
  "current_height_m", "current_volume_m3", "tank_cross_section_area_m2",
  "result" };

static const char * c8_i_debug_family_names[6] = { "nargin", "nargout",
  "tank_height_m", "tank_volume_m3", "tank_cross_section_area_m2", "result" };

/* Function Declarations */
static void initialize_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void initialize_params_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void enable_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void disable_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void set_sim_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_st);
static void finalize_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void sf_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void c8_chartstep_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void initSimStructsc8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real_T c8_emlrt_marshallIn(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance, const mxArray *c8_b_pre_tank_cross_section_area_m2, const
  char_T *c8_identifier);
static real_T c8_b_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_b_pre_max_vol_m3, const char_T *c8_identifier);
static real_T c8_d_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static boolean_T c8_e_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_g8, const char_T *c8_identifier);
static boolean_T c8_f_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_g_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static boolean_T c8_implies(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance, boolean_T c8_a, boolean_T c8_b);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_h_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_i_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_b_is_active_c8_Properties_Tank2_Primitives, const char_T *c8_identifier);
static uint8_T c8_j_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_pre_max_vol_m3_not_empty = FALSE;
  chartInstance->c8_pre_tank_cross_section_area_m2_not_empty = FALSE;
  chartInstance->c8_is_active_c8_Properties_Tank2_Primitives = 0U;
}

static void initialize_params_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
}

static void enable_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  boolean_T c8_hoistedGlobal;
  boolean_T c8_u;
  const mxArray *c8_b_y = NULL;
  boolean_T c8_b_hoistedGlobal;
  boolean_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  boolean_T c8_c_hoistedGlobal;
  boolean_T c8_c_u;
  const mxArray *c8_d_y = NULL;
  boolean_T c8_d_hoistedGlobal;
  boolean_T c8_d_u;
  const mxArray *c8_e_y = NULL;
  boolean_T c8_e_hoistedGlobal;
  boolean_T c8_e_u;
  const mxArray *c8_f_y = NULL;
  boolean_T c8_f_hoistedGlobal;
  boolean_T c8_f_u;
  const mxArray *c8_g_y = NULL;
  boolean_T c8_g_hoistedGlobal;
  boolean_T c8_g_u;
  const mxArray *c8_h_y = NULL;
  boolean_T c8_h_hoistedGlobal;
  boolean_T c8_h_u;
  const mxArray *c8_i_y = NULL;
  boolean_T c8_i_hoistedGlobal;
  boolean_T c8_i_u;
  const mxArray *c8_j_y = NULL;
  boolean_T c8_j_hoistedGlobal;
  boolean_T c8_j_u;
  const mxArray *c8_k_y = NULL;
  boolean_T c8_k_hoistedGlobal;
  boolean_T c8_k_u;
  const mxArray *c8_l_y = NULL;
  boolean_T c8_l_hoistedGlobal;
  boolean_T c8_l_u;
  const mxArray *c8_m_y = NULL;
  boolean_T c8_m_hoistedGlobal;
  boolean_T c8_m_u;
  const mxArray *c8_n_y = NULL;
  boolean_T c8_n_hoistedGlobal;
  boolean_T c8_n_u;
  const mxArray *c8_o_y = NULL;
  boolean_T c8_o_hoistedGlobal;
  boolean_T c8_o_u;
  const mxArray *c8_p_y = NULL;
  real_T c8_p_hoistedGlobal;
  real_T c8_p_u;
  const mxArray *c8_q_y = NULL;
  real_T c8_q_hoistedGlobal;
  real_T c8_q_u;
  const mxArray *c8_r_y = NULL;
  uint8_T c8_r_hoistedGlobal;
  uint8_T c8_r_u;
  const mxArray *c8_s_y = NULL;
  boolean_T *c8_a1;
  boolean_T *c8_a2;
  boolean_T *c8_a3;
  boolean_T *c8_a4;
  boolean_T *c8_a5;
  boolean_T *c8_a6;
  boolean_T *c8_a7;
  boolean_T *c8_g1;
  boolean_T *c8_g2;
  boolean_T *c8_g3;
  boolean_T *c8_g4;
  boolean_T *c8_g5;
  boolean_T *c8_g6;
  boolean_T *c8_g7;
  boolean_T *c8_g8;
  c8_g8 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c8_g7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c8_g6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c8_g5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c8_g4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c8_g3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c8_g2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c8_g1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c8_a7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_a6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(18), FALSE);
  c8_hoistedGlobal = *c8_a1;
  c8_u = c8_hoistedGlobal;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = *c8_a2;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  c8_c_hoistedGlobal = *c8_a3;
  c8_c_u = c8_c_hoistedGlobal;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_c_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 2, c8_d_y);
  c8_d_hoistedGlobal = *c8_a4;
  c8_d_u = c8_d_hoistedGlobal;
  c8_e_y = NULL;
  sf_mex_assign(&c8_e_y, sf_mex_create("y", &c8_d_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 3, c8_e_y);
  c8_e_hoistedGlobal = *c8_a5;
  c8_e_u = c8_e_hoistedGlobal;
  c8_f_y = NULL;
  sf_mex_assign(&c8_f_y, sf_mex_create("y", &c8_e_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 4, c8_f_y);
  c8_f_hoistedGlobal = *c8_a6;
  c8_f_u = c8_f_hoistedGlobal;
  c8_g_y = NULL;
  sf_mex_assign(&c8_g_y, sf_mex_create("y", &c8_f_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 5, c8_g_y);
  c8_g_hoistedGlobal = *c8_a7;
  c8_g_u = c8_g_hoistedGlobal;
  c8_h_y = NULL;
  sf_mex_assign(&c8_h_y, sf_mex_create("y", &c8_g_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 6, c8_h_y);
  c8_h_hoistedGlobal = *c8_g1;
  c8_h_u = c8_h_hoistedGlobal;
  c8_i_y = NULL;
  sf_mex_assign(&c8_i_y, sf_mex_create("y", &c8_h_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 7, c8_i_y);
  c8_i_hoistedGlobal = *c8_g2;
  c8_i_u = c8_i_hoistedGlobal;
  c8_j_y = NULL;
  sf_mex_assign(&c8_j_y, sf_mex_create("y", &c8_i_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 8, c8_j_y);
  c8_j_hoistedGlobal = *c8_g3;
  c8_j_u = c8_j_hoistedGlobal;
  c8_k_y = NULL;
  sf_mex_assign(&c8_k_y, sf_mex_create("y", &c8_j_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 9, c8_k_y);
  c8_k_hoistedGlobal = *c8_g4;
  c8_k_u = c8_k_hoistedGlobal;
  c8_l_y = NULL;
  sf_mex_assign(&c8_l_y, sf_mex_create("y", &c8_k_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 10, c8_l_y);
  c8_l_hoistedGlobal = *c8_g5;
  c8_l_u = c8_l_hoistedGlobal;
  c8_m_y = NULL;
  sf_mex_assign(&c8_m_y, sf_mex_create("y", &c8_l_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 11, c8_m_y);
  c8_m_hoistedGlobal = *c8_g6;
  c8_m_u = c8_m_hoistedGlobal;
  c8_n_y = NULL;
  sf_mex_assign(&c8_n_y, sf_mex_create("y", &c8_m_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 12, c8_n_y);
  c8_n_hoistedGlobal = *c8_g7;
  c8_n_u = c8_n_hoistedGlobal;
  c8_o_y = NULL;
  sf_mex_assign(&c8_o_y, sf_mex_create("y", &c8_n_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 13, c8_o_y);
  c8_o_hoistedGlobal = *c8_g8;
  c8_o_u = c8_o_hoistedGlobal;
  c8_p_y = NULL;
  sf_mex_assign(&c8_p_y, sf_mex_create("y", &c8_o_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 14, c8_p_y);
  c8_p_hoistedGlobal = chartInstance->c8_pre_max_vol_m3;
  c8_p_u = c8_p_hoistedGlobal;
  c8_q_y = NULL;
  if (!chartInstance->c8_pre_max_vol_m3_not_empty) {
    sf_mex_assign(&c8_q_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c8_q_y, sf_mex_create("y", &c8_p_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c8_y, 15, c8_q_y);
  c8_q_hoistedGlobal = chartInstance->c8_pre_tank_cross_section_area_m2;
  c8_q_u = c8_q_hoistedGlobal;
  c8_r_y = NULL;
  if (!chartInstance->c8_pre_tank_cross_section_area_m2_not_empty) {
    sf_mex_assign(&c8_r_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c8_r_y, sf_mex_create("y", &c8_q_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c8_y, 16, c8_r_y);
  c8_r_hoistedGlobal =
    chartInstance->c8_is_active_c8_Properties_Tank2_Primitives;
  c8_r_u = c8_r_hoistedGlobal;
  c8_s_y = NULL;
  sf_mex_assign(&c8_s_y, sf_mex_create("y", &c8_r_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 17, c8_s_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_st)
{
  const mxArray *c8_u;
  boolean_T *c8_a1;
  boolean_T *c8_a2;
  boolean_T *c8_a3;
  boolean_T *c8_a4;
  boolean_T *c8_a5;
  boolean_T *c8_a6;
  boolean_T *c8_a7;
  boolean_T *c8_g1;
  boolean_T *c8_g2;
  boolean_T *c8_g3;
  boolean_T *c8_g4;
  boolean_T *c8_g5;
  boolean_T *c8_g6;
  boolean_T *c8_g7;
  boolean_T *c8_g8;
  c8_g8 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c8_g7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c8_g6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c8_g5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c8_g4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c8_g3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c8_g2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c8_g1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c8_a7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_a6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  *c8_a1 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    0)), "a1");
  *c8_a2 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    1)), "a2");
  *c8_a3 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    2)), "a3");
  *c8_a4 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    3)), "a4");
  *c8_a5 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    4)), "a5");
  *c8_a6 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    5)), "a6");
  *c8_a7 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    6)), "a7");
  *c8_g1 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    7)), "g1");
  *c8_g2 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    8)), "g2");
  *c8_g3 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    9)), "g3");
  *c8_g4 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    10)), "g4");
  *c8_g5 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    11)), "g5");
  *c8_g6 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    12)), "g6");
  *c8_g7 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    13)), "g7");
  *c8_g8 = c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u,
    14)), "g8");
  chartInstance->c8_pre_max_vol_m3 = c8_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c8_u, 15)), "pre_max_vol_m3");
  chartInstance->c8_pre_tank_cross_section_area_m2 = c8_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 16)),
     "pre_tank_cross_section_area_m2");
  chartInstance->c8_is_active_c8_Properties_Tank2_Primitives =
    c8_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 17)),
    "is_active_c8_Properties_Tank2_Primitives");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_Properties_Tank2_Primitives(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
}

static void sf_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  boolean_T *c8_a1;
  boolean_T *c8_a2;
  boolean_T *c8_a3;
  boolean_T *c8_a4;
  boolean_T *c8_a5;
  boolean_T *c8_a6;
  boolean_T *c8_a7;
  real_T *c8_previous_height_m;
  real_T *c8_valve_flow_rate_m3dt;
  real_T *c8_tank_cross_section_area_m2;
  real_T *c8_p_valve_flow_rate_m3dt;
  real_T *c8_e_valve_flow_rate_m3dt;
  real_T *c8_max_vol_m3;
  boolean_T *c8_g1;
  real_T *c8_current_height_m;
  real_T *c8_time;
  boolean_T *c8_g2;
  boolean_T *c8_g3;
  boolean_T *c8_g4;
  boolean_T *c8_g5;
  boolean_T *c8_g6;
  boolean_T *c8_g7;
  boolean_T *c8_g8;
  c8_g8 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c8_g7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c8_g6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c8_g5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c8_g4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c8_g3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c8_g2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c8_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c8_current_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c8_g1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c8_max_vol_m3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c8_e_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c8_p_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c8_tank_cross_section_area_m2 = (real_T *)ssGetInputPortSignal
    (chartInstance->S, 2);
  c8_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_previous_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_a7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_a6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_a5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_a4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_a3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_a2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_a1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a1, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a2, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a3, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a4, 3U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a5, 4U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a6, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_a7, 6U);
  _SFD_DATA_RANGE_CHECK(*c8_previous_height_m, 7U);
  _SFD_DATA_RANGE_CHECK(*c8_valve_flow_rate_m3dt, 8U);
  _SFD_DATA_RANGE_CHECK(*c8_tank_cross_section_area_m2, 9U);
  _SFD_DATA_RANGE_CHECK(*c8_p_valve_flow_rate_m3dt, 10U);
  _SFD_DATA_RANGE_CHECK(*c8_e_valve_flow_rate_m3dt, 11U);
  _SFD_DATA_RANGE_CHECK(*c8_max_vol_m3, 12U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g1, 13U);
  _SFD_DATA_RANGE_CHECK(*c8_current_height_m, 14U);
  _SFD_DATA_RANGE_CHECK(*c8_time, 15U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g2, 16U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g3, 17U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g4, 18U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g5, 19U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g6, 20U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g7, 21U);
  _SFD_DATA_RANGE_CHECK((real_T)*c8_g8, 22U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_Properties_Tank2_Primitives(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_Properties_Tank2_PrimitivesMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c8_chartstep_c8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  real_T c8_c_hoistedGlobal;
  real_T c8_d_hoistedGlobal;
  real_T c8_e_hoistedGlobal;
  real_T c8_f_hoistedGlobal;
  real_T c8_g_hoistedGlobal;
  real_T c8_h_hoistedGlobal;
  real_T c8_previous_height_m;
  real_T c8_valve_flow_rate_m3dt;
  real_T c8_tank_cross_section_area_m2;
  real_T c8_p_valve_flow_rate_m3dt;
  real_T c8_e_valve_flow_rate_m3dt;
  real_T c8_max_vol_m3;
  real_T c8_current_height_m;
  real_T c8_time;
  uint32_T c8_debug_family_var_map[32];
  real_T c8_tank_height_m;
  real_T c8_current_volume_m3;
  real_T c8_previous_volume_m3;
  real_T c8_net_flow_m3dt;
  real_T c8_initial_height_m;
  real_T c8_nargin = 8.0;
  real_T c8_nargout = 15.0;
  boolean_T c8_a1;
  boolean_T c8_a2;
  boolean_T c8_a3;
  boolean_T c8_a4;
  boolean_T c8_a5;
  boolean_T c8_a6;
  boolean_T c8_a7;
  boolean_T c8_g1;
  boolean_T c8_g2;
  boolean_T c8_g3;
  boolean_T c8_g4;
  boolean_T c8_g5;
  boolean_T c8_g6;
  boolean_T c8_g7;
  boolean_T c8_g8;
  real_T c8_A;
  real_T c8_B;
  real_T c8_x;
  real_T c8_y;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_a;
  real_T c8_b;
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_b_initial_height_m;
  real_T c8_b_previous_height_m;
  real_T c8_b_time;
  real_T c8_b_tank_cross_section_area_m2;
  uint32_T c8_b_debug_family_var_map[9];
  boolean_T c8_UnderThisCondition;
  boolean_T c8_ResultShouldBe;
  real_T c8_b_nargin = 4.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_c_y;
  real_T c8_d_a;
  real_T c8_d_b;
  real_T c8_d_y;
  real_T c8_b_current_volume_m3;
  real_T c8_b_net_flow_m3dt;
  real_T c8_tank_volume_m3;
  uint32_T c8_c_debug_family_var_map[8];
  boolean_T c8_b_UnderThisCondition;
  boolean_T c8_b_ResultShouldBe;
  real_T c8_c_nargin = 3.0;
  real_T c8_c_nargout = 1.0;
  real_T c8_c_current_volume_m3;
  real_T c8_c_net_flow_m3dt;
  uint32_T c8_d_debug_family_var_map[7];
  boolean_T c8_c_UnderThisCondition;
  boolean_T c8_c_ResultShouldBe;
  real_T c8_d_nargin = 2.0;
  real_T c8_d_nargout = 1.0;
  real_T c8_d_current_volume_m3;
  real_T c8_d_net_flow_m3dt;
  real_T c8_b_tank_volume_m3;
  real_T c8_b_previous_volume_m3;
  boolean_T c8_d_UnderThisCondition;
  boolean_T c8_d_ResultShouldBe;
  real_T c8_e_nargin = 4.0;
  real_T c8_e_nargout = 1.0;
  boolean_T c8_b0;
  real_T c8_b_current_height_m;
  real_T c8_b_tank_height_m;
  uint32_T c8_e_debug_family_var_map[5];
  real_T c8_f_nargin = 2.0;
  real_T c8_f_nargout = 1.0;
  real_T c8_c_current_height_m;
  real_T c8_e_current_volume_m3;
  real_T c8_c_tank_cross_section_area_m2;
  uint32_T c8_f_debug_family_var_map[6];
  real_T c8_g_nargin = 3.0;
  real_T c8_g_nargout = 1.0;
  real_T c8_b_A;
  real_T c8_b_B;
  real_T c8_c_x;
  real_T c8_e_y;
  real_T c8_d_x;
  real_T c8_f_y;
  real_T c8_g_y;
  real_T c8_c_tank_height_m;
  real_T c8_c_tank_volume_m3;
  real_T c8_d_tank_cross_section_area_m2;
  real_T c8_h_nargin = 3.0;
  real_T c8_h_nargout = 1.0;
  real_T c8_c_A;
  real_T c8_c_B;
  real_T c8_e_x;
  real_T c8_h_y;
  real_T c8_f_x;
  real_T c8_i_y;
  real_T c8_j_y;
  boolean_T *c8_b_g8;
  boolean_T *c8_b_g7;
  boolean_T *c8_b_g6;
  boolean_T *c8_b_g5;
  boolean_T *c8_b_g4;
  boolean_T *c8_b_g3;
  boolean_T *c8_b_g2;
  boolean_T *c8_b_g1;
  boolean_T *c8_b_a7;
  boolean_T *c8_b_a6;
  boolean_T *c8_b_a5;
  boolean_T *c8_b_a4;
  boolean_T *c8_b_a3;
  boolean_T *c8_b_a2;
  boolean_T *c8_b_a1;
  real_T *c8_c_time;
  real_T *c8_d_current_height_m;
  real_T *c8_b_max_vol_m3;
  real_T *c8_b_e_valve_flow_rate_m3dt;
  real_T *c8_b_p_valve_flow_rate_m3dt;
  real_T *c8_e_tank_cross_section_area_m2;
  real_T *c8_b_valve_flow_rate_m3dt;
  real_T *c8_c_previous_height_m;
  boolean_T guard1 = FALSE;
  c8_b_g8 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 15);
  c8_b_g7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 14);
  c8_b_g6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 13);
  c8_b_g5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 12);
  c8_b_g4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 11);
  c8_b_g3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 10);
  c8_b_g2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 9);
  c8_c_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c8_d_current_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c8_b_g1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c8_b_max_vol_m3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c8_b_e_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S,
    4);
  c8_b_p_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S,
    3);
  c8_e_tank_cross_section_area_m2 = (real_T *)ssGetInputPortSignal
    (chartInstance->S, 2);
  c8_b_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_c_previous_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c8_b_a7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c8_b_a6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c8_b_a5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c8_b_a4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c8_b_a3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c8_b_a2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c8_b_a1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_c_previous_height_m;
  c8_b_hoistedGlobal = *c8_b_valve_flow_rate_m3dt;
  c8_c_hoistedGlobal = *c8_e_tank_cross_section_area_m2;
  c8_d_hoistedGlobal = *c8_b_p_valve_flow_rate_m3dt;
  c8_e_hoistedGlobal = *c8_b_e_valve_flow_rate_m3dt;
  c8_f_hoistedGlobal = *c8_b_max_vol_m3;
  c8_g_hoistedGlobal = *c8_d_current_height_m;
  c8_h_hoistedGlobal = *c8_c_time;
  c8_previous_height_m = c8_hoistedGlobal;
  c8_valve_flow_rate_m3dt = c8_b_hoistedGlobal;
  c8_tank_cross_section_area_m2 = c8_c_hoistedGlobal;
  c8_p_valve_flow_rate_m3dt = c8_d_hoistedGlobal;
  c8_e_valve_flow_rate_m3dt = c8_e_hoistedGlobal;
  c8_max_vol_m3 = c8_f_hoistedGlobal;
  c8_current_height_m = c8_g_hoistedGlobal;
  c8_time = c8_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 32U, 32U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_tank_height_m, 0U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_current_volume_m3, 1U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_previous_volume_m3, 2U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_net_flow_m3dt, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_initial_height_m, 4U, c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 5U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 6U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c8_previous_height_m, 7U, c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_valve_flow_rate_m3dt, 8U,
    c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_tank_cross_section_area_m2, 9U,
    c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_p_valve_flow_rate_m3dt, 10U,
    c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_e_valve_flow_rate_m3dt, 11U,
    c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_max_vol_m3, 12U, c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_current_height_m, 13U, c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_time, 14U, c8_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c8_a1, 15U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a2, 16U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a3, 17U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a4, 18U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a5, 19U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a6, 20U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a7, 21U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g1, 22U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g2, 23U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g3, 24U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g4, 25U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g5, 26U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g6, 27U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g7, 28U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g8, 29U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c8_pre_max_vol_m3,
    30U, c8_b_sf_marshallOut, c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable
    (&chartInstance->c8_pre_tank_cross_section_area_m2, 31U, c8_sf_marshallOut,
     c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c8_pre_max_vol_m3_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 7);
    chartInstance->c8_pre_max_vol_m3 = c8_max_vol_m3;
    chartInstance->c8_pre_max_vol_m3_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 9);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 10);
  if (CV_EML_IF(0, 1, 1,
                !chartInstance->c8_pre_tank_cross_section_area_m2_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
    chartInstance->c8_pre_tank_cross_section_area_m2 =
      c8_tank_cross_section_area_m2;
    chartInstance->c8_pre_tank_cross_section_area_m2_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  c8_A = c8_max_vol_m3;
  c8_B = c8_tank_cross_section_area_m2;
  c8_x = c8_A;
  c8_y = c8_B;
  c8_b_x = c8_x;
  c8_b_y = c8_y;
  c8_tank_height_m = c8_b_x / c8_b_y;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 15);
  c8_a = c8_current_height_m;
  c8_b = c8_tank_cross_section_area_m2;
  c8_current_volume_m3 = c8_a * c8_b;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 16);
  c8_b_a = c8_previous_height_m;
  c8_b_b = c8_tank_cross_section_area_m2;
  c8_previous_volume_m3 = c8_b_a * c8_b_b;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 17);
  c8_net_flow_m3dt = (c8_valve_flow_rate_m3dt - c8_p_valve_flow_rate_m3dt) -
    c8_e_valve_flow_rate_m3dt;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 18);
  c8_initial_height_m = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 22);
  c8_a1 = (c8_valve_flow_rate_m3dt >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 24);
  c8_a2 = (c8_tank_cross_section_area_m2 >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 26);
  c8_a3 = (chartInstance->c8_pre_tank_cross_section_area_m2 ==
           c8_tank_cross_section_area_m2);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 28);
  c8_a4 = (c8_p_valve_flow_rate_m3dt >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 30);
  c8_a5 = (c8_e_valve_flow_rate_m3dt >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 32);
  c8_a6 = (c8_max_vol_m3 >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 34);
  c8_a7 = (chartInstance->c8_pre_max_vol_m3 == c8_max_vol_m3);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 40);
  c8_b_initial_height_m = 0.0;
  c8_b_previous_height_m = c8_previous_height_m;
  c8_b_time = c8_time;
  c8_b_tank_cross_section_area_m2 = c8_tank_cross_section_area_m2;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c8_c_debug_family_names,
    c8_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_UnderThisCondition, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_ResultShouldBe, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_nargin, 2U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_nargout, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_initial_height_m, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_previous_height_m, 5U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_time, 6U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_tank_cross_section_area_m2, 7U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g1, 8U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 64);
  c8_UnderThisCondition = (c8_b_time == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 65);
  c8_c_a = c8_b_previous_height_m;
  c8_c_b = c8_b_tank_cross_section_area_m2;
  c8_c_y = c8_c_a * c8_c_b;
  c8_d_a = c8_b_initial_height_m;
  c8_d_b = c8_b_tank_cross_section_area_m2;
  c8_d_y = c8_d_a * c8_d_b;
  c8_ResultShouldBe = (c8_c_y == c8_d_y);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 66);
  c8_g1 = c8_implies(chartInstance, c8_UnderThisCondition, c8_ResultShouldBe);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -66);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 42);
  c8_b_current_volume_m3 = c8_current_volume_m3;
  c8_b_net_flow_m3dt = c8_net_flow_m3dt;
  c8_tank_volume_m3 = c8_max_vol_m3;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c8_d_debug_family_names,
    c8_c_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_UnderThisCondition, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_ResultShouldBe, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_nargin, 2U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_nargout, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_current_volume_m3, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_net_flow_m3dt, 5U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_tank_volume_m3, 6U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g2, 7U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 3);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 69);
  c8_b_UnderThisCondition = (c8_b_current_volume_m3 + c8_b_net_flow_m3dt >=
    c8_tank_volume_m3);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 70);
  c8_b_ResultShouldBe = (c8_b_current_volume_m3 == c8_tank_volume_m3);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 71);
  c8_g2 = c8_implies(chartInstance, c8_b_UnderThisCondition, c8_b_ResultShouldBe);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -71);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 44);
  c8_c_current_volume_m3 = c8_current_volume_m3;
  c8_c_net_flow_m3dt = c8_net_flow_m3dt;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c8_e_debug_family_names,
    c8_d_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_UnderThisCondition, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_ResultShouldBe, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_nargin, 2U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_nargout, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_current_volume_m3, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_net_flow_m3dt, 5U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g3, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 4);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 74);
  c8_c_UnderThisCondition = (c8_c_current_volume_m3 + c8_c_net_flow_m3dt <= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 75);
  c8_c_ResultShouldBe = (c8_c_current_volume_m3 == 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 76);
  c8_g3 = c8_implies(chartInstance, c8_c_UnderThisCondition, c8_c_ResultShouldBe);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -76);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 46);
  c8_d_current_volume_m3 = c8_current_volume_m3;
  c8_d_net_flow_m3dt = c8_net_flow_m3dt;
  c8_b_tank_volume_m3 = c8_max_vol_m3;
  c8_b_previous_volume_m3 = c8_previous_volume_m3;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c8_f_debug_family_names,
    c8_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_UnderThisCondition, 0U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_ResultShouldBe, 1U,
    c8_c_sf_marshallOut, c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_e_nargin, 2U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_e_nargout, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_current_volume_m3, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_net_flow_m3dt, 5U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_tank_volume_m3, 6U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_previous_volume_m3, 7U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g4, 8U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 5);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 79);
  guard1 = FALSE;
  if (c8_d_current_volume_m3 + c8_d_net_flow_m3dt <= c8_b_tank_volume_m3) {
    if (c8_d_current_volume_m3 + c8_d_net_flow_m3dt >= 0.0) {
      c8_b0 = TRUE;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c8_b0 = FALSE;
  }

  c8_d_UnderThisCondition = c8_b0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 80);
  c8_d_ResultShouldBe = (c8_d_current_volume_m3 == c8_b_previous_volume_m3 +
    c8_d_net_flow_m3dt);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 81);
  c8_g4 = c8_implies(chartInstance, c8_d_UnderThisCondition, c8_d_ResultShouldBe);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -81);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 48);
  c8_b_current_height_m = c8_current_height_m;
  c8_b_tank_height_m = c8_tank_height_m;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c8_g_debug_family_names,
    c8_e_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_f_nargin, 0U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_f_nargout, 1U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_current_height_m, 2U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b_tank_height_m, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g5, 4U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 6);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 84);
  c8_g5 = (c8_b_current_height_m <= c8_b_tank_height_m);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -84);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 50);
  c8_g6 = (c8_current_height_m >= 0.0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 52);
  c8_c_current_height_m = c8_current_height_m;
  c8_e_current_volume_m3 = c8_current_volume_m3;
  c8_c_tank_cross_section_area_m2 = c8_tank_cross_section_area_m2;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_h_debug_family_names,
    c8_f_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_g_nargin, 0U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g_nargout, 1U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_current_height_m, 2U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_e_current_volume_m3, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_tank_cross_section_area_m2, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g7, 5U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 8);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 90);
  c8_b_A = c8_e_current_volume_m3;
  c8_b_B = c8_c_tank_cross_section_area_m2;
  c8_c_x = c8_b_A;
  c8_e_y = c8_b_B;
  c8_d_x = c8_c_x;
  c8_f_y = c8_e_y;
  c8_g_y = c8_d_x / c8_f_y;
  c8_g7 = (c8_c_current_height_m == c8_g_y);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -90);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 54);
  c8_c_tank_height_m = c8_tank_height_m;
  c8_c_tank_volume_m3 = c8_max_vol_m3;
  c8_d_tank_cross_section_area_m2 = c8_tank_cross_section_area_m2;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_i_debug_family_names,
    c8_f_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_h_nargin, 0U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_h_nargout, 1U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_tank_height_m, 2U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c_tank_volume_m3, 3U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_d_tank_cross_section_area_m2, 4U,
    c8_d_sf_marshallOut, c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_g8, 5U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 9);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 93);
  c8_c_A = c8_c_tank_volume_m3;
  c8_c_B = c8_d_tank_cross_section_area_m2;
  c8_e_x = c8_c_A;
  c8_h_y = c8_c_B;
  c8_f_x = c8_e_x;
  c8_i_y = c8_h_y;
  c8_j_y = c8_f_x / c8_i_y;
  c8_g8 = (c8_c_tank_height_m == c8_j_y);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -93);
  sf_debug_symbol_scope_pop();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -54);
  sf_debug_symbol_scope_pop();
  *c8_b_a1 = c8_a1;
  *c8_b_a2 = c8_a2;
  *c8_b_a3 = c8_a3;
  *c8_b_a4 = c8_a4;
  *c8_b_a5 = c8_a5;
  *c8_b_a6 = c8_a6;
  *c8_b_a7 = c8_a7;
  *c8_b_g1 = c8_g1;
  *c8_b_g2 = c8_g2;
  *c8_b_g3 = c8_g3;
  *c8_b_g4 = c8_g4;
  *c8_b_g5 = c8_g5;
  *c8_b_g6 = c8_g6;
  *c8_b_g7 = c8_g7;
  *c8_b_g8 = c8_g8;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_Properties_Tank2_Primitives
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  if (!chartInstance->c8_pre_tank_cross_section_area_m2_not_empty) {
    sf_mex_assign(&c8_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_emlrt_marshallIn(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance, const mxArray *c8_b_pre_tank_cross_section_area_m2, const
  char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_pre_tank_cross_section_area_m2), &c8_thisId);
  sf_mex_destroy(&c8_b_pre_tank_cross_section_area_m2);
  return c8_y;
}

static real_T c8_b_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_pre_tank_cross_section_area_m2_not_empty = FALSE;
  } else {
    chartInstance->c8_pre_tank_cross_section_area_m2_not_empty = TRUE;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
    c8_y = c8_d0;
  }

  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_pre_tank_cross_section_area_m2;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_b_pre_tank_cross_section_area_m2 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_pre_tank_cross_section_area_m2), &c8_thisId);
  sf_mex_destroy(&c8_b_pre_tank_cross_section_area_m2);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  if (!chartInstance->c8_pre_max_vol_m3_not_empty) {
    sf_mex_assign(&c8_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_b_pre_max_vol_m3, const char_T *c8_identifier)
{
  real_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_pre_max_vol_m3),
    &c8_thisId);
  sf_mex_destroy(&c8_b_pre_max_vol_m3);
  return c8_y;
}

static real_T c8_d_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d1;
  if (mxIsEmpty(c8_u)) {
    chartInstance->c8_pre_max_vol_m3_not_empty = FALSE;
  } else {
    chartInstance->c8_pre_max_vol_m3_not_empty = TRUE;
    sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d1, 1, 0, 0U, 0, 0U, 0);
    c8_y = c8_d1;
  }

  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_pre_max_vol_m3;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_b_pre_max_vol_m3 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_pre_max_vol_m3),
    &c8_thisId);
  sf_mex_destroy(&c8_b_pre_max_vol_m3);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  boolean_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(boolean_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static boolean_T c8_e_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_g8, const char_T *c8_identifier)
{
  boolean_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_g8), &c8_thisId);
  sf_mex_destroy(&c8_g8);
  return c8_y;
}

static boolean_T c8_f_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  boolean_T c8_y;
  boolean_T c8_b1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_b1, 1, 11, 0U, 0, 0U, 0);
  c8_y = c8_b1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_g8;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  boolean_T c8_y;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_g8 = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_g8), &c8_thisId);
  sf_mex_destroy(&c8_g8);
  *(boolean_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_g_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d2;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d2, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d2;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_Properties_Tank2_Primitives_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[4];
  c8_ResolvedFunctionInfo (*c8_b_info)[4];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i0;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_b_info = (c8_ResolvedFunctionInfo (*)[4])c8_info;
  (*c8_b_info)[0].context = "";
  (*c8_b_info)[0].name = "mrdivide";
  (*c8_b_info)[0].dominantType = "double";
  (*c8_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[0].fileTimeLo = 1342832544U;
  (*c8_b_info)[0].fileTimeHi = 0U;
  (*c8_b_info)[0].mFileTimeLo = 1319751566U;
  (*c8_b_info)[0].mFileTimeHi = 0U;
  (*c8_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c8_b_info)[1].name = "rdivide";
  (*c8_b_info)[1].dominantType = "double";
  (*c8_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[1].fileTimeLo = 1286840444U;
  (*c8_b_info)[1].fileTimeHi = 0U;
  (*c8_b_info)[1].mFileTimeLo = 0U;
  (*c8_b_info)[1].mFileTimeHi = 0U;
  (*c8_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c8_b_info)[2].name = "eml_div";
  (*c8_b_info)[2].dominantType = "double";
  (*c8_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c8_b_info)[2].fileTimeLo = 1313369410U;
  (*c8_b_info)[2].fileTimeHi = 0U;
  (*c8_b_info)[2].mFileTimeLo = 0U;
  (*c8_b_info)[2].mFileTimeHi = 0U;
  (*c8_b_info)[3].context = "";
  (*c8_b_info)[3].name = "mtimes";
  (*c8_b_info)[3].dominantType = "double";
  (*c8_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c8_b_info)[3].fileTimeLo = 1289541292U;
  (*c8_b_info)[3].fileTimeHi = 0U;
  (*c8_b_info)[3].mFileTimeLo = 0U;
  (*c8_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c8_i0 = 0; c8_i0 < 4; c8_i0++) {
    c8_r0 = &c8_info[c8_i0];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i0);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i0);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static boolean_T c8_implies(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance, boolean_T c8_a, boolean_T c8_b)
{
  boolean_T c8_c;
  uint32_T c8_debug_family_var_map[5];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  boolean_T c8_b2;
  boolean_T guard1 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_d_sf_marshallOut,
    c8_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_a, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_b, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_c, 4U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 61);
  guard1 = FALSE;
  if (!c8_a) {
    guard1 = TRUE;
  } else if (c8_b) {
    guard1 = TRUE;
  } else {
    c8_b2 = FALSE;
  }

  if (guard1 == TRUE) {
    c8_b2 = TRUE;
  }

  c8_c = c8_b2;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -61);
  sf_debug_symbol_scope_pop();
  return c8_c;
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_h_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i1;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i1, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i1;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_i_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_b_is_active_c8_Properties_Tank2_Primitives, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_Properties_Tank2_Primitives), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_Properties_Tank2_Primitives);
  return c8_y;
}

static uint8_T c8_j_emlrt_marshallIn
  (SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance, const mxArray *
   c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_Properties_Tank2_PrimitivesInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_Properties_Tank2_Primitives_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1026701459U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2368352159U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3105996372U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1105795608U);
}

mxArray *sf_c8_Properties_Tank2_Primitives_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SwUWDAES7voiwUNMxFOHfF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c8_Properties_Tank2_Primitives(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[33],T\"a1\",},{M[1],M[34],T\"a2\",},{M[1],M[35],T\"a3\",},{M[1],M[36],T\"a4\",},{M[1],M[37],T\"a5\",},{M[1],M[38],T\"a6\",},{M[1],M[39],T\"a7\",},{M[1],M[5],T\"g1\",},{M[1],M[23],T\"g2\",},{M[1],M[24],T\"g3\",}}",
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[25],T\"g4\",},{M[1],M[26],T\"g5\",},{M[1],M[27],T\"g6\",},{M[1],M[28],T\"g7\",},{M[1],M[29],T\"g8\",},{M[4],M[0],T\"pre_max_vol_m3\",S'l','i','p'{{M1x2[310 324],M[0],}}},{M[4],M[0],T\"pre_tank_cross_section_area_m2\",S'l','i','p'{{M1x2[400 430],M[0],}}},{M[8],M[0],T\"is_active_c8_Properties_Tank2_Primitives\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 18, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_Properties_Tank2_Primitives_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
    chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Properties_Tank2_PrimitivesMachineNumber_,
           8,
           1,
           1,
           23,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_Properties_Tank2_PrimitivesMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Properties_Tank2_PrimitivesMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Properties_Tank2_PrimitivesMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"a1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"a2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"a3");
          _SFD_SET_DATA_PROPS(3,2,0,1,"a4");
          _SFD_SET_DATA_PROPS(4,2,0,1,"a5");
          _SFD_SET_DATA_PROPS(5,2,0,1,"a6");
          _SFD_SET_DATA_PROPS(6,2,0,1,"a7");
          _SFD_SET_DATA_PROPS(7,1,1,0,"previous_height_m");
          _SFD_SET_DATA_PROPS(8,1,1,0,"valve_flow_rate_m3dt");
          _SFD_SET_DATA_PROPS(9,1,1,0,"tank_cross_section_area_m2");
          _SFD_SET_DATA_PROPS(10,1,1,0,"p_valve_flow_rate_m3dt");
          _SFD_SET_DATA_PROPS(11,1,1,0,"e_valve_flow_rate_m3dt");
          _SFD_SET_DATA_PROPS(12,1,1,0,"max_vol_m3");
          _SFD_SET_DATA_PROPS(13,2,0,1,"g1");
          _SFD_SET_DATA_PROPS(14,1,1,0,"current_height_m");
          _SFD_SET_DATA_PROPS(15,1,1,0,"time");
          _SFD_SET_DATA_PROPS(16,2,0,1,"g2");
          _SFD_SET_DATA_PROPS(17,2,0,1,"g3");
          _SFD_SET_DATA_PROPS(18,2,0,1,"g4");
          _SFD_SET_DATA_PROPS(19,2,0,1,"g5");
          _SFD_SET_DATA_PROPS(20,2,0,1,"g6");
          _SFD_SET_DATA_PROPS(21,2,0,1,"g7");
          _SFD_SET_DATA_PROPS(22,2,0,1,"g8");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,12,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,3353);
        _SFD_CV_INIT_EML_FCN(0,1,"implies",3353,-1,3508);
        _SFD_CV_INIT_EML_FCN(0,2,"initially_empty",3508,-1,3950);
        _SFD_CV_INIT_EML_FCN(0,3,"full_cond",3950,-1,4348);
        _SFD_CV_INIT_EML_FCN(0,4,"empty_cond",4348,-1,4768);
        _SFD_CV_INIT_EML_FCN(0,5,"tank_volume_update",4768,-1,5220);
        _SFD_CV_INIT_EML_FCN(0,6,"tank_less_or_equal_full",5220,-1,5396);
        _SFD_CV_INIT_EML_FCN(0,7,"tank_height_not_negative",5396,-1,5613);
        _SFD_CV_INIT_EML_FCN(0,8,"math_check",5613,-1,5893);
        _SFD_CV_INIT_EML_FCN(0,9,"math_check_2",5893,-1,6165);
        _SFD_CV_INIT_EML_FCN(0,10,"math_check_3",6165,-1,6423);
        _SFD_CV_INIT_EML_FCN(0,11,"math_check_4",6423,-1,6741);
        _SFD_CV_INIT_EML_IF(0,1,0,325,351,-1,388);
        _SFD_CV_INIT_EML_IF(0,1,1,431,473,-1,542);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_c_sf_marshallOut,(MexInFcnForType)c8_c_sf_marshallIn);

        {
          boolean_T *c8_a1;
          boolean_T *c8_a2;
          boolean_T *c8_a3;
          boolean_T *c8_a4;
          boolean_T *c8_a5;
          boolean_T *c8_a6;
          boolean_T *c8_a7;
          real_T *c8_previous_height_m;
          real_T *c8_valve_flow_rate_m3dt;
          real_T *c8_tank_cross_section_area_m2;
          real_T *c8_p_valve_flow_rate_m3dt;
          real_T *c8_e_valve_flow_rate_m3dt;
          real_T *c8_max_vol_m3;
          boolean_T *c8_g1;
          real_T *c8_current_height_m;
          real_T *c8_time;
          boolean_T *c8_g2;
          boolean_T *c8_g3;
          boolean_T *c8_g4;
          boolean_T *c8_g5;
          boolean_T *c8_g6;
          boolean_T *c8_g7;
          boolean_T *c8_g8;
          c8_g8 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 15);
          c8_g7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 14);
          c8_g6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 13);
          c8_g5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 12);
          c8_g4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 11);
          c8_g3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 10);
          c8_g2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 9);
          c8_time = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c8_current_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S,
            6);
          c8_g1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c8_max_vol_m3 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c8_e_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 4);
          c8_p_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 3);
          c8_tank_cross_section_area_m2 = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 2);
          c8_valve_flow_rate_m3dt = (real_T *)ssGetInputPortSignal
            (chartInstance->S, 1);
          c8_previous_height_m = (real_T *)ssGetInputPortSignal(chartInstance->S,
            0);
          c8_a7 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c8_a6 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c8_a5 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c8_a4 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c8_a3 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c8_a2 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c8_a1 = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c8_a1);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_a2);
          _SFD_SET_DATA_VALUE_PTR(2U, c8_a3);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_a4);
          _SFD_SET_DATA_VALUE_PTR(4U, c8_a5);
          _SFD_SET_DATA_VALUE_PTR(5U, c8_a6);
          _SFD_SET_DATA_VALUE_PTR(6U, c8_a7);
          _SFD_SET_DATA_VALUE_PTR(7U, c8_previous_height_m);
          _SFD_SET_DATA_VALUE_PTR(8U, c8_valve_flow_rate_m3dt);
          _SFD_SET_DATA_VALUE_PTR(9U, c8_tank_cross_section_area_m2);
          _SFD_SET_DATA_VALUE_PTR(10U, c8_p_valve_flow_rate_m3dt);
          _SFD_SET_DATA_VALUE_PTR(11U, c8_e_valve_flow_rate_m3dt);
          _SFD_SET_DATA_VALUE_PTR(12U, c8_max_vol_m3);
          _SFD_SET_DATA_VALUE_PTR(13U, c8_g1);
          _SFD_SET_DATA_VALUE_PTR(14U, c8_current_height_m);
          _SFD_SET_DATA_VALUE_PTR(15U, c8_time);
          _SFD_SET_DATA_VALUE_PTR(16U, c8_g2);
          _SFD_SET_DATA_VALUE_PTR(17U, c8_g3);
          _SFD_SET_DATA_VALUE_PTR(18U, c8_g4);
          _SFD_SET_DATA_VALUE_PTR(19U, c8_g5);
          _SFD_SET_DATA_VALUE_PTR(20U, c8_g6);
          _SFD_SET_DATA_VALUE_PTR(21U, c8_g7);
          _SFD_SET_DATA_VALUE_PTR(22U, c8_g8);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Properties_Tank2_PrimitivesMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "76iZqHQPUbb5EihIP6BLy";
}

static void sf_opaque_initialize_c8_Properties_Tank2_Primitives(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_Properties_Tank2_PrimitivesInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
  initialize_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_Properties_Tank2_Primitives(void
  *chartInstanceVar)
{
  enable_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_Properties_Tank2_Primitives(void
  *chartInstanceVar)
{
  disable_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_Properties_Tank2_Primitives(void
  *chartInstanceVar)
{
  sf_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_Properties_Tank2_Primitives
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Properties_Tank2_Primitives();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c8_Properties_Tank2_Primitives(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_Properties_Tank2_Primitives();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_Properties_Tank2_Primitives
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c8_Properties_Tank2_Primitives(S);
}

static void sf_opaque_set_sim_state_c8_Properties_Tank2_Primitives(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c8_Properties_Tank2_Primitives(S, st);
}

static void sf_opaque_terminate_c8_Properties_Tank2_Primitives(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_Properties_Tank2_Primitives
      ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Properties_Tank2_Primitives_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_Properties_Tank2_Primitives
    ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_Properties_Tank2_Primitives(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_Properties_Tank2_Primitives
      ((SFc8_Properties_Tank2_PrimitivesInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_Properties_Tank2_Primitives(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Properties_Tank2_Primitives_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,8);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,15);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2204821700U));
  ssSetChecksum1(S,(1457695458U));
  ssSetChecksum2(S,(64120292U));
  ssSetChecksum3(S,(3995330934U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_Properties_Tank2_Primitives(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_Properties_Tank2_Primitives(SimStruct *S)
{
  SFc8_Properties_Tank2_PrimitivesInstanceStruct *chartInstance;
  chartInstance = (SFc8_Properties_Tank2_PrimitivesInstanceStruct *)malloc
    (sizeof(SFc8_Properties_Tank2_PrimitivesInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_Properties_Tank2_PrimitivesInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_Properties_Tank2_Primitives;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c8_Properties_Tank2_Primitives_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_Properties_Tank2_Primitives(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_Properties_Tank2_Primitives(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_Properties_Tank2_Primitives(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_Properties_Tank2_Primitives_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
