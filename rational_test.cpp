/**
 * @brief asssert tests for rational class
 * @file rational_test.cpp
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */


#include <sstream>
#include <cassert>
#include "rational.h"

using namespace std;

// Testing vectors using assert
void testRationalConstructor() {
  Rational rempty;
  Rational r3(3);
  Rational r35(3, 5);
  Rational r3050(30, 50);
  assert(rempty.getNumerator() == 0);
  assert(rempty.getDenominator() == 1);
  assert(r3.getNumerator() == 3);
  assert(r3.getDenominator() == 1);
  assert(r35.getNumerator() == 3);
  assert(r35.getDenominator() == 5);
  assert(r3050.getNumerator() == 3);
  assert(r3050.getDenominator() == 5);
}

// Testing vectors << and >> operators
void testRationalInsertExtract() {
  ostringstream out;
  istringstream is;
  Rational r3(3);
  Rational r35(3, 5);
  operator<<(out, r3);
  assert(out.str() == "3");

  out.str("");
  operator<<(out, r35);
  assert(out.str() == "3/5");

  is.str("12 30");
  Rational r23;
  operator>>(is, r23);
  assert(r23.getNumerator() == 2);
  assert(r23.getDenominator() == 5);
}

// Testing vectors math
void testRationalMath() {
  // add
  {
    Rational r12(1, 2);
    Rational r23(2, 3);
    Rational r = r12 + r23;
    assert(r.getNumerator() == 7);
    assert(r.getDenominator() == 6);

    r12 += r23;
    assert(r == r12);
  }

  // subtract
  {
    Rational r12(1, 2);
    Rational r23(2, 3);
    Rational r = r12 - r23;
    assert(r.getNumerator() == -1);
    assert(r.getDenominator() == 6);

    r12 -= r23;
    assert(r == r12);
  }

  // multiply
  {
    Rational r12(1, 2);
    Rational r23(2, 3);
    Rational r = r12 * r23;
    assert(r.getNumerator() == 1);
    assert(r.getDenominator() == 3);

    r12 *= r23;
    assert(r == r12);
  }

  // divide
  {
    Rational r12(1, 2);
    Rational r23(2, 3);
    Rational r = r12 / r23;
    assert(r.getNumerator() == 3);
    assert(r.getDenominator() == 4);

    r12 /= r23;
    assert(r == r12);
  }
}

// Testing vectors compare
void testRationalCompare() {
  Rational r12(1, 2);
  Rational r23(2, 3);
  Rational r2030(20, 30);
  assert(r12 < r23);
  assert(r12 <= r23);
  assert(r12 != r23);
  assert(r23 > r12);
  assert(r23 >= r12);
  assert(r23 == r2030);
}

// Run all vector tests
void testRationalExtras() {
  ostringstream out;
  Rational r125(12, 5);
  Rational r23(2, 3);
  Rational r46(4, 6);

  auto itwo = static_cast<int>(r125);
  assert(itwo == 2);

  auto izero = static_cast<int>(r23);
  assert(izero == 0);

  Rational r = r23 - r46;
  operator<<(out, r);
  assert(out.str() == "0");

  Rational rerr = r125 / r;
  out.str("");
  operator<<(out, rerr);
  assert(out.str() == "\nDIVIDE BY ZERO ERROR!!!\n");
}

void testRationalAll() {
  testRationalConstructor();
  testRationalInsertExtract();
  testRationalMath();
  testRationalCompare();
  testRationalExtras();
}
