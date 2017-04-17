#include <iostream>

bool isMultiple(size_t number) {
  return (number % 3 == 0 || number % 5 == 0);
}

int main ( ) {
  constexpr size_t MAX_NUMBER = 1000;
  size_t counter = 0;
  for ( size_t i = 0 ; i < MAX_NUMBER ; i++ ) {
    if ( isMultiple(i) ) {
      counter += i;
    }
  }

  std::cout << "Final Number: " << counter << std::endl;

  return 0;
}
