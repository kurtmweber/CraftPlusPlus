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

#include <Protocol/Types/Types.h>
#include <iostream>

namespace Protocol {
namespace Types {
UnsignedShort &UnsignedShort::operator<<(std::queue<std::byte> &rhs) {
  // This value is sent big-endian over the wire
  // I THINK this should obviate the need to worry about network-to-host byte
  // order conversion, because we put the first byte (most significant) into the
  // logical high-order position of tmp in a manner that is agnostic to
  // in-memory ordering
  val = (static_cast<int16_t>(rhs.front()) << 8);
  rhs.pop();
  val += static_cast<int16_t>(rhs.front());

  return *this;
}

UnsignedShort::operator uint16_t() { return val; }
} // namespace Types
} // namespace Protocol