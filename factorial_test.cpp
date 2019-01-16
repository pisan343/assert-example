/**
 * @brief assert example factorial
 * @file factorial_test.cpp
 *
 * @author Yusuf Pisan
 * @date 7 Dec 2018
 */

#include <cassert>

//  Calculate factorial
unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

void testFactorialAll() {
  assert(Factorial(1) == 1);
  assert(Factorial(2) == 2);
  assert(Factorial(3) == 6);
  assert(Factorial(10) == 3628800);
  // next test is intended to fail, fix it
  // assert(Factorial(2) == -1);
  assert(Factorial(1) == 1);
  // next test is intended to fail, fix it
  // assert(Factorial(3) == -1);
}
