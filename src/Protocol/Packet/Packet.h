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

#ifndef _PROTOCOL_PACKET_PACKET_H
#define _PROTOCOL_PACKET_PACKET_H

#include <memory>
#include <queue>
#include <string>
namespace Protocol {
namespace Packet {

enum class PacketType { UNKNOWN, HANDSHAKE = 0 };
class Packet {
public:
  Packet(std::queue<std::byte> &rd);
  virtual ~Packet();
  PacketType Type;

  static std::unique_ptr<Packet> PacketFactory(std::queue<std::byte> &raw);

protected:
  std::queue<std::byte> raw;
};

class HandshakePacket : public Packet {
public:
  HandshakePacket(std::queue<std::byte> &rd);

private:
  int32_t ProtocolVersion;
  std::string ServerAddress;
  uint16_t Port;
  enum class HandshakeIntent { STATUS = 1, LOGIN = 2, TRANSFER = 3 } Intent;
};

class Handshake : public Packet {};
} // namespace Packet
} // namespace Protocol

#endif