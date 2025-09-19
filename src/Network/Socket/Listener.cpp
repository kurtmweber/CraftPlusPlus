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

#include <Network/Socket/Socket.h>

namespace Network {
namespace Socket {
Listener::Listener(uint16_t port, uint32_t addr) {
  sockaddr_in sa;

  sa.sin_family = AF_INET;
  sa.sin_port = htons(25565);
  sa.sin_addr.s_addr = INADDR_ANY;
  bind(sockfd, reinterpret_cast<sockaddr *>(&sa), sizeof(sa));

  return;
}
} // namespace Socket
} // namespace Network