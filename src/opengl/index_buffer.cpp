//
// Created by asuna on 3/11/2020.
//

#include "opengl/index_buffer.hpp"

namespace eng {


  IndexBuffer::IndexBuffer(const void *data, unsigned int size) : _count(_count)
  {
    glGenBuffers(1, &_rendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof(unsigned int), data, GL_STATIC_DRAW);
  }
  void IndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
  }
  void IndexBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }
  IndexBuffer::~IndexBufferndexBuffer() {
    glDeleteBuffers(1,&_rendererID);
  }
  unsigned int IndexBuffer::getCount() const {
    return _count;
  }
}