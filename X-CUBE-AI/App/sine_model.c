/**
  ******************************************************************************
  * @file    sine_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Mar  8 23:22:56 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "sine_model.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_sine_model
 
#undef AI_SINE_MODEL_MODEL_SIGNATURE
#define AI_SINE_MODEL_MODEL_SIGNATURE     "addc0b0e2f9e7c76ce5cdc45d30316dc"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Mar  8 23:22:56 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_SINE_MODEL_N_BATCHES
#define AI_SINE_MODEL_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array lstm_1_scratch0_array;   /* Array #0 */
AI_STATIC ai_array dense_3_bias_array;   /* Array #1 */
AI_STATIC ai_array dense_3_weights_array;   /* Array #2 */
AI_STATIC ai_array dense_2_bias_array;   /* Array #3 */
AI_STATIC ai_array dense_2_weights_array;   /* Array #4 */
AI_STATIC ai_array lstm_1_bias_array;   /* Array #5 */
AI_STATIC ai_array lstm_1_peephole_array;   /* Array #6 */
AI_STATIC ai_array lstm_1_recurrent_array;   /* Array #7 */
AI_STATIC ai_array lstm_1_kernel_array;   /* Array #8 */
AI_STATIC ai_array input_0_output_array;   /* Array #9 */
AI_STATIC ai_array lstm_1_output_array;   /* Array #10 */
AI_STATIC ai_array dense_2_output_array;   /* Array #11 */
AI_STATIC ai_array dense_2_nl_output_array;   /* Array #12 */
AI_STATIC ai_array dense_3_output_array;   /* Array #13 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor lstm_1_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor dense_3_bias;   /* Tensor #1 */
AI_STATIC ai_tensor dense_3_weights;   /* Tensor #2 */
AI_STATIC ai_tensor dense_2_bias;   /* Tensor #3 */
AI_STATIC ai_tensor dense_2_weights;   /* Tensor #4 */
AI_STATIC ai_tensor lstm_1_bias;   /* Tensor #5 */
AI_STATIC ai_tensor lstm_1_peephole;   /* Tensor #6 */
AI_STATIC ai_tensor lstm_1_recurrent;   /* Tensor #7 */
AI_STATIC ai_tensor lstm_1_kernel;   /* Tensor #8 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #9 */
AI_STATIC ai_tensor lstm_1_output;   /* Tensor #10 */
AI_STATIC ai_tensor dense_2_output;   /* Tensor #11 */
AI_STATIC ai_tensor dense_2_nl_output;   /* Tensor #12 */
AI_STATIC ai_tensor dense_3_output;   /* Tensor #13 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain lstm_1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain dense_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_2_nl_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain dense_3_chain;   /* Chain #3 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_lstm lstm_1_layer; /* Layer #0 */
AI_STATIC ai_layer_dense dense_2_layer; /* Layer #1 */
AI_STATIC ai_layer_nl dense_2_nl_layer; /* Layer #2 */
AI_STATIC ai_layer_dense dense_3_layer; /* Layer #3 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 700, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10000, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 400, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_peephole_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 300, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 40000, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 400, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  lstm_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_2_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_3_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 700, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2800, 2800),
  1, &lstm_1_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_3_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 100, 1, 1, 1), AI_STRIDE_INIT(4, 4, 400, 400, 400),
  1, &dense_3_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_2_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 100, 100, 1, 1), AI_STRIDE_INIT(4, 4, 400, 40000, 40000),
  1, &dense_2_weights_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1600, 1600),
  1, &lstm_1_bias_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_peephole, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 300, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1200, 1200),
  1, &lstm_1_peephole_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_recurrent, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 100, 1, 1, 400), AI_STRIDE_INIT(4, 4, 400, 400, 400),
  1, &lstm_1_recurrent_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_kernel, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 400), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &lstm_1_kernel_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &input_0_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  lstm_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &lstm_1_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_2_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  dense_2_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_2_nl_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_3_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  lstm_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &lstm_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 7, &lstm_1_kernel, &lstm_1_recurrent, &lstm_1_peephole, &lstm_1_bias, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &lstm_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  lstm_1_layer, 0,
  LSTM_TYPE,
  lstm, forward_lstm,
  &AI_NET_OBJ_INSTANCE, &dense_2_layer, AI_STATIC,
  .tensors = &lstm_1_chain, 
  .n_units = 100, 
  .activation_nl = nl_func_relu_array_f32, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .out_nl = nl_func_relu_array_f32, 
  .recurrent_nl = nl_func_sigmoid_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &lstm_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_2_weights, &dense_2_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_layer, 1,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_2_nl_layer, AI_STATIC,
  .tensors = &dense_2_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_2_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_2_nl_layer, 1,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_3_layer, AI_STATIC,
  .tensors = &dense_2_nl_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_2_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_3_weights, &dense_3_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_3_layer, 2,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &dense_3_layer, AI_STATIC,
  .tensors = &dense_3_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 205204, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 3200, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_SINE_MODEL_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_SINE_MODEL_OUT_NUM, &dense_3_output),
  &lstm_1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool sine_model_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_SINE_MODEL_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    lstm_1_scratch0_array.data = AI_PTR(activations + 0);
    lstm_1_scratch0_array.data_start = AI_PTR(activations + 0);
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    lstm_1_output_array.data = AI_PTR(activations + 2800);
    lstm_1_output_array.data_start = AI_PTR(activations + 2800);
    dense_2_output_array.data = AI_PTR(activations + 0);
    dense_2_output_array.data_start = AI_PTR(activations + 0);
    dense_2_nl_output_array.data = AI_PTR(activations + 400);
    dense_2_nl_output_array.data_start = AI_PTR(activations + 400);
    dense_3_output_array.data = AI_PTR(NULL);
    dense_3_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool sine_model_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_3_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_3_bias_array.data = AI_PTR(weights + 205200);
    dense_3_bias_array.data_start = AI_PTR(weights + 205200);
    dense_3_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_3_weights_array.data = AI_PTR(weights + 204800);
    dense_3_weights_array.data_start = AI_PTR(weights + 204800);
    dense_2_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_2_bias_array.data = AI_PTR(weights + 204400);
    dense_2_bias_array.data_start = AI_PTR(weights + 204400);
    dense_2_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_2_weights_array.data = AI_PTR(weights + 164400);
    dense_2_weights_array.data_start = AI_PTR(weights + 164400);
    lstm_1_bias_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_bias_array.data = AI_PTR(weights + 162800);
    lstm_1_bias_array.data_start = AI_PTR(weights + 162800);
    lstm_1_peephole_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_peephole_array.data = AI_PTR(weights + 161600);
    lstm_1_peephole_array.data_start = AI_PTR(weights + 161600);
    lstm_1_recurrent_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_recurrent_array.data = AI_PTR(weights + 1600);
    lstm_1_recurrent_array.data_start = AI_PTR(weights + 1600);
    lstm_1_kernel_array.format |= AI_FMT_FLAG_CONST;
    lstm_1_kernel_array.data = AI_PTR(weights + 0);
    lstm_1_kernel_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_sine_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_SINE_MODEL_MODEL_NAME,
      .model_signature   = AI_SINE_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 51100,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_sine_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_sine_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_sine_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_sine_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= sine_model_configure_weights(net_ctx, &params->params);
  ok &= sine_model_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_sine_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_sine_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_SINE_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

