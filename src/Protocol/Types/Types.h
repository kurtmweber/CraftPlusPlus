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

#ifndef _PROTOCOL_TYPES_TYPES_H
#define _PROTOCOL_TYPES_TYPES_H

namespace Protocol {
namespace Types {
class Boolean {
private:
  bool val;

public:
  Boolean &operator=(bool &src);
  operator bool() const;
};
} // namespace Types
} // namespace Protocol

#endif