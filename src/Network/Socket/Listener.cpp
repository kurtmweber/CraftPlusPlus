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
#include <future>
#include <iostream>
#include <poll.h>
#include <sys/socket.h>

#include <Exceptions/Exceptions.h>
#include <Network/Socket/Socket.h>

namespace Network {
namespace Socket {
void Listener::DoListen() {
  std::cout << "Test" << std::endl;
  return;
}

std::future<void> Listener::Listen() {
  std::future<void> fut;

  auto a = listen(sockfd, 500);
  if (a == -1) {
    throw Exceptions::SocketException(errno);
  }

  fut = std::async(&Listener::DoListen, this);

  return fut;
}

Listener::Listener(uint16_t port, uint32_t addr) : Socket() {
  sockaddr_in sa;

  sa.sin_family = AF_INET;
  sa.sin_port = htons(port);
  sa.sin_addr.s_addr = addr;
  auto a = bind(sockfd, reinterpret_cast<sockaddr *>(&sa), sizeof(sa));
  if (a == -1) {
    throw Exceptions::SocketException(errno);
  }

  return;
}
} // namespace Socket
} // namespace Network