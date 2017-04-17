// Copyright 2016 <Abhi Agarwal>

#include <iostream>
#include <vector>

class factor {
  private:
    int mNumber = 0;
    int mPower = 0;
  public:
    int getNumber() {
      return mNumber;
    }

    void setNumber(int tNumber) {
      mNumber = tNumber;
    }

    int getPower() {
      return mPower;
    }

    void setPower(int tPower) {
      mPower = tPower;
    }
};

class primeFactorization {
private:
  std::vector<factor>mFactors;
public:
  explicit primeFactorization(std::vector<factor>tFactors) : mFactors(tFactors)
  { }

  void addFactor(factor tFactor) {
    mFactors.push_back(tFactor);
  }

  int getNumberOfDivisors() {
    int product = 1;
    for(size_t i = 0; i < mFactors.size(); i++) {
      product *= (mFactors[i].getPower() + 1);
    }

    return product;
  }

};

std::vector<factor>primeFactorize(int number) {

}
