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

#include <cstring>
#include <stdexcept>
#include <string>

#include <Exceptions/Exceptions.h>

namespace Exceptions {
SocketException::SocketException(std::string_view msg)
    : std::runtime_error(static_cast<std::string>(msg)) {
  return;
}

SocketException::SocketException(int e) : std::runtime_error(std::strerror(e)) {
  return;
}
} // namespace Exceptions