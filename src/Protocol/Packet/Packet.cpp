/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-11
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <vector>

#include <Protocol/Packet/Packet.h>
#include <Protocol/Types/Types.h>

namespace Protocol {
namespace Packet {
std::unique_ptr<Packet> Packet::PacketFactory(std::queue<std::byte> &raw) {
  // Determine packet type
  Types::VarInt pt;
  pt << raw;

  std::unique_ptr<Packet> pack;

  switch ((PacketType)(int32_t)pt) {
  case PacketType::HANDSHAKE:
    auto hp = std::make_unique<HandshakePacket>(raw);
    pack = std::move(hp);
  }

  return pack;
}

Packet::Packet(std::queue<std::byte> &rd) {
  Type = PacketType::UNKNOWN;
  raw = rd;
  return;
}

Packet::~Packet() { return; }
} // namespace Packet
} // namespace Protocol