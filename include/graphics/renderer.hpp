//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

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
    static void clear();
    static void clearColor();
    static void enableBlend(bool enable);
    static void blend(Blend src, Blend dst);
  private:
    Renderer() = default;
  };
}

#endif //ENGINE_RENDERER_HPP
