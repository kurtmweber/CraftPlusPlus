/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-10
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <cstdint>
#include <iostream>
#include <vector>

#ifndef _PROTOCOL_TYPES_TYPES_H
#define _PROTOCOL_TYPES_TYPES_H

namespace Protocol {
namespace Types {
class Boolean {
private:
  bool val;

public:
  Boolean &operator=(bool rhs);
  operator bool() const;
};

class Byte {
private:
  int8_t val;

public:
  Byte &operator=(int8_t rhs);
  operator int8_t() const;
};

class VarInt {

  friend std::ostream &operator<<(std::ostream &os, VarInt const &m);

private:
  int32_t val;
  std::vector<uint8_t> var_int;

public:
  VarInt &operator=(int32_t rhs);
};
} // namespace Types
} // namespace Protocol

#endif