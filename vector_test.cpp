/**
 * @brief assert example vector
 * @file vector_test.cpp
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <vector>
#include <cassert>

// Testing vectors using assert
void testVectorResize01() {
  std::vector<int> v(5);

  assert(v.size() == 5);
  assert(v.capacity() >= 5);
  v.resize(10);

  assert(v.size() == 10);
  assert(v.capacity() >= 10);
}

// Testing vectors using assert
void testVectorResize02() {
  std::vector<int> v(5);

  assert(v.size() == 5);
  assert(v.capacity() >= 5);
  v.resize(0);

  assert(v.empty());
  assert(v.capacity() >= 5);
}

// Testing vectors using assert
void testVectorResize03() {
  std::vector<int> v(5);

  assert(v.size() == 5);
  assert(v.capacity() >= 5);
  v.reserve(10);

  assert(v.size() == 5);
  assert(v.capacity() >= 10);
}

// Testing vectors using assert
void testVectorResize04() {
  std::vector<int> v(5);

  assert(v.size() == 5);
  assert(v.capacity() >= 5);
  v.reserve(0);

  assert(v.size() == 5);
  assert(v.capacity() >= 5);
  // next test is intended to fail, fix it
  // assert(v.size() == -1);
}

void testVectorAll() {
  testVectorResize01();
  testVectorResize02();
  testVectorResize03();
  testVectorResize04();
}

