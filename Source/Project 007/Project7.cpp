// Copyright 2017 <Abhi Agarwal>
// WIP
#include <iostream>

bool isPrime(const uint64_t &);

int main() {
  constexpr size_t limit = 100001;
  size_t counter = 0;
  size_t i;
  for (i = 1; counter != limit; i++) {
    if (isPrime(i)) {
      std::cout << "Found Prime: " << i << std::endl;
      counter++;
    }
  }
  std::cout << "Number is: " << i <<std::endl;
  return 0;
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
