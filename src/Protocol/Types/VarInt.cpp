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
#include <format>
#include <stdexcept>
#include <string>
#include <vector>

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
} // namespace Types
} // namespace Protocol