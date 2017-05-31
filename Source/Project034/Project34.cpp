// Copyright 2017 <Abhi Agarwal>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

std::vector<uint8_t> decomposeDigits(uint64_t);
uint64_t factorialSum(const std::vector<uint8_t> &);
uint64_t factorial(const uint8_t &);

int main() {
  // We loop through std::numeric_limits because I don't know if there's a max.
  uint64_t temp_sum = 0;
  for (size_t i = 3; i < std::numeric_limits<size_t>::max(); i++) {
    if (i == factorialSum(decomposeDigits(i))) {
      std::cout << "Found number: " << i << std::endl;
      temp_sum += i;
      std::cout << "Current Sum is: " << temp_sum << std::endl;
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

uint64_t factorialSum(const std::vector<uint8_t> &digits) {
  uint64_t temp_sum = 0;
  for (const auto &digit : digits) {
    temp_sum += factorial(digit);
  }
  return temp_sum;
}

uint64_t factorial(const uint8_t &number) {
  if (number > 1) {
    return number * factorial(number - 1);
  } else {
    return 1;
  }
}
