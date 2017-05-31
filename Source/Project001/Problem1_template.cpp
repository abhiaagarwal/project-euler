// Copyright 2017 <Abhi Agarwal>
#include <cstddef>
#include <cstdint>
#include <iostream>

template<size_t T>
constexpr uint32_t get_numbers() {
  uint32_t counter{0};
  for(size_t i{0}; i < T; i++) {
    if(i % 3 == 0 || i % 5 == 0) {
      counter += i;
    }
  }

  return counter;
}

int main() {
  std::cout << "Number is: " << get_numbers<1000>() << std::endl;
  return 0;
}
