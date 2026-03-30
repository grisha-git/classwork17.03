#include "top-it-vector.hpp"
#include <iostream>
#include <iomanip>

bool testEmptyVector()
{
  using namespace topit;
  Vector< int > v;
  return v.isEmpty();
}

bool testElementInBoundAccess()
{
  topit::Vector< int >v;
  v.pushBack(1);
  try
  {
    int& val = v.at(0);
    return val == 1;
  }
  catch(...)
  {
    return false;
  }
}
bool testElementOutOfBoundAccess()
{
  topit::Vector< int >v;
  try
  {
    int& val = v.at(0);
    return false;
  }
  catch (const std::out_of_range&)
  {
    return true;
  }
  catch (...)
  {
    return false;
  }
}

bool testElementInBoundConstAccess()
{
  topit::Vector< int >v;
  v.pushBack(1);
  const topit::Vector< int >& rv = v;
  try
  {
    const int& val = rv.at(0);
    return val == 1;
  }
  catch(...)
  {
    return false;
  }
}
bool testElementOutOfBoundConstAccess()
{
  const topit::Vector< int >v;
  try
  {
    const int& val = v.at(0);
    return false;
  }
  catch (const std::out_of_range&)
  {
    return true;
  }
  catch (...)
  {
    return false;
  }
}

bool testCopyConstructorForEmpty()
{
  topit::Vector< int > v;
  topit::Vector< int > yav = v;
  return v == yav;
}
bool testCopyConstructorForNonEmpty()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yav = v;
  return v == yav;
}

bool testCopyOperatorForEmpty()
{
  topit::Vector< int > vec1;
  topit::Vector< int > vec2;
  vec2 = vec1;
  return vec1 == vec2;
}
bool testCopyOperatorForNonEmpty()
{
  topit::Vector< int > vec1;
  vec1.pushBack(1);
  topit::Vector< int > vec2;
  vec2 = vec1;
  return vec1 == vec2;
}

bool testPushBack()
{
  topit::Vector< int > vec;
  vec.pushBack(1);
  return (vec.getSize() == 1) && (vec[0] == 1);
}
bool tetsPopBack()
{
  topit::Vector< int > vec;
  vec.pushBack(1);
  vec.popBack();
  return (vec.getSize() == 0);
}

bool testInitializerList()
{
  topit::Vector< int > v {1, 2};
  return v.getSize() == 2 && (v[0] == 1) && (v[1] == 2);
}

int main()
{
  using test_t = std::pair< const char*, bool(*)() >;
  test_t tests [] = 
  {
    { "Empty vector", testEmptyVector},
    { "Indound access", testElementInBoundAccess},
    { "Out of bound access", testElementOutOfBoundAccess},
    { "Inbound const accsess", testElementInBoundConstAccess},
    { "Out of bound const access", testElementOutOfBoundConstAccess},
    { "Copy empty vector", testCopyConstructorForEmpty},
    { "Copy non-empty vector", testCopyConstructorForNonEmpty},
    { "Copy-operator for empty vector", testCopyOperatorForEmpty},
    { "Copy-operator for non-empty vector", testCopyOperatorForNonEmpty},
    { "Push back testing", testPushBack},
    { "Pop back testing", tetsPopBack},
    { "Initializer_list test", testInitializerList}
  };
  const size_t count = sizeof(tests) / sizeof(test_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; ++i)
  {
    bool res = tests[i].second;
    std::cout << tests[i].first << ": " << tests[i].second() << "\n";
    pass = pass && res;
  }
  std::cout << "RESULT: " << pass << "\n";
  //Подсчет пройденных-непройденных
  //Выводить только неудачные тесты
}