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

#include <Protocol/Types/Types.h>

namespace Protocol {
namespace Types {
Boolean &Boolean::operator=(bool &src) {
  val = src;
  return *this;
}

Boolean::operator bool() const { return val; }
} // namespace Types
} // namespace Protocol