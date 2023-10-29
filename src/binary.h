#ifndef _BINARY_H_
#define _BINARY_H_

#include <stdio.h>
#include <stdint.h>

#define BIN_PARITY_BEG 0
#define BIN_PARITY_END 1
#define BIN_PARITY_EVE 0
#define BIN_PARITY_ODD 1

/// @brief Print the binary sequence of the specified word
/// @param word_i Word to be printed in binary sequence
/// @param size_i Word dimensions in bytes
void bin_print(uint32_t word_i, size_t size_i);

/// @brief Get the binary sequence of the specified word as string
/// @param word_i Word to be converted to string
/// @param size_i Word dimensions in bytes
/// @param str_o Destination string for storing char binary sequence
void bin_stringify(uint32_t word_i, size_t size_i, char* str_o);

/// @brief Get the reversed binary sequence of the specified word
/// @param word_i Word to be reversed
/// @param size_i Word dimensions in bytes
/// @return Reversed binary sequence as unsigned integer
uint32_t bin_reverse(uint32_t word_i, size_t size_i);

/// @brief Check parity bit based on desired convention
/// @param word_i Word to be checked
/// @param size_i Word dimensions in bytes
/// @param pos_i Specifies if parity bit is the first or last bit in the sequence ('BEG' = 0 or 'END' = 1) 
/// @return Parity bit status (0 or 1)
uint8_t bin_check_parity(uint32_t word_i, size_t size_i, uint8_t pos_i);

/// @brief Evaluate parity bit based on desired convention
/// @param word_i Word to be checked
/// @param size_i Word dimensions in bytes
/// @param type_i Type of convention used for the binary sequence ('EVEN' = 0 or 'ODD' = 1)
/// @param pos_i Specifies if parity bit is the first or last bit in the sequence ('BEG' = 0 or 'END' = 1) 
/// @return Evaluated parity state
uint8_t bin_eval_parity(uint32_t word_i, size_t size_i, uint8_t type_i, uint8_t pos_i);

/// @brief Set parity bit based on desired convention
/// @param word_i Word to be processed
/// @param size_i Word dimensions in bytes
/// @param type_i Type of convention used for the binary sequence ('EVEN' = 0 or 'ODD' = 1)
/// @param pos_i Specifies if parity bit is the first or last bit in the sequence ('BEG' = 0 or 'END' = 1) 
/// @return Processed word with parity bit
uint32_t bin_set_parity(uint32_t word_i, size_t size_i, uint8_t type_i, uint8_t pos_i);


#endif /* _BINARY_H_ */