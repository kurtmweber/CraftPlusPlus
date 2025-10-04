/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-28
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <netinet/in.h>
#include <sys/socket.h>

#include <Network/Socket/Socket.h>

namespace Network {
namespace Socket {
Connected::Connected(int sf) : Socket(sf) { return; }

Connected::Connected(int sf, sockaddr_in remote_addr) : Socket(sf) {
  remote = remote_addr;
  return;
}
} // namespace Socket
} // namespace Network