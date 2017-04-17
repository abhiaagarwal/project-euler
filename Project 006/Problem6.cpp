// Copyright 2017 <Abhi Agarwal>
#include <iostream>

uint32_t getSquareSum(const size_t &);
uint32_t getTotalSquare(const size_t &);

int main() {
  constexpr size_t limit = 100;

  const uint32_t square_sum = getSquareSum(limit);
  const uint32_t total_square = getTotalSquare(limit);

  std::cout << "The Differences is: " << total_square - square_sum << std::endl;

  return 0;
}

uint32_t getSquareSum(const size_t &limit) {
  uint32_t sum = 0;
  for (size_t i = 1; i <= limit; i++) {
    sum += i * i;
  }

  return sum;
}

uint32_t getTotalSquare(const size_t &limit) {
  uint32_t sum = 0;
  for (size_t i = 1; i <= limit; i++) {
    sum += i;
  }

  return sum * sum;
}
