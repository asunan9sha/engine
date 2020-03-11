//
// Created by asuna on 3/11/2020.
//

#include <opengl/vertex_buffer.hpp>

namespace eng {


  VertexBuffer::VertexBuffer(const void *data, unsigned int size) {
    glGenBuffers(1, &_rendererID);
    glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  }
  void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
  }
  void VertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  }
  VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1,&_rendererID);
  }
}