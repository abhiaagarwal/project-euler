// Copyright 2017 <Abhi Agarwal>
#include <cstdint>
#include <iostream>
#include <map>

uint32_t collatz(uint32_t);

int main() {
  constexpr uint32_t limit = 1000000;
  size_t max_length = 0;
  size_t max_num = 0;

  for (size_t i = 2; i < limit; i++) {
    uint32_t current_num = static_cast<uint32_t>(i);
    size_t j;
    for (j = 1; current_num > 1; j++) {
      current_num = collatz(current_num);
    }
    if (j > max_length) {
      max_length = j;
      max_num = i;
    }
  }

  std::cout << "Number is: " << max_num << ", Length is: " << max_length
            << std::endl;
  return 0;
}

uint32_t collatz(uint32_t number) {
  if (number % 2 == 0) {
    return number / 2;
  } else {
    return 3 * number + 1;
  }
}
