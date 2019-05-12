#pragma once

#include <Eigen/Core>

namespace rdsp {

template<typename T>
using array_base = Eigen::DenseBase<T>;

template<typename T>
using array = Eigen::Matrix<T, 1, Eigen::Dynamic>;

template<typename T>
using array_map = Eigen::Map<array<T>>;

}  // namespace rdsp
