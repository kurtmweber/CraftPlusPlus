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

#ifndef _NETWORK_SOCKET_H
#define _NETWORK_SOCKET_H

#include <cstdint>
#include <future>
#include <netinet/in.h>
#include <sys/socket.h>

namespace Network {
namespace Socket {
class Socket {
protected:
  int sockfd;

  sockaddr_in local;
  sockaddr_in remote;

  Socket();
  Socket(int sf);
  ~Socket();

public:
  template <typename T> T Read() {
    const size_t num_bytes = sizeof(T);
    T buf;

    recv(sockfd, &buf, num_bytes, MSG_WAITALL);

    return buf;
  }
};

class Connected : public Socket {
public:
  Connected(int sf);
  Connected(int sf, sockaddr_in remote_addr);
  ~Connected();
};

class Listener : public Socket {
public:
  Listener(uint16_t port, uint32_t addr);
  std::future<void> *Listen();

private:
  void DoListen();
};
} // namespace Socket
} // namespace Network

#endif