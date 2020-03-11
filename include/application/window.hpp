//
// Created by asuna on 3/6/2020.
//

#ifndef ENGINE_WINDOW_HPP
#define ENGINE_WINDOW_HPP

#include <queue>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <application/config.hpp>
#include <event/event.hpp>

namespace eng {

  class Window {

  public:

    void initialize(const Config &config);

    Window();

    void run();

    void setWindowSize(unsigned width, unsigned height);

    void clear();

    //void draw();

    //void update();

    bool isVsync() const;

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    bool Window::isMouseButtonPressed(GLFWwindow *window, Mouse::Button button);

    static Keyboard::Key glfwKeyToEng(int key);

    bool isKeyPressed(GLFWwindow *window, Keyboard::Key key);

    static Mouse::Button glfwButtonToEng(int button);

    void shutdown();

    unsigned int GetWidth() const;

    unsigned int GetHeight() const;

    const char *getTitle() const;

    GLFWwindow &getGlfwWindow();

    static Window *getWindow() { return _instance; };

    void pushEvent(Event &e);

    void pollEvent(Event &e);

  private:

    GLFWwindow *_window;

    static Window *_instance;

    bool _isOpen;

    struct WindowData {
      const char *Title;
      unsigned int Width, Height;
      bool VSync;

      //EventCallbackFn EventCallback;
    };

    WindowData _windowData;

    std::queue<Event> _events;


  };
}

#endif //ENGINE_WINDOW_HPP
