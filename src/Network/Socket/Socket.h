/* Creator: Kurt M. Weber
 *
 * Created on: 2025-09-16
 *
 * This file is part of CraftPlusPlus.
 *
 * Licensed under Hippocratic License with clauses:
 * HL3-CL-ECO-EXTR-FFD-MEDIA-MY-SUP-SV-TAL-USTA-XUAR See file LICENSE for full
 * licensing information.
 */

#include <cstdint>
#include <netinet/in.h>

namespace Network {
namespace Socket {
class Socket {
protected:
  int sockfd;

  Socket();
  ~Socket();
};

class Listener : Socket {
public:
  Listener(uint16_t port, uint32_t addr);
  ~Listener();
};
} // namespace Socket
} // namespace Network