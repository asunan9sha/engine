//
// Created by asuna on 3/6/2020.
//

#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include <GLFW/glfw3.h>
#include "config.hpp"

class Window {

private:

  GLFWwindow *window;

  static Window *_instance;

  bool isOpen= true;

  int width,height;

  const char* title;

  bool vSync;


public:

  void initialize(const Config &config);

  Window();

  void run();

  void clear();

  //void draw();

  //void update();

  inline bool isWindowOpen() { return isOpen; }

  inline GLFWwindow& getGlfwWindow() { return  *window;}

  static Window *getWindow() { return _instance; };
};


#endif //ENGINE_WINDOW_HPP
