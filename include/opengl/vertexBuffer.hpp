//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_VERTEXBUFFER_HPP
#define ENGINE_VERTEXBUFFER_HPP

#include <opengl/renderer.hpp>

namespace eng {
  class VertexBuffer {

  private:

    unsigned int _rendererID;

  public:

    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();
    void bind() const;
    void unbind() const;

  };
}

#endif //ENGINE_VERTEXBUFFER_HPP
