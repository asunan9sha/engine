//
// Created by asuna on 3/12/2020.
//
#include "pch.hpp"
#include <graphics/vertexArray.hpp>
#include <macro/glerrorcheck.hpp>

namespace eng {

  VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1, &_rendererID));
  }

  VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1, &_rendererID));
  }

  void VertexArray::addBuffer(const VertexBuffer &vb, const BufferLayout &layout) {
    bind();
    vb.bind();

    const auto &l = layout.getLayout();

    for (unsigned int i = 0; i < l.size(); i++) {
      auto &&element = l[i];
      GLCall(glEnableVertexAttribArray(i));
      GLCall(glVertexAttribPointer(i, element.count, element.type,
                                   static_cast<GLboolean>(element.normalized), layout.getStride(),
                                   reinterpret_cast<const void *> (element.offset)));
    }
  }

  void VertexArray::bind() const {
    GLCall(glBindVertexArray(_rendererID));
  }

  void VertexArray::unbind() const {
    GLCall(glBindVertexArray(0));
  }
  void VertexArray::draw(unsigned int indicesCount) {
    GLCall(glDrawElements(GL_TRIANGLES, indicesCount , GL_UNSIGNED_INT, nullptr));
  }

}
