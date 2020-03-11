//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_INDEX_BUFFER_HPP
#define ENGINE_INDEX_BUFFER_HPP

#include <opengl/renderer.hpp>

namespace eng {
  class IndexBuffer {

  private:

    unsigned int _rendererID;
    unsigned int _count;

  public:

    IndexBuffer(const unsigned int *data, unsigned int _count);
    ~IndexBuffer();
    void bind() const;
    void unbind() const;

    unsigned int getCount() const;
  };
}


#endif //ENGINE_INDEX_BUFFER_HPP
