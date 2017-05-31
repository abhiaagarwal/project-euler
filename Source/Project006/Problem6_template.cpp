// Copyright 2017 <Abhi Agarwal>
#include <cstddef>
#include <cstdint>
#include <iostream>

template<size_t T>
constexpr uint64_t square_sum() {
  return (T * (T+ 1) * (2 * T + 1)) / 6;
}

template <size_t T>
constexpr uint64_t squared_sum() {
  return (T * T * (T+1) * (T+1)) / 4;
}

int main() {
  std::cout << squared_sum<100>() - square_sum<100>() << std::endl;
  return 0;
}
