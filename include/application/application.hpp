//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

namespace eng {
  class Application {
  public:
    void run();
  private:
    Window window;
    Config config;
  };
}

#endif //ENGINE_APPLICATION_HPP
