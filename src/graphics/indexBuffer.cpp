//
// Created by asuna on 3/11/2020.
//

#include "pch.hpp"
#include "graphics/indexBuffer.hpp"
#include <macro/glerrorcheck.hpp>

namespace eng {

  IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count) : _count(count) {
    GLCall(glGenBuffers(1, &_rendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(unsigned int), data, GL_STATIC_DRAW));
  }

  IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &_rendererID));
  }

  void IndexBuffer::bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID));
  }

  void IndexBuffer::unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
  }

  unsigned int IndexBuffer::getCount() const {
    return _count;
  }

}