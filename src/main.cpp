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
#include <chrono>
#include <cstdint>
#include <iostream>
#include <thread>

#include <Network/Socket/Socket.h>
#include <Protocol/Types/Types.h>

int main(int argc, char *argv[]) {
  auto l = new Network::Socket::Listener(25536, INADDR_ANY);

  l->Listen();

  std::cout << "Listening" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(69000));
  std::cout << "Slept" << std::endl;

  return 0;
}