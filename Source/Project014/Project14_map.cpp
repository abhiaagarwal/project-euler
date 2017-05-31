// Copyright 2017 <Abhi Agarwal>
// WIP
#include <cstdint>
#include <iostream>
#include <unordered_map>

uint32_t collatz(uint32_t);
size_t collatzLength(const uint32_t &);

int main() {
  constexpr uint32_t limit = 1000000;
  size_t max_length = 0;
  size_t max_num = 0;

  for (size_t i = 2; i < limit; i++) {
    size_t length = collatzLength(static_cast<uint32_t>(i));
    if (length > max_length) {
      max_length = length;
      max_num = i;
    }
  }

  std::cout << "Number is: " << max_num << ", Length is: " << max_length
            << std::endl;
  return 0;
}

uint32_t collatz(uint32_t number) {
  return (number % 2 == 0) ? number / 2 : 3 * number + 1;
}

size_t collatzLength(const uint32_t &number) {
  // Number, Length
  static std::unordered_map<uint32_t, size_t> collatz_map;
  auto temp_num = number;

  //std::cout << "Number is: " << number << std::endl;

  size_t i;
  for (i = 1; temp_num > 1; i++) {
    temp_num = collatz(temp_num);
    //std::cout << "Temp num is: " << temp_num << std::endl;

    if (const auto &iter = collatz_map.find(temp_num); iter != collatz_map.end()) {
      //std::cout << "Found repeat!" << std::endl;
      collatz_map.insert(std::make_pair(number, i + iter->first));
      return i + iter->first;
    }
  }

  collatz_map.insert(std::make_pair(number, i));
  return i;
}
