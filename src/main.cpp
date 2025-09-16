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

#include <Protocol/Types/Types.h>

int main(int argc, char *argv[]) {
  int32_t testvals[] = {0,     1,       2,          127, 128,        255,
                        25565, 2097151, 2147483647, -1,  -2147483648};
  Protocol::Types::VarInt vi;

  for (auto i = 0; i < sizeof(testvals) / sizeof(int32_t); i++) {
    vi = testvals[i];
    std::cout << vi;
    std::cout << std::endl;
  }

  return 0;
}