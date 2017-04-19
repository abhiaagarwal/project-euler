// Copyright 2017 <Abhi Agarwal>
// WIP
#include <cstdint>
#include <iostream>

int main() {
  // There's a purely mathematical way to do this, but I don't really care.
  constexpr size_t limit = 20;
  bool success = false;
  size_t i;
  for (i = limit; !success; i++) {
    for (size_t j = 1; j <= limit; j++) {
      if (i % j != 0) {
        break;
      }
      if (j == limit) {
        success = true;
      }
    }
  }
  std::cout << "Number is: " << i;
  return 0;
}
