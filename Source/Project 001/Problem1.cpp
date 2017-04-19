// Copyright 2017 <Abhi Agarwal>
#include <iostream>

bool isMultiple(const uint32_t &);

int main() {
  constexpr size_t limit = 1000;
  size_t counter = 0;
  for (size_t i = 0; i < limit; i++) {
    if (isMultiple(static_cast<uint32_t>(i))) {
      counter += i;
    }
  }

  std::cout << "Final Number: " << counter << std::endl;

  return 0;
}

bool isMultiple(const uint32_t &number) {
  return (number % 3 == 0 || number % 5 == 0);
}
