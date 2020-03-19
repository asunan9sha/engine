//
// Created by asuna on 3/11/2020.
//
#include "pch.hpp"
#include "graphics/renderer.hpp"
#include <macro/glerrorcheck.hpp>

namespace eng {
  void Renderer::clear() {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
  }
  void Renderer::clearColor() {
    GLCall(glClearColor(1.0f, 0.3f, 0.5f, 1.0f));
  }
}