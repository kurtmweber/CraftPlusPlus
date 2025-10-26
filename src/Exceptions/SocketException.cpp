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
#include <errno.h>
#include <stdexcept>
#include <string>

#include <Exceptions/Exceptions.h>

namespace Exceptions {

SocketException::SocketException(std::string_view msg)
    : std::runtime_error(static_cast<std::string>(msg)) {
  return;
}

SocketException::SocketException(int e) : std::runtime_error(std::strerror(e)) {
  ExceptionCause = static_cast<SocketExceptionTypes>(e);
  return;
}

SocketException::SocketException(int e, std::string file, std::string func,
                                 unsigned long line)
    : std::runtime_error(static_cast<std::string>(std::strerror(e)) + " in " +
                         file + ", line " + std::to_string(line) + ", " +
                         func) {
  ExceptionCause = static_cast<SocketExceptionTypes>(e);
  return;
}

SocketExceptionTypes SocketException::Cause() { return ExceptionCause; }
} // namespace Exceptions