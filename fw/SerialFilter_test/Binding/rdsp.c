#include "rdsp.h"

static size_t rdsp_mp_write(struct cmp_ctx_s *mp_ctx,
                            const void *data, size_t count) {
  rdsp_context_t *ctx = (rdsp_context_t *)mp_ctx->buf;
  return ctx->write(data, count, ctx->arg);
}

static bool rdsp_mp_read(struct cmp_ctx_s *mp_ctx,
                         void *data, size_t limit) {
  rdsp_context_t *ctx = (rdsp_context_t *)mp_ctx->buf;
  return ctx->read(data, limit, ctx->arg);
}

void
rdsp_context_init(rdsp_context_t *context, rdsp_read_t read,
                  rdsp_write_t write, void *arg) {
  context->read = read;
  context->write = write;
  context->arg = arg;

  cmp_init(&context->mp_context, context, rdsp_mp_read, NULL, rdsp_mp_write);
}

bool
rdsp_take_q15_filter_request(rdsp_context_t *ctx, q15_filter_request_t *req) {
  uint32_t value;
  if (!cmp_read_array(&ctx->mp_context, &value)) {
    return false;
  }
  req->coeff_size = value;

  if (req->coeff_size > req->coeff_limit) {
    return false;
  }

  for (int i = 0; i < req->coeff_size; ++i) {
    if (!cmp_read_short(&ctx->mp_context, &req->coeff[i])) {
      return false;
    }
  }

  if (!cmp_read_array(&ctx->mp_context, &value)) {
    return false;
  }
  req->input_size = value;

  if (req->input_size > req->input_limit) {
    return false;
  }

  for (int i = 0; i < req->input_size; ++i) {
    if (!cmp_read_short(&ctx->mp_context, &req->input[i])) {
      return false;
    }
  }

  return true;
}

bool
rdsp_dump_q15_filter_response(rdsp_context_t *ctx, q15_filter_response_t *res) {
  if (!cmp_write_array(&ctx->mp_context, res->output_size)) {
    return false;
  }

  for (int i = 0; i < res->output_size; ++i) {
    if (!cmp_write_s16(&ctx->mp_context, res->output[i])) {
      return false;
    }
  }

  return true;
}
