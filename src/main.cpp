
#include <iostream>
#include "application/window.hpp"
#include "application/config.hpp"

int main()
{

  Config config;
  Window window;

  window.initialize(config);
  window.run();

  return 0;
}