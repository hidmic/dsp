#pragma once

#include <chrono>
#include <string>

#include <asio.hpp>
#include <msgpack.hpp>

#include "rdsp/types.hpp"
#include "rdsp/msgpack.hpp"

namespace rdsp {

using namespace std::chrono_literals;

template <typename T>
void filter(const std::string& device, const rdsp::array<T>& coeff,
            const rdsp::array<T>& input, rdsp::array<T>& output,
            const std::chrono::milliseconds& timeout = 2s) {
  asio::io_service io;
  asio::serial_port port(io, device);
  port.set_option(asio::serial_port_base::baud_rate(115200));

  msgpack::sbuffer buffer;
  msgpack::packer<msgpack::sbuffer> packer(&buffer);
  const rdsp::array<T> rcoeff = coeff.reverse();
  packer.pack(rcoeff); packer.pack(input);

  asio::write(port, asio::buffer(buffer.data(), buffer.size()));

  msgpack::unpacker unpacker;
  unpacker.reserve_buffer(buffer.size());

  asio::deadline_timer deadline(io);
  deadline.expires_from_now(boost::posix_time::milliseconds(timeout.count()));
  deadline.async_wait([&port](const asio::error_code& error) {
    throw std::runtime_error("Filter operation timed out\n");
  });

  msgpack::object_handle handle;
  do {
    asio::async_read(
      port, asio::buffer(unpacker.buffer(), unpacker.buffer_capacity()),
      [&unpacker, &deadline](const asio::error_code& error, std::size_t bytes_read) {
        unpacker.buffer_consumed(bytes_read);
      });
    io.run_one();
  } while (!unpacker.next(handle));
  const msgpack::object& object = handle.get();
  if (object.is_nil()) {
    throw std::runtime_error("No output for filter operation\n");
  }
  object.convert(output);
}

template <typename T>
void filter(const std::string& device, const rdsp::array_map<T>& coeff,
            const rdsp::array_map<T>& input, rdsp::array_map<T>& output,
            const std::chrono::milliseconds& timeout = 2s) {
  asio::io_service io;
  asio::serial_port port(io, device);
  port.set_option(asio::serial_port_base::baud_rate(115200));

  msgpack::sbuffer buffer;
  msgpack::packer<msgpack::sbuffer> packer(&buffer);
  const rdsp::array<T> rcoeff = coeff.reverse();
  packer.pack(rcoeff); packer.pack(input);

  asio::write(port, asio::buffer(buffer.data(), buffer.size()));

  msgpack::unpacker unpacker;
  unpacker.reserve_buffer(buffer.size());

  asio::deadline_timer deadline(io);
  deadline.expires_from_now(boost::posix_time::milliseconds(timeout.count()));
  deadline.async_wait([&port](const asio::error_code& error) {
    throw std::runtime_error("Filter operation timed out\n");
  });

  msgpack::object_handle handle;
  do {
    asio::async_read(
      port, asio::buffer(unpacker.buffer(), unpacker.buffer_capacity()),
      [&unpacker, &deadline](const asio::error_code& error, std::size_t bytes_read) {
        unpacker.buffer_consumed(bytes_read);
      });
    io.run_one();
  } while (!unpacker.next(handle));
  const msgpack::object& object = handle.get();
  if (object.is_nil()) {
    throw std::runtime_error("No output for filter operation\n");
  }
  object.convert(output);
}

}  // namespace rdsp
