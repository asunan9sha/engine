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

    void addBuffer(const VertexBuffer &vb, const BufferLayout &layout);
    void bind() const;
    void unbind() const;

    void draw(unsigned int indicesCount);
  };
}

#endif //ENGINE_VERTEX_ARRAY_HPP
