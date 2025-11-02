/* Creator: Kurt M. Weber
 *
 * Created on: 2025-11-01
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <Protocol/Packet/Packet.h>
#include <Protocol/Types/Types.h>
#include <iostream>

namespace Protocol {
namespace Packet {
HandshakePacket::HandshakePacket(std::queue<std::byte> &rd) : Packet(rd) {
  Type = PacketType::HANDSHAKE;

  // protocol version
  Types::VarInt pv;
  pv << raw;

  // server address
  Types::String s;
  s << raw;
}
} // namespace Packet
} // namespace Protocol