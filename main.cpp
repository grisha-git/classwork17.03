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
  try
  {
    return yav.getSize() == v.getSize() && yav.at(0) == v.at(0);
  }
  catch (...)
  {
    return false;
  }
  return v == yav;
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
    { "copy non-empty vector", testCopyConstructorForNonEmpty}
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