//
// Created by asuna on 3/8/2020.
//

#ifndef ENGINE_EVENT_HPP
#define ENGINE_EVENT_HPP
#include <event/keyboard.hpp>
#include <event/mouse.hpp>
namespace eng {

  class Event
  {
  public:

    struct SizeEvent
    {
      unsigned int width;
      unsigned int height;
    };

    struct KeyEvent
    {
      Keyboard::Key code;
      bool          alt;
      bool          control;
      bool          shift;
      bool          system;
    };

    struct TextEvent
    {
      unsigned int unicode;
    };

    struct MouseMoveEvent
    {
      int x;
      int y;
    };

    struct MouseButtonEvent
    {
      Mouse::Button button;
      int           x;
      int           y;
    };


    struct MouseWheelEvent
    {
      int delta;
      int x;
      int y;
    };

    struct MouseWheelScrollEvent
    {
    //  Mouse::Wheel wheel;
      float        delta;
      int          x;
      int          y;
    };

    struct JoystickConnectEvent
    {
      unsigned int joystickId;
    };

    struct JoystickMoveEvent
    {
      unsigned int   joystickId;
  //    Joystick::Axis axis;
      float          position;
    };

    struct JoystickButtonEvent
    {
      unsigned int joystickId;
      unsigned int button;
    };

    struct TouchEvent
    {
      unsigned int finger;
      int x;
      int y;
    };

    struct SensorEvent
    {
  //    Sensor::Type type; ///< Type of the sensor
      float x;
      float y;
      float z;
    };


    enum EventType
    {
      Closed,
      Resized,
      LostFocus,
      GainedFocus,
      TextEntered,
      KeyPressed,
      KeyReleased,
      MouseWheelMoved,
      MouseWheelScrolled,
      MouseButtonPressed,
      MouseButtonReleased,
      MouseMoved,
      MouseEntered,
      MouseLeft,
      JoystickButtonPressed,
      JoystickButtonReleased,
      JoystickMoved,
      JoystickConnected,
      JoystickDisconnected,
      TouchBegan,
      TouchMoved,
      TouchEnded,
      SensorChanged,

      Count
    };




    EventType type;

    union
    {
      SizeEvent             size;
      KeyEvent              key;
      TextEvent             text;
      MouseMoveEvent        mouseMove;
      MouseButtonEvent      mouseButton;
      MouseWheelEvent       mouseWheel;
      MouseWheelScrollEvent mouseWheelScroll;
      JoystickMoveEvent     joystickMove;
      JoystickButtonEvent   joystickButton;
      JoystickConnectEvent  joystickConnect;
      TouchEvent            touch;
      SensorEvent           sensor;
    };
  };

  }




#endif //ENGINE_EVENT_HPP
