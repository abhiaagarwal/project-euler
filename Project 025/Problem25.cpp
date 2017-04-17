#include <cmath>
#include <iostream>
#include <string>

/*
A Closed Version of Binet's Formula is [1/sqrt(5) * ((1+sqrt(5))/2)^n]
To get the n-th integer we have to take the log base 10 of it and add 1.
Therefore, we get log_10([1/sqrt(5) * ((1+sqrt(5))/2)^n])+1.
We can simplify this:
-1/2 * log_10(5) + nlog_10((1+sqrt(5))/2) + 1
*/

double getDigitsInNFib(const size_t &);

int main() {
  bool success = false;
  size_t i = 0;
  for (i = 2; !success; i++) {
    if (getDigitsInNFib(i) >= 1000) {
      success = true;
    }
  }

  std::cout << "Index is: " << i << std::endl;

  return 0;
}

double getDigitsInNFib(const size_t &n) {
  const double phi =
      3.236067977499789696409173668731276235440618359611525724270;
  const double shift =
      0.698970004336018804786261105275506973231810118537891458689;

  return (std::ceil(0.5 * (n * phi - shift))) + 1.0;
}
