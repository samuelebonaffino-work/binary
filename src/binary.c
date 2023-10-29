#include "binary.h"

void bin_print(uint32_t word_i, size_t size_i)
{
  size_t size = size_i * 8 - 1;

  for(uint32_t mask = 1 << size; mask > 0; mask /= 2)
  {
    (word_i & mask) ? printf("1") : printf("0");
  }
  printf("\n");
}

void bin_stringify(uint32_t word_i, size_t size_i, char* str_o)
{
  for(uint32_t bit_mask = 1 << (size_i * 8 - 1), i = 0; bit_mask > 0; bit_mask /= 2, i++)
  {
    str_o[i] = (word_i & bit_mask) ? '1' : '0';
  }
  str_o[size_i * 8] = '\0';
}

uint32_t bin_reverse(uint32_t word_i, size_t size_i)
{
  uint32_t word_o = 0;
  size_t size = size_i * 8 - 1;

  for(uint32_t mask = 1 << size, pos = size; mask > 0; mask /= 2, pos--)
  {
    word_o += (word_i & mask) ? 1 << (size - pos) : 0;
  }

  return word_o;
}

uint8_t bin_check_parity(uint32_t word_i, size_t size_i, uint8_t pos_i)
{
  uint32_t word = pos_i == BIN_PARITY_BEG ? word_i : bin_reverse(word_i, size_i);
  return (word & (1 << (size_i * 8 - 1))) ? 1 : 0;
}

uint8_t bin_eval_parity(uint32_t word_i, size_t size_i, uint8_t type_i, uint8_t pos_i)
{
  size_t size = size_i * 8 - 1;
  uint8_t counter = 0;
  uint32_t mask_0 = (1 << size) - 1;
  uint32_t word = (pos_i == BIN_PARITY_BEG) ? (word_i & mask_0) : (bin_reverse(word_i, size_i) & mask_0);

  for(uint32_t bit_mask = 1 << size; bit_mask > 0; bit_mask /= 2)
  {
    counter += (word & bit_mask) ? 1 : 0;
  }

  return ((counter + type_i) % 2) ? 1 : 0;
}

uint32_t bin_set_parity(uint32_t word_i, size_t size_i, uint8_t type_i, uint8_t pos_i)
{
  size_t size = size_i * 8 - 1;
  uint32_t mask_0 = (1 << size) - 1;
  uint32_t mask_1 = 1 << size;
  uint32_t word_o = (pos_i == BIN_PARITY_BEG) ? (word_i & mask_0) : (bin_reverse(word_i, size_i) & mask_0);

  word_o = bin_eval_parity(word_i, size_i, type_i, pos_i) ? (word_o | mask_1) : word_o;

  return (pos_i == BIN_PARITY_BEG) ? word_o : (bin_reverse(word_o, size_i));
}
