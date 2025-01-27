#include <iostream>

using namespace std;

template <int x>
struct Factorial
{
  static constexpr int nr = x * Factorial<x - 1>::nr;
};

template <>
struct Factorial<1>
{
  static constexpr int nr = 1;
};
int main()
{
  std::cout << Factorial<5>::nr << std::endl;
}