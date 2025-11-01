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
#include <memory>
#include <queue>
#include <sys/socket.h>
#include <sys/time.h>
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

  timeval to = {0, 500};

  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &to, sizeof(to)) == -1) {
    throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
  }
  return;
}

Socket::Socket(int sf) {
  sockfd = sf;
  return;
}

std::unique_ptr<std::queue<std::byte>> Socket::Read(size_t num_bytes) {
  // replace this with std::inplace_vector once available
  // auto bytes = std::make_unique<std::queue<std::byte>>;

  std::unique_ptr<std::queue<std::byte>> bytes(new std::queue<std::byte>);
  std::byte tmp[num_bytes];
  ssize_t ret = 0;
  ssize_t sum = 0;

  while (sum < num_bytes) {

    ret = recv(sockfd, &tmp[sum], num_bytes - sum, MSG_WAITALL);

    if (ret == -1) {
      if (errno == EINTR) {
        continue;
      } else {
        throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
      }
    } else {
      sum += ret;
    }
  }

  for (auto i = 0; i < num_bytes; i++) {
    bytes->push(tmp[i]);
  }

  return bytes;
}

Socket::~Socket() { close(sockfd); }
} // namespace Socket
} // namespace Network