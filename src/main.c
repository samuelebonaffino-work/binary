#include <stdio.h>

#include "binary.h"

int main(void)
{
  //UINT8
  uint8_t w8_i = 0b10011100;
  printf("w8_i = "); bin_print(w8_i, sizeof(w8_i));
  uint8_t w8_o = bin_set_parity(w8_i, sizeof(w8_i), BIN_PARITY_ODD, BIN_PARITY_BEG);
  printf("w8_o = "); bin_print(w8_o, sizeof(w8_o));
  printf("parity = %d\n", bin_check_parity(w8_o, sizeof(w8_o), BIN_PARITY_BEG));
  printf("\n");

  //UINT16
  uint16_t w16_i = 0b00001111 << 8;
  printf("w16_i = "); bin_print(w16_i, sizeof(w16_i));
  uint16_t w16_o = bin_set_parity(w16_i, sizeof(w16_i), BIN_PARITY_ODD, BIN_PARITY_BEG);
  printf("w16_o = "); bin_print(w16_o, sizeof(w16_o));
  printf("parity = %d\n", bin_check_parity(w16_o, sizeof(w16_o), BIN_PARITY_BEG));
  printf("\n");

  //UINT32
  uint32_t w32_i = 0b10111111 << 24;
  printf("w32_i = "); bin_print(w32_i, sizeof(w32_i));
  uint32_t w32_o = bin_set_parity(w32_i, sizeof(w32_i), BIN_PARITY_ODD, BIN_PARITY_BEG);
  printf("w32_o = "); bin_print(w32_o, sizeof(w32_o));
  printf("parity = %d\n", bin_check_parity(w32_o, sizeof(w32_o), BIN_PARITY_BEG));
  printf("\n");

  return 0;
}
