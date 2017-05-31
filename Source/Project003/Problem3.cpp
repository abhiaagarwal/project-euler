// Copyright 2017 <Abhi Agarwal>
#include <cstdint>
#include <iostream>

bool isPrime(const uint64_t &);

int main() {
  constexpr uint64_t number = 600851475143;
  uint64_t factor = 0;
  for (uint64_t i = 1; i * i < number; i++) {
    // Only checks against Square Root the factors
    if ((number % i == 0) && isPrime(i)) {
      factor = i;
    }
  }

  std::cout << "Factor is: " << factor << std::endl;
}

bool isPrime(const uint64_t &number) {
  // To be Optimized Later
  if (number <= 1)
    return false;
  if (number == 2)
    return true;
  if (number % 2 == 0)
    return false;

  for (uint64_t i = 3; i * i <= number; i += 2) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}
