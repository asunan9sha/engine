//
// Created by asuna on 3/12/2020.
//

#include <opengl/vertexArray.hpp>
#include <opengl/vertexBufferLayout.hpp>
#include <glad/glad.h>

namespace eng {
  VertexArray::VertexArray() {
      glGenVertexArrays(1, &_rendererID);
  }
  VertexArray::~VertexArray() {
      glDeleteVertexArrays(1, &_rendererID);
  }
  void VertexArray::AddBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) {
    bind();
    vb.bind();

    const auto &elements = layout.getElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
      const auto &element =elements[i];
      glEnableVertexAttribArray(i);
      glVertexAttribPointer(i,element.count, element.type, element.normalized,layout.getStride(), (const void*)offset);
      offset+=element.count * VertexBufferElement::getSizeOfType(element.type);
    }
  }
  void VertexArray::bind() const {
    glBindVertexArray(_rendererID);
  }
  void VertexArray::unbind() const {
    glBindVertexArray(0);
  }
}
