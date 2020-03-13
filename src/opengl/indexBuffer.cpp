//
// Created by asuna on 3/11/2020.
//


#include "opengl/indexBuffer.hpp"
#include "glad/glad.h"

namespace eng {


  IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int _count) : _count(_count)
  {
    glGenBuffers(1, &_rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(unsigned int), data, GL_STATIC_DRAW);
  }
  IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1,&_rendererID);
  }
  void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
  }
  void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }
  unsigned int IndexBuffer::getCount() const {
    return _count;
  }
}