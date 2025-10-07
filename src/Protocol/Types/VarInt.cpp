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

#include <cstdint>
#include <cstring>
#include <format>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include <Protocol/Protocol.h>
#include <Protocol/Types/Types.h>

namespace Protocol {
namespace Types {
std::ostream &operator<<(std::ostream &os, VarInt const &rhs) {
  std::string str = "";

  for (auto i = 0; i < rhs.var_int.size(); i++) {
    if (i > 0) {
      str.append(" ");
    }
    str.append(std::format("{:#04x}", rhs.var_int[i]));
  }

  if (str.length() > 0) {
    str.append(" ");
  }
  return os << str;
}

VarInt &VarInt::operator=(int32_t rhs) {
  uint8_t byte = 0;
  uint32_t u_rhs = 0;

  this->var_int.clear();

  this->val = rhs;
  u_rhs = static_cast<uint32_t>(rhs);

  do {
    byte = static_cast<uint32_t>(u_rhs & 0x7F);
    u_rhs >>= 7;
    if (u_rhs) {
      byte |= 0x80;
    }
    this->var_int.push_back(byte);
  } while (u_rhs);

  return *this;
}

VarInt &VarInt::operator=(std::vector<uint8_t> vi) {
  uint8_t b;
  int32_t tmp;
  int i = 0;
  for (int i = 0; i < vi.size(); i++) {
    b = vi[i];
    tmp |= ((b & 0x7F) << (i * 7));

    if (!(b & 0x80)) {
      break;
    }
  }

  val = tmp;
  var_int = vi;

  return *this;
}

VarInt &VarInt::operator<<(Protocol &rhs) {
  int32_t tmp;
  std::vector<uint8_t> vi;

  uint8_t inb = static_cast<uint8_t>(rhs.Read());
  vi.push_back(inb);
  while (inb & 0x80) {
    uint8_t inb = static_cast<uint8_t>(rhs.Read());
    vi.push_back(inb);
  }

  *this = vi;

  return *this;
}

VarInt::operator int32_t() { return val; }
} // namespace Types
} // namespace Protocol