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
  Cause(e);
  return;
}

SocketException::SocketException(int e, std::string file, std::string func,
                                 unsigned long line)
    : std::runtime_error(static_cast<std::string>(std::strerror(e)) + " in " +
                         file + ", line " + std::to_string(line) + ", " +
                         func) {
  Cause(e);
  return;
}

SocketExceptionTypes SocketException::Cause() { return ExceptionCause; }

void SocketException::Cause(int cause) {
  // per POSIX, either of these error codes can be returned for the same
  // underlying error, and it is not guaranteed that they will have the same
  // value, so we have to account for both.
  if ((cause == EAGAIN) || (cause == EWOULDBLOCK)) {
    cause = EWOULDBLOCK;
  }

  ExceptionCause = static_cast<SocketExceptionTypes>(cause);

  return;
}
} // namespace Exceptions