//
// Created by asuna on 3/11/2020.
//
#include "pch.hpp"
#include "graphics/renderer.hpp"
#include <glad/glad.h>

namespace eng {
  void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
  }
  void Renderer::clearColor() {
    glClearColor(1.0f, 0.3f, 0.5f, 1.0f);
  }
}