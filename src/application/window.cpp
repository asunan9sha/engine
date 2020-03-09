//
// Created by asuna on 3/6/2020.
//

#include <glad/glad.h>
#include <application/window.hpp>
#include <iostream>
#include "macro/assert.hpp"

namespace prv {

  void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto p = reinterpret_cast<eng::Window *>(glfwGetWindowUserPointer(window));
    eng::Event e{ };

    e.key.code = key;
    e.key.alt =mods== GLFW_MOD_ALT;
    e.key.control =mods== GLFW_MOD_CONTROL;
    e.key.shift =mods== GLFW_MOD_SHIFT;
    e.key.system =mods== GLFW_MOD_SUPER;
    if (action == GLFW_RELEASE) {
      e.type = eng::Event::KeyReleased;;
    } else if (action == GLFW_PRESS) {
      e.type = eng::Event::KeyPressed;
    } else if (action == GLFW_REPEAT) {
      e.type = eng::Event::KeyPressed;
    }
    p->pushEvent(e);
  }
}


namespace eng {
  Window *Window::_instance = nullptr;

  Window::Window() {

    ASSERT(!_instance && "error instanse already exist");

    _instance = this;

  }


  void Window::initialize(const Config &config) {

    _windowData.Width = config.width;
    _windowData.Height = config.height;
    _windowData.Title = config.title;
    _windowData.VSync = config.vSync;

    if (!glfwInit()) {
      std::cout << "ERROR::GLFW::INIT : GLFW failed to initialize" << std::endl;
      return;
    }


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    _window = glfwCreateWindow(_windowData.Width, _windowData.Height, _windowData.Title, NULL, NULL);

    glfwSetWindowUserPointer(_window, this);

    //glfwSetKeyCallback(m_Window, key_callback);
    //glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

    glfwMakeContextCurrent(_window);

    const int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    if (!status) {
      glfwTerminate();
      std::cout << "ERROR::GLAD::INIT : GLAD failed to initialize" << std::endl;
      return;
    }

    if (_windowData.VSync) {
      glfwSwapInterval(1);
      std::cout << "WINDOW::OPTIONS::VSYNC::ON" << std::endl;
    } else {
      std::cout << "WINDOW::OPTIONS::VSYNC::OFF" << std::endl;
    }

    glfwSetKeyCallback(_window, prv::key_callback);

  }

  void Window::Window::run() {


    while (!glfwWindowShouldClose(_window)) {
      glClear(GL_COLOR_BUFFER_BIT);
      glClearColor(1.0f, 0.3f, 0.5f, 1.0f);


      //glDrawArrays(GL_TRIANGLES, 0, 3);

      /* Swap front and back buffers */
      glfwSwapBuffers(_window);

      /* Poll for and process events */
      glfwPollEvents();
      Event event{ };
      pollEvent(event);
      if (event.type == Event::KeyPressed) { printf("key %i, %i\n", event.key.code,event.key.shift); }
    }
    glfwTerminate();

  }


  void Window::clear() {

  }
  bool Window::isVsync() const {
    return _windowData.VSync;
  }
  void Window::shutdown() {
    glfwDestroyWindow(_window);
    glfwTerminate();
  }
  unsigned int Window::GetWidth() const {
    return _windowData.Width;
  }
  unsigned int Window::GetHeight() const {
    return _windowData.Height;
  }
  GLFWwindow &Window::getGlfwWindow() {
    return *_window;
  }
  void Window::setWindowSize(unsigned width, unsigned height) {
    _windowData.Width = width;
    _windowData.Height = height;
    glfwSetWindowSize(_window, _windowData.Width, _windowData.Height);
  }
  const char *Window::getTitle() const {
    return _windowData.Title;
  }
  void Window::pushEvent(Event &e) {
    _events.emplace(e);
  }
  void Window::pollEvent(Event &e) {
    if (!_events.empty()) {
      e = _events.back();
      _events.pop();
    }
  }
}