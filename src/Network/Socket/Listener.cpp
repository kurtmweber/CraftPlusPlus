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
  // we poll rather than loop on accept because poll allows us to specify a
  // timeout, which we take advantage of to periodically check for messages
  // since C++'s futures library doesn't actually provide a mechanism for
  // interrupting threads
  pollfd pfd = {sockfd, POLLIN, 0};

  while (1) {
    auto ret = poll(&pfd, 1, 5000);
    if (ret) {
      accept(sockfd, nullptr, nullptr);
      std::cout << "Accepted!" << std::endl;
    } else {
      // Check for any messages we may need to check on
    }
  }
  return;
}

std::future<void> *Listener::Listen() {
  auto fut = new std::future<void>;

  auto a = listen(sockfd, 500);
  if (a == -1) {
    throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
  }

  *fut = std::async(&Listener::DoListen, this);

  return fut;
}

Listener::Listener(uint16_t port, uint32_t addr) : Socket() {
  sockaddr_in sa;

  sa.sin_family = AF_INET;
  sa.sin_port = htons(port);
  sa.sin_addr.s_addr = addr;
  auto a = bind(sockfd, reinterpret_cast<sockaddr *>(&sa), sizeof(sa));
  if (a == -1) {
    throw Exceptions::SocketException(errno, __FILE__, __func__, __LINE__);
  }

  return;
}
} // namespace Socket
} // namespace Network