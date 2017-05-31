// Copyright 2017 <Abhi Agarwal>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>

uint16_t getDigits(const uint32_t &);
uint32_t shuffleDigits(const uint32_t &, const uint16_t &, const size_t &);
bool isCircularPrime(const uint32_t &);
bool isPrime(const uint32_t &);

int main() {
  constexpr uint32_t limit = 1000000;
  size_t counter = 0;

  for (size_t i = 2; i < limit; i++) {
    if (isCircularPrime(static_cast<uint32_t>(i))) {
      counter++;
    }
  }
  std::cout << "Counter is: " << counter << std::endl;
  return 0;
}

uint16_t getDigits(const uint32_t &number) {
  return static_cast<uint16_t>(std::floor(std::log10(number)) + 1);
}

bool isCircularPrime(const uint32_t &number) {
  const uint16_t digits = getDigits(number);

  if (digits <= 1) {
    return isPrime(number);
  }

  for (size_t i = 0; i < digits; i++) {
    if (!isPrime(shuffleDigits(number, digits, i))) {
      return false;
    }
  }
  return true;
}

uint32_t shuffleDigits(const uint32_t &number, const uint16_t &digits,
                       const size_t &offset) {
  if (offset <= 0) {
    return number;
  }

  const uint32_t power_of_ten = static_cast<uint32_t>(std::pow(10, offset));
  const uint32_t remainder = number % power_of_ten;
  const uint16_t remainder_digits = getDigits(remainder);
  const uint32_t remainder_multiplier =
      static_cast<uint32_t>(std::pow(10, digits - remainder_digits));
  const uint32_t new_digits =
      static_cast<uint32_t>(std::floor(number / power_of_ten));
  const uint32_t new_number = remainder * remainder_multiplier + new_digits;

  return new_number;
}

bool isPrime(const uint32_t &number) {
  static std::map<uint32_t, bool> prime_map;

  const auto iter = prime_map.find(number);
  if (iter != prime_map.end()) {
    return iter->second;
  }

  if (number == 2) {
    prime_map.insert(std::make_pair(2, true));
    return true;
  }
  if (number % 2 == 0) {
    prime_map.insert(std::make_pair(number, false));
    return false;
  }

  for (size_t i = 3; i * i <= number; i += 2) {
    if (number % i == 0) {
      prime_map.insert(std::make_pair(number, false));
      return false;
    }
  }
  prime_map.insert(std::make_pair(number, true));
  return true;
}
