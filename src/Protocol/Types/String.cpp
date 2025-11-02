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

#include <queue>
#include <string>

#include <Protocol/Types/Types.h>

namespace Protocol {
namespace Types {
String::String() { Contents.clear(); }
String &String::operator<<(std::queue<std::byte> &rhs) {
  Types::VarInt len;

  // pull the length of the string
  len << rhs;

  Contents.resize((size_t)len);

  for (int32_t i = 0; i < static_cast<int32_t>(len); i++) {
    Contents[i] = static_cast<char>(rhs.front());
    rhs.pop();
  }

  return *this;
}

String::operator std::string() { return Contents; }
} // namespace Types
} // namespace Protocol