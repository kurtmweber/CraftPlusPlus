/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-30
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <Network/Socket/Socket.h>
#include <Protocol/Packet/Packet.h>
#include <Protocol/Protocol.h>
#include <Protocol/Types/Types.h>

namespace Protocol {
Protocol::Protocol(Network::Socket::Connected &sock) : socket(sock) {
  state = State::HANDSHAKING;
  return;
}

void Protocol::Run() { return; }
} // namespace Protocol