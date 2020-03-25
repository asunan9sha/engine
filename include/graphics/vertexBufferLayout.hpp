//
// Created by asuna on 3/12/2020.
//

#ifndef ENGINE_VERTEX_BUFFER_LAYOUT_HPP
#define ENGINE_VERTEX_BUFFER_LAYOUT_HPP

#include <graphics/GLTypes.hpp>
#include <vector>
#include <graphics/renderer.hpp>
#include <macro/assert.hpp>
#include <math/math.hpp>

namespace eng {

  struct BufferElement {
    const char *name;
    unsigned int type;
    unsigned int size;
    unsigned int count;
    unsigned int offset;
    bool normalized;

    BufferElement(const char *name, unsigned int type, unsigned int size, unsigned int count, unsigned int offset,
                  bool normalized) :
        name(name), type(type), size(size), count(count), offset(offset), normalized(normalized) { }
  };

  class BufferLayout {
  public:
    BufferLayout() : size(0) { }

    template<typename T>
    void push(const char *name, unsigned int count = 1, bool normalized = false) {
      ASSERT(false && "Unknown type!"); //for default types only
    }

    inline const std::vector<BufferElement> &getLayout() const { return layout; }
    inline unsigned int getStride() const { return size; }

  private:
    void push(const char *name, unsigned int type, unsigned int size, unsigned int count, bool normalized) {
      layout.emplace_back(name, type, size, count, BufferLayout::size, normalized);
      BufferLayout::size += size * count;
    }

  private:
    unsigned int size;
    std::vector<BufferElement> layout;
  };

  template<>
  inline void BufferLayout::push<float>(const char *name, unsigned int count, bool normalized) {
    push(name, GL_FLOAT, sizeof(float), count, normalized);
  }

  template<>
  inline void BufferLayout::push<unsigned int>(const char *name, unsigned int count, bool normalized) {
    push(name, GL_UNSIGNED_INT, sizeof(unsigned int), count, normalized);
  }

  template<>
  inline void BufferLayout::push<int>(const char *name, unsigned int count, bool normalized) {
    push(name, GL_INT, sizeof(int), count, normalized);
  }

  template<>
  inline void BufferLayout::push<unsigned char>(const char *name, unsigned int count, bool normalized) {
    push(name, GL_UNSIGNED_BYTE, sizeof(unsigned char), count, normalized);
  }

  template<>
  inline void BufferLayout::push<vec2>(const char *name, unsigned int count, bool normalized) {
    ASSERT(count <= 1 && "cant push more then 1 vec2");

    push(name, GL_FLOAT, sizeof(float), 2, normalized);
  }
  template<>
  inline void BufferLayout::push<vec2u>(const char *name, unsigned int count, bool normalized) {
    ASSERT(count <= 1 && "cant push more then 1 vec2");

    push(name, GL_UNSIGNED_INT, sizeof(unsigned int), 2, normalized);
  }

  template<>
  inline void BufferLayout::push<vec3>(const char *name, unsigned int count, bool normalized) {
    ASSERT(count <= 1 && "cant push more then 1 vec3");

    push(name, GL_FLOAT, sizeof(float), 3, normalized);
  }

  template<>
  inline void BufferLayout::push<vec4>(const char *name, unsigned int count, bool normalized) {
    ASSERT(count <= 1 && "cant push more then 1 vec4");

    push(name, GL_FLOAT, sizeof(float), 4, normalized);
  }

  template<>
  inline void BufferLayout::push<mat4>(const char *name, unsigned int count, bool normalized) {
    ASSERT(count <= 1 && "cant push more then 1 mat4");
    push(name, GL_FLOAT, sizeof(float), 16, normalized);
  }

}
#endif //ENGINE_VERTEX_BUFFER_LAYOUT_HPP
