// Copyright 2017 <Abhi Agarwal>
// WIP
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <experimental/string_view>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

// Constants
// These mean that the size constants are compile time not run time
constexpr size_t num_length = 50;
constexpr size_t num_numbers = 100;

// Typedefs
// These makes things easier to read
using numbers_t = std::array<uint16_t, num_length>;
using numbers_array_t = std::array<numbers_t, num_numbers>;
using sum_t = std::list<uint16_t>;

// Function Prototypes
// This is good practice
numbers_array_t readFile();
numbers_t lineToDigits(const std::experimental::string_view &);
sum_t getSum(const numbers_array_t &);
void readSum(const sum_t &);

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

  /*

  for (size_t i = 0; i < num_numbers; i++) {
    for (size_t j = 0; j < num_length; j++) {
      const auto cell = numbers[i][j];
      std::cout << "numbers[" << i << "][" << j << "] is " << cell << std::endl;
    }
  }

  */

  const auto sum = getSum(numbers);
  // readSum(sum);

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
    std::string input = "";
    std::getline(file, input);
    numbers[i] = lineToDigits(input);
  }

  return numbers;
}

numbers_t lineToDigits(const std::experimental::string_view &number) {
  numbers_t digits;
  for (size_t i = 0; i < number.size(); i++) {
    digits[i] = static_cast<uint16_t>(std::atoi(&number[i]));
  }
  return digits;
}

sum_t getSum(const numbers_array_t &numbers) {
  sum_t sum;

  uint16_t remainder = 0;
  for (size_t i = 0; i < num_length; i++) {
    uint16_t temp_sum = 0;
    for (size_t j = 0; j < num_numbers; j++) {
      /*
      In theory, the first cell will be: numbers[0][49]
      The second cell will be: numbers[1][49]
      The third cell will be: numbers[2][49]
      It will end with [99][49]
      Then, it goes to [0][48]
      etc...
      */
      const uint16_t cell = numbers[j][(num_length - 1) - i];
      std::cout << "numbers[" << j << "][" << (num_length - 1) - i
                << "] is " << cell << std::endl;
      temp_sum += cell;
    }
    std::cout << std::endl;
    // Take the Remainder of the Previous Sum and add it to the current one.
    temp_sum += remainder;

    // Push front the first digit of the Temp Sum by taking the modulus.
    sum.push_front(temp_sum % 10);

    // The remainder is the number without the first digit.
    remainder = static_cast<uint16_t>(std::floor(temp_sum / 10));
  }

  // Push front the remaining digits
  while (remainder > 1) {
    sum.push_back(remainder % 10);
    remainder /= 10;
  }

  return sum;
}

void readSum(const sum_t &sum) {
  for (const auto &digit : sum) {
    std::cout << digit;
  }
  std::cout << std::endl;
}
