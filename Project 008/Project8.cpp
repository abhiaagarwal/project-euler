// Copyright 2017 <Abhi Agarwal>
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

constexpr uint16_t limit = 1000;
std::array<uint8_t, limit> getDigits();
uint32_t getProduct(const std::array<uint8_t, limit> &, const size_t &);

int main() {
  const auto digits = getDigits();
  uint32_t product = 1;
  for (size_t i = 0; i < limit; i++) {
    uint32_t temp = getProduct(digits, i);
    if (temp > product) {
      product = temp;
      std::cout << "New product is: " << product << std::endl;
    }
  }

  std::cout << "Greatest product is: " << product << std::endl;
  return 0;
}

std::array<uint8_t, limit> getDigits() {
  std::array<uint8_t, limit> digits;

  const std::string file_name = "numbers.txt";
  std::ifstream file(file_name);

  uint16_t index = 0;
  while (file) {
    char input;
    file >> input;
    if (index >= limit) {
      break;
    }
    if (input == '\n') {
      break;
    }
    digits[index] = static_cast<uint8_t>(input - '0');
    index++;
  }

  return digits;
}

uint32_t getProduct(const std::array<uint8_t, limit> &digits,
                    const size_t &offset) {
  constexpr uint16_t product_limit = 13;
  uint32_t product = 1;
  for (size_t i = 0; i < product_limit; i++) {
    size_t index = i + offset;
    if (index >= limit) {
      return product;
    }
    product *= digits[index];
  }
  return product;
}
