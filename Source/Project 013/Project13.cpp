// Copyright 2017 <Abhi Agarwal>
// WIP
#include <array>
#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

constexpr size_t num_length = 50;
constexpr size_t num_numbers = 100;

using numbers_array_t =
    std::array<std::array<uint8_t, num_length>, num_numbers>;

numbers_array_t readFile();
std::array<uint8_t, num_length> lineToDigits(const std::string &);
std::list<uint8_t> getSum(const numbers_array_t &);

int main() {
  const auto numbers = readFile();

  /*
  for (const auto &number : numbers) {
    for (const auto &digit : number) {
      std::cout << digit;
    }
    std::cout << std::endl;
  }
  */
  const auto sum = getSum(numbers);

  return 0;
}

numbers_array_t readFile() {
  numbers_array_t numbers;

  const std::string file_name = "numbers.txt";
  std::ifstream file(file_name);

  for (size_t i = 0; file; i++) {
    if (i >= num_numbers) {
      break;
    }
    std::string input;
    std::getline(file, input);
    numbers[i] = lineToDigits(input);
  }

  return numbers;
}

std::array<uint8_t, num_length> lineToDigits(const std::string &number) {
  std::array<uint8_t, num_length> digits;
  for (size_t i = 0; i < number.size(); i++) {
    char temp = number[i];
    digits[i] = static_cast<uint8_t>(temp);
  }
  return digits;
}

std::list<uint8_t> getSum(const numbers_array_t &numbers) {
  std::list<uint8_t> sum;
  uint16_t temp_sum = 0;
  uint16_t remainder = 0;
  for (size_t i = 0; i < numbers.size(); i++) {
    temp_sum = 0;
    std::cout << "Sums: ";
    for (size_t j = 0; j < num_numbers; j++) {
      const uint8_t cell = numbers[j][numbers.size() - 1 - i];
      temp_sum += cell;
      std::cout << temp_sum << ", " << std::endl;
    }
    temp_sum += remainder;
    remainder = static_cast<uint8_t>(std::floor(temp_sum / 10));
    sum.push_front(temp_sum % 10);
    std::cout << std::endl;
  }

  return sum;
}
