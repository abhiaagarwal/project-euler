// Copyright 2017 <Abhi Agarwal>

#include <array>
#include <fstream>
#include <iostream>

template <typename T, uint16_t x, uint16_t y>
using squarearray_t = std::array<std::array<T, x>, y>;

enum class dimensions: uint16_t {
  x = 20,
  y = 20
};

squarearray_t<uint16_t, dimensions::x, dimensions::y> makeArray(const std::ifstream &);

int main() {
  std::ifstream file("numbers.txt");

  return 0;
}
