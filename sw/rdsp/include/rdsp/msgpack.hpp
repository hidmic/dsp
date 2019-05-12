#pragma once

#include <msgpack.hpp>

#include "rdsp/types.hpp"

namespace msgpack {
MSGPACK_API_VERSION_NAMESPACE(v1) {
namespace adaptor {

template <typename T>
struct pack<rdsp::array<T>> {
  template <typename Stream>
  msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, const rdsp::array<T>& v) const {
    if (v.rows() != 1) throw msgpack::type_error();
    o.pack_array(v.cols());
    for (int i = 0; i < v.cols(); ++i) {
      o.pack(v(1, i));
    }
    return o;
  }
};

template <typename T>
struct convert<rdsp::array<T>> {
  msgpack::object const& operator()(msgpack::object const& o, rdsp::array<T>& v) const {
    if (v.rows() != 1) throw msgpack::type_error();
    if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
    if (o.via.array.size != v.size()) throw msgpack::type_error();
    for (int i = 0; i < o.via.array.size; ++i) {
      o.via.array.ptr[i].convert(v(1, i));
    }
    return o;
  }
};

template <typename T>
struct pack<rdsp::array_map<T>> {
  template <typename Stream>
  msgpack::packer<Stream>& operator()(msgpack::packer<Stream>& o, const rdsp::array_map<T>& v) const {
    if (v.rows() != 1) throw msgpack::type_error();
    o.pack_array(v.cols());
    for (int i = 0; i < v.cols(); ++i) {
      o.pack(v(1, i));
    }
    return o;
  }
};

template <typename T>
struct convert<rdsp::array_map<T>> {
  msgpack::object const& operator()(msgpack::object const& o, rdsp::array_map<T>& v) const {
    if (v.rows() != 1) throw msgpack::type_error();
    if (o.type != msgpack::type::ARRAY) throw msgpack::type_error();
    if (o.via.array.size != v.size()) throw msgpack::type_error();
    for (int i = 0; i < o.via.array.size; ++i) {
      o.via.array.ptr[i].convert(v(1, i));
    }
    return o;
  }
};

}  // namespace adaptor
}  // MSGPACK_API_VERSION_NAMESPACE(v1)
}  // namespace msgpack
