/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-20
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <stdexcept>
#include <string>

namespace Exceptions {
class SocketException : public std::runtime_error {
public:
  SocketException(std::string_view msg);
  SocketException(int e);
};
} // namespace Exceptions