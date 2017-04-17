#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  constexpr size_t upper = 2000000;
  constexpr size_t lower = 2;

  std::vector<uint32_t> numbers((upper - lower) + 1);
  std::iota(numbers.begin(), numbers.end(), lower);

  uint64_t sum = 0;
  for(const auto& iter : numbers) {
  }

  return 0;
}
