#ifndef _RDSP_H
#define _RDSP_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cmp.h"

typedef struct {
  int16_t *coeff;
  size_t coeff_size;
  size_t coeff_limit;
  int16_t *input;
  size_t input_size;
  size_t input_limit;
} q15_filter_request_t;

typedef struct {
  int16_t *output;
  size_t output_size;
} q15_filter_response_t;

typedef bool (*rdsp_read_t)(void *data, size_t limit, void *arg);
typedef size_t (*rdsp_write_t)(const void *data, size_t count, void *arg);

typedef struct {
  cmp_ctx_t mp_context;
  rdsp_read_t read;
  rdsp_write_t write;
  void *arg;
} rdsp_context_t;

void
rdsp_context_init(rdsp_context_t *context, rdsp_read_t read, rdsp_write_t write, void *arg);

bool
rdsp_take_q15_filter_request(rdsp_context_t *ctx, q15_filter_request_t *req);

bool
rdsp_dump_q15_filter_response(rdsp_context_t *ctx, q15_filter_response_t *res);

#endif  // _RDSP_H
