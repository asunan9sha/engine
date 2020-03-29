//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

#include <graphics/vertexArray.hpp>
#include <graphics/indexBuffer.hpp>
#include <graphics/shader.hpp>

namespace eng {

  enum class Blend {
    Zero,
    One,
    SrcColor,
    OneMinusSrcColor,
    SrcAlpha,
    OneMinusSrcAlpha,
    DstColor,
    OneMinusDstColor,
    DstAlpha,
    OneMinusDstAlpha,
    SrcAlphaSaturated,
    BlendColor,
    OneMinusBlendColor,
    BlendAlpha,
    OneMinusBlendAlpha
  };

  class Renderer {
  public:
     void clear();
     void clearColor();
     void enableBlend(bool enable);
     void blend(Blend src, Blend dst);
     void draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;
  };
}

#endif //ENGINE_RENDERER_HPP
