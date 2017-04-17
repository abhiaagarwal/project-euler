// Copyright 2016 <Abhi Agarwal>
#include <cstdint>
#include <iostream>
#include <vector>

uint16_t getNumFactors(const uint64_t &);
uint64_t getNTriangleNumber(const uint64_t &);

int main() {
  constexpr uint16_t limit = 500;
  bool success = false;
  uint32_t number = 0;
  for (size_t i = 1; !success; i++) {
    if (getNumFactors(getNTriangleNumber(static_cast<uint64_t>(i))) >= limit) {
      number = static_cast<uint32_t>(i);
      success = true;
    }
  }
  std::cout<<"The Number is: "<<number<<std::endl;
  return 0;
}

uint16_t getNumFactors(const uint64_t& number) {
  /* This algorithm is horribly ineffecient and will probably shame
  my ancestors and descendants for several generations to come but
  it's all I got right now.
  */
  uint16_t counter = 0;
  for (size_t i = 1; i <= number; i++) {
    if (number % i == 0) {
      counter++;
    }
  }
  std::cout<<"Number of Factors for "<<number<<" is: "<<counter<<std::endl;
  return counter;
}

uint64_t getNTriangleNumber(const uint64_t &n) {
  // It's a simple algorithm.
  return ((n) * (n + 1) / 2);
}
