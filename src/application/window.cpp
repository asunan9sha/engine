//
// Created by asuna on 3/6/2020.
//

#include <glad/glad.h>
#include <application/window.hpp>
#include <iostream>
#include "macro/assert.hpp"


Window *Window::_instance = nullptr;

Window::Window() {

  ASSERT(!_instance && "error instanse already exist");

  _instance = this;

}


void Window::initialize(const Config &config) {

  width = config.width;
  height = config.height;
  title = config.title;
  vSync = config.vSync;

  if (!glfwInit()) {
    std::cout << "ERROR::GLFW::INIT : GLFW failed to initialize" << std::endl;
    return;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  window = glfwCreateWindow(width, height, title, NULL, NULL);


  //glfwSetKeyCallback(m_Window, key_callback);
  //glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);

  glfwMakeContextCurrent(window);

  const int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

  if (!status) {
    glfwTerminate();
    std::cout << "ERROR::GLAD::INIT : GLAD failed to initialize" << std::endl;
    return;
  }

  if (vSync) {
    glfwSwapInterval(1);
    std::cout << "WINDOW::OPTIONS::VSYNC::ON" << std::endl;
  } else {
    std::cout << "WINDOW::OPTIONS::VSYNC::OFF" << std::endl;
  }

}

void Window::Window::run() {


  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 0.3f, 0.5f, 1.0f);


    //glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }
  glfwTerminate();
}

void Window::clear() {

}
