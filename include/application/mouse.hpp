//
// Created by asuna on 3/9/2020.
//

#ifndef ENGINE_MOUSE_HPP
#define ENGINE_MOUSE_HPP
namespace eng {
  struct Mouse {
    enum Button {
      Left,
      Right,
      Middle,
      Button4,
      Button5,
      Button6,
      Button7,
      Button8,

      ButtonCount 
    };

    enum Wheel {
      VerticalWheel,
      HorizontalWheel
    };
  };
}
#endif //ENGINE_MOUSE_HPP
