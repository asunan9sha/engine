//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_RENDERER_HPP
#define ENGINE_RENDERER_HPP

namespace eng {
  class Renderer {
  public:
    static void clear();
    static void clearColor();
  private:
    Renderer() = default;
  };
}

#endif //ENGINE_RENDERER_HPP
