//
// Created by asuna on 3/11/2020.
//

#include "pch.hpp"
#include <application/window.hpp>
#include <application/application.hpp>
#include <graphics/renderer.hpp>

#include <graphics/renderer.hpp>
#include <graphics/vertexBuffer.hpp>
#include <graphics/indexBuffer.hpp>
#include <graphics/vertexArray.hpp>

#include <graphics/shader.hpp>

#include <glad/glad.h>

namespace eng {


  void Application::run() {
    {
      window.initialize(config);

      float positions[] = {
          -0.5f, -0.5f,
          0.5f, -0.5f,
          0.5f, 0.5f,
          -0.5f, 0.5f
      };

      unsigned int indices[] = {
          0, 1, 2,
          2, 3, 0
      };

      unsigned int vao;
      glGenVertexArrays(1, &vao);
      glBindVertexArray(vao);


      VertexArray va;
      VertexBuffer vb(positions, 4 * 2 * sizeof(float));

      VertexBufferLayout layout;
      layout.push<float>(2);
      va.AddBuffer(vb, layout);

      IndexBuffer ib(indices, 6);

      Shader shader("res/shaders/basic.shader");
      shader.bind();
      shader.setUniform4f("u_Color", {0.8f, 0.3f, 0.8f, 1.0f});

      va.unbind();

      shader.unbind();

      float r = 0.0f;
      float increment = 0.05f;

      while (!window.isExisting()) {

        eng::Renderer::clear();
        eng::Renderer::clearColor();
        // glClearColor(1.0f, 0.3f, 0.5f, 1.0f);
        shader.bind();

        shader.setUniform4f("u_Color", {r, 0.3f, 0.8f, 1.0f});

        va.bind();
        ib.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        if (r > 1.0f)
          increment = -0.05f;
        else if (r < 0.0f)
          increment = 0.05f;
        r += increment;
        /* Swap front and back buffers */
        window.swapBuffers(&window.getGlfwWindow());

        /* Poll for and process events */
        window.pollEvents();
        Event event{ };
        while (window.pollEvent(event)) {
          if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::A) {
              printf("a\n");
            }
            if (event.key.code == Keyboard::S) {
              printf("s\n");
            }
            if (event.key.code == Keyboard::D) {
              printf("d\n");
            }
          }

          if (event.type == Event::MouseButtonReleased) {
            {
              printf("RELEASED\n");
            }
            if (event.mouseButton.button == Mouse::Left) {
              printf("left button\n");
            }
          }

        }
      }
      window.shutdown();
    }
  }
}