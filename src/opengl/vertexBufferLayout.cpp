//
// Created by asuna on 3/12/2020.
//

#include "opengl/vertexBufferLayout.hpp"
namespace eng {
  unsigned int VertexBufferLayout::getStride() const {
    return _stride;
  }
  const std::vector<VertexBufferElement> VertexBufferLayout::getElements() const {
    return _elements;
  }
}