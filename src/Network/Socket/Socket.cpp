/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-16
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <cerrno>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

#include <Exceptions/Exceptions.h>
#include <Network/Socket/Socket.h>
#include <Protocol/Packet/Packet.h>

namespace Network {
namespace Socket {
Socket::Socket() {
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
  }
  return;
}

Socket::Socket(int sf) {
  sockfd = sf;
  return;
}

Protocol::Packet::Packet Socket::Read(size_t num_bytes) {
  // replace this with std::inplace_vector once available
  auto bytes = new std::byte[num_bytes];

  auto ret = recv(sockfd, bytes, num_bytes, 0);

  if (ret == -1) {
    throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
  }
}

Socket::~Socket() { close(sockfd); }
} // namespace Socket
} // namespace Network