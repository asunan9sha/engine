//
// Created by asuna on 3/12/2020.
//

#ifndef ENGINE_VERTEX_BUFFER_LAYOUT_HPP
#define ENGINE_VERTEX_BUFFER_LAYOUT_HPP

#include <opengl/GLTypes.hpp>
#include <vector>
#include <opengl/renderer.hpp>
#include <macro/assert.hpp>
namespace eng {

  struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;


    static unsigned int getSizeOfType(unsigned int type) {
      switch (type) {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
      }
      ASSERT(false);
      return 0;
    }
  };

  class VertexBufferLayout {

  private:

    std::vector<VertexBufferElement> _elements;
    unsigned int _stride;

  public:

    VertexBufferLayout()
        : _stride(0) { }

    template<typename T>
    void push(unsigned count) {
      static_assert(false);
    }
    template<>
    void push<float>(unsigned int count) {
      _elements.push_back({GL_FLOAT, count, GL_FALSE});
      _stride = count * sizeof(VertexBufferElement::getSizeOfType(GL_FLOAT));
    };
    template<>
    void push<unsigned int>(unsigned int count) {
      _elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
      _stride = count * sizeof(VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT));
    };
    template<>
    void push<unsigned char>(unsigned int count) {
      _elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
      _stride = count * sizeof(VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE));
    }

    const std::vector<VertexBufferElement> getElements() const;
    unsigned int getStride() const;

  };
}
#endif //ENGINE_VERTEX_BUFFER_LAYOUT_HPP
