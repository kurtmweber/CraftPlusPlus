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

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

namespace Protocol {
enum class State { HANDSHAKING, STATUS, LOGIN, CONFIGURATION, PLAY };
class Protocol {
private:
  Network::Socket::Connected &socket;

  State state;

public:
  Protocol(Network::Socket::Connected &sock);
  ~Protocol();

  std::byte Read();

  void Run();
};
} // namespace Protocol

#endif