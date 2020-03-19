//
// Created by asuna on 3/11/2020.
//
#include "pch.hpp"
#include <graphics/vertexBuffer.hpp>
#include <macro/glerrorcheck.hpp>

namespace eng {


  VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    GLCall(glGenBuffers(1, &_rendererID));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
  }
  VertexBuffer::~VertexBuffer() {
    GLCall(glDeleteBuffers(1, &_rendererID));
  }
  void VertexBuffer::bind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, _rendererID));
  }
  void VertexBuffer::unbind() const {
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
  }
}