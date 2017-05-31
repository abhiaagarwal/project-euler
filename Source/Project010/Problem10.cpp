// Copyright 2017 <Abhi Agarwal>
#include <cstdint>
#include <iostream>
#include <map>

std::map<uint32_t, bool> makeMap(const size_t&, const size_t&);
std::map<uint32_t, bool> seive(std::map<uint32_t, bool>);
uint64_t sum(const std::map<uint32_t, bool>&);

int main() {
  constexpr size_t upper = 2000000;
  constexpr size_t bottom = 2;

  std::cout << "Sum is: " << sum(seive(makeMap(bottom, upper))) << std::endl;

  return 0;
}

std::map<uint32_t, bool> seive(std::map<uint32_t, bool> numbers) {
  const auto last = numbers.rbegin()->first;

  for (auto iter = numbers.begin(); (iter->first * iter->first) <= last;
       iter++) {
    if (iter->second) {
      for (size_t i = (iter->first * 2); i <= last; i += iter->first) {
        numbers[static_cast<uint32_t>(i)] = false;
      }
    }
  }
  return numbers;
}

std::map<uint32_t, bool> makeMap(const size_t& bottom, const size_t& upper) {
  std::map<uint32_t, bool> numbers;
  for (size_t i = bottom; i < upper; i++) {
    numbers.insert(std::make_pair(i, true));
  }

  return numbers;
}

uint64_t sum(const std::map<uint32_t, bool>& primes) {
  uint64_t sum = 0;
  for (const auto &iter : primes) {
    if (iter.second) {
      sum += static_cast<uint64_t>(iter.first);
    }
  }
  return sum;
}
