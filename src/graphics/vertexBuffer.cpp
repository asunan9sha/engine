//
// Created by asuna on 3/11/2020.
//
#include "pch.hpp"
#include <graphics/vertexBuffer.hpp>
#include <glad/glad.h>

namespace eng {


  VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    glGenBuffers(1, &_rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  }
  VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &_rendererID);
  }
  void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
  }
  void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
}