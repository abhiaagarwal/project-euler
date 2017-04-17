// Copyright 2017 <Abhi Agarwal>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

bool isPalindrome(const uint32_t &multiple);

int main() {
  constexpr size_t lower = 100;
  constexpr size_t upper = 999;

  std::vector<uint32_t> numbers((upper - lower) + 1);
  std::iota(numbers.begin(), numbers.end(), lower);

  uint32_t larger = 0;
  for (const auto &i : numbers) {
    for (const auto &j : numbers) {
      uint32_t product = static_cast<uint32_t>(i * j);
      if (isPalindrome(product) & (product > larger)) {
        larger = product;
      }
    }
  }

  std::cout << "Larger is: " << larger << std::endl;
  return 0;
}

bool isPalindrome(const uint32_t &multiple) {
  uint32_t number = multiple;
  uint32_t reverse = 0;
  while (number != 0) {
    reverse = reverse * 10 + number % 10;
    ;
    number = number / 10;
  }
  return reverse == multiple;
}
