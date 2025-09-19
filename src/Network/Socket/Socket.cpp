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

#include <sys/socket.h>
#include <unistd.h>

#include <Network/Socket/Socket.h>

namespace Network {
namespace Socket {
Socket::Socket() {
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  return;
}

Socket::~Socket() { close(sockfd); }
} // namespace Socket
} // namespace Network