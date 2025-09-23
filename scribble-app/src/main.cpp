#include <fmt/core.h>
#include <iostream>

int main()
{
  fmt::print("Hello World!\n");

  fmt::print("Press any key to exit the console...");
  std::cin.ignore();
  std::cin.get();
  return 0;
}
