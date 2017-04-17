// Copyright 2017 <Abhi Agarwal>
#include <iostream>
#include <vector>

uint32_t vectorSum(std::vector<uint32_t> &numbers);
bool isEven(const uint32_t &num);

int main() {
  std::vector<uint32_t> fib_numbers = {1, 2};

  constexpr size_t max = 4000000;

  for (size_t i = fib_numbers[1]; fib_numbers.back() < max; i++) {
    fib_numbers.push_back(fib_numbers[i - 1] + fib_numbers[i - 2]);
    std::cout << "Current Number: " << fib_numbers[i] << std::endl;
  }

  std::cout << std::endl
            << "Sum of Numbers is:" << vectorSum(fib_numbers) << std::endl;
}

uint32_t vectorSum(std::vector<uint32_t> &numbers) {
  uint32_t sum = 0;
  for (const auto &i : numbers) {
    if (isEven(i)) {
      sum += i;
    }
  }

  return sum;
}

bool isEven(const uint32_t &num) { return num % 2 == 0; }
