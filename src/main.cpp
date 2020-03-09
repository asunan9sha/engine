
#include <iostream>
#include "application/window.hpp"
#include "application/config.hpp"

int main()
{

  eng::Config config;
  eng::Window window;

  window.initialize(config);
  window.run();

  return 0;
}