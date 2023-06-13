#ifndef TVMGEN_REC_H_
#define TVMGEN_REC_H_
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * \brief Input tensor x size (in bytes) for TVM module "rec" 
 */
#define TVMGEN_REC_X_SIZE 122880
/*!
 * \brief Output tensor output size (in bytes) for TVM module "rec" 
 */
#define TVMGEN_REC_OUTPUT_SIZE 31040
/*!
 * \brief Input tensor pointers for TVM module "rec" 
 */
struct tvmgen_rec_inputs {
  void* x;
};

/*!
 * \brief Output tensor pointers for TVM module "rec" 
 */
struct tvmgen_rec_outputs {
  void* output;
};

/*!
 * \brief entrypoint function for TVM module "rec"
 * \param inputs Input tensors for the module 
 * \param outputs Output tensors for the module 
 */
int32_t tvmgen_rec_run(
  struct tvmgen_rec_inputs* inputs,
  struct tvmgen_rec_outputs* outputs
);
/*!
 * \brief Workspace size for TVM module "rec" 
 */
#define TVMGEN_REC_WORKSPACE_SIZE 1429176

#ifdef __cplusplus
}
#endif

#endif // TVMGEN_REC_H_
