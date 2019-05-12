#include "mex.h"
#include "matrix.h"

#include "rdsp/filter.hpp"
#include "rdsp/types.hpp"

namespace rdsp {
namespace mex {

template<typename T>
void filter(const mxArray *device, const mxArray *coeff,
            const mxArray *input, const mxArray *timeout,
            mxArray *output) {
  const std::string mapped_device(std::move(mxArrayToString(device)));
  rdsp::array_map<T> mapped_input(static_cast<T*>(mxGetData(input)),
                                  mxGetNumberOfElements(input));
  rdsp::array_map<T> mapped_coeff(static_cast<T*>(mxGetData(coeff)),
                                  mxGetNumberOfElements(coeff));
  rdsp::array_map<T> mapped_output(static_cast<T*>(mxGetData(output)),
                                   mxGetNumberOfElements(output));
  auto mapped_timeout = std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::duration<double>(*((double *)mxGetData(timeout))));
  rdsp::filter(mapped_device, mapped_coeff, mapped_input, mapped_output, mapped_timeout);
}

auto pick_filter_specialization(mxClassID type) {
  switch(type) {
    case mxDOUBLE_CLASS:
      return rdsp::mex::filter<double>;
    case mxSINGLE_CLASS:
      return rdsp::mex::filter<float>;
    case mxINT8_CLASS:
      return rdsp::mex::filter<int8_t>;
    case mxUINT8_CLASS:
      return rdsp::mex::filter<uint8_t>;
    case mxINT16_CLASS:
      return rdsp::mex::filter<int16_t>;
    case mxUINT16_CLASS:
      return rdsp::mex::filter<uint16_t>;
    case mxINT32_CLASS:
      return rdsp::mex::filter<int32_t>;
    case mxUINT32_CLASS:
      return rdsp::mex::filter<uint32_t>;
    case mxINT64_CLASS:
      return rdsp::mex::filter<int64_t>;
    case mxUINT64_CLASS:
      return rdsp::mex::filter<uint64_t>;
    default:
      throw std::runtime_error("Unknown numeric type\n");
  }
}

}  // namespace mex
}  // namespace rdsp

extern "C" {

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
  if (nlhs > 1) {
    mexErrMsgTxt("Too many (>1) output arguments\n");
  }
  if (nrhs != 4) {
    mexErrMsgTxt("Too many or too few (=4) input arguments\n");
  }
  if (!mxIsChar(prhs[0])) {
    mexErrMsgTxt("Device must be a string\n");
  }
  if (1 != mxGetM(prhs[1])) {
    mexErrMsgTxt("Coefficients must be a row matrix\n");
  }
  if (!mxIsNumeric(prhs[1])) {
    mexErrMsgTxt("Coefficients must be numeric\n");
  }
  if (1 != mxGetM(prhs[2])) {
    mexErrMsgTxt("Input must be a row matrix\n");
  }
  if (!mxIsNumeric(prhs[2])) {
    mexErrMsgTxt("Input must be numeric\n");
  }
  if (mxGetClassID(prhs[1]) != mxGetClassID(prhs[2])) {
    mexErrMsgTxt("Input and coefficients must be of the same type\n");
  }
  if (!mxIsScalar(prhs[3]) || !mxIsDouble(prhs[3])) {
    mexErrMsgTxt("Timeout must be a number\n");
  }
  plhs[0] = mxCreateNumericMatrix(1, mxGetNumberOfElements(prhs[2]),
                                  mxGetClassID(prhs[2]), mxREAL);
  try {
    auto func = rdsp::mex::pick_filter_specialization(mxGetClassID(prhs[2]));
    func(prhs[0], prhs[1], prhs[2], prhs[3], plhs[0]);
  } catch (const std::exception& e) {
    mexErrMsgTxt(e.what());
  }
}

}
