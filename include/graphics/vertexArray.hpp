//
// Created by asuna on 3/12/2020.
//

#ifndef ENGINE_VERTEX_ARRAY_HPP
#define ENGINE_VERTEX_ARRAY_HPP

#include <graphics/vertexBuffer.hpp>
#include <graphics/vertexBufferLayout.hpp>

namespace eng {
  class VertexArray {
  private:

    unsigned int _rendererID;

  public:
    VertexArray();
    ~VertexArray();

    void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
  };
}

#endif //ENGINE_VERTEX_ARRAY_HPP
