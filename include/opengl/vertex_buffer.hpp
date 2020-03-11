//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_VERTEX_BUFFER_HPP
#define ENGINE_VERTEX_BUFFER_HPP

#include <opengl/renderer.hpp>

namespace eng {
  class VertexBuffer {

  private:

    unsigned int _rendererID;

  public:

    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();
    void bind();
    void unbind();

  };
}

#endif //ENGINE_VERTEX_BUFFER_HPP
