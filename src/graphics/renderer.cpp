//
// Created by asuna on 3/11/2020.
//
#include "pch.hpp"
#include "graphics/renderer.hpp"
#include <macro/glerrorcheck.hpp>

namespace eng::cvt {
  static uint32_t toGL(Blend e) {
    switch (e) {
      case Blend::One: return GL_ONE;
      case Blend::SrcColor: return GL_SRC_COLOR;
      case Blend::OneMinusSrcColor: return GL_ONE_MINUS_SRC_COLOR;
      case Blend::SrcAlpha: return GL_SRC_ALPHA;
      case Blend::OneMinusSrcAlpha: return GL_ONE_MINUS_SRC_ALPHA;
      case Blend::DstColor: return GL_DST_COLOR;
      case Blend::OneMinusDstColor: return GL_ONE_MINUS_DST_COLOR;
      case Blend::DstAlpha: return GL_DST_ALPHA;
      case Blend::OneMinusDstAlpha: return GL_ONE_MINUS_DST_ALPHA;
      case Blend::SrcAlphaSaturated: return GL_SRC_ALPHA_SATURATE;
      case Blend::BlendColor: return GL_BLEND_COLOR;
      case Blend::OneMinusBlendColor: return GL_ONE_MINUS_CONSTANT_COLOR;
      case Blend::BlendAlpha: return GL_CONSTANT_ALPHA;
      case Blend::OneMinusBlendAlpha: return GL_ONE_MINUS_CONSTANT_ALPHA;
      case Blend::Zero:
      default: return GL_ZERO;
    }
  }
}

namespace eng {
  void Renderer::clear() {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
  }
  void Renderer::clearColor() {
    GLCall(glClearColor(1.0f, 0.3f, 0.5f, 1.0f));
  }
  void Renderer::enableBlend(bool enable) {
    if (enable) {
      GLCall(glEnable(GL_BLEND));
    } else {
      GLCall(glDisable(GL_BLEND));
    }
  }
  void Renderer::blend(Blend src, Blend dst) {
    GLCall(glBlendFunc(cvt::toGL(src), cvt::toGL(dst)));
  }
}