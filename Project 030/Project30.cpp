// Copyright 2017 <Abhi Agarwal>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

std::vector<uint8_t> decomposeDigits(uint64_t);
uint64_t FivePowDigitSum(const std::vector<uint8_t> &);

int main() {
  // I don't know if there's a max, so I'll just numeric limits.
  uint64_t temp_sum = 0;
  for (size_t i = 2; i < std::numeric_limits<size_t>::max(); i++) {
    if (i == FivePowDigitSum(decomposeDigits(i))) {
      std::cout << "Found number: " << i << std::endl;
      temp_sum += i;
      std::cout << "Current Sum is: "<<temp_sum <<std::endl;
    }
  }
  return 0;
}

std::vector<uint8_t> decomposeDigits(uint64_t number) {
  std::vector<uint8_t> digits;
  while (number > 0) {
    digits.push_back(number % 10);
    number /= 10;
  }
  return digits;
}

uint64_t FivePowDigitSum(const std::vector<uint8_t> &digits) {
  constexpr uint8_t power = 5;
  uint64_t temp_sum = 0;
  for (const auto &digit : digits) {
    temp_sum += std::pow(digit, power);
  }
  return temp_sum;
}
