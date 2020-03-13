//
// Created by asuna on 3/11/2020.
//

#include <application/window.hpp>
#include "application/application.hpp"
#include <opengl/renderer.hpp>

#include <opengl/renderer.hpp>
#include <opengl/vertexBuffer.hpp>
#include <opengl/indexBuffer.hpp>
#include <opengl/vertexArray.hpp>

#include <glad/glad.h>

namespace eng {




  void Application::run() {
    {
      window.initialize(config);
      
      float positions[] = {
          -0.5f, -0.5f,
          0.5f, -0.5f,
          0.5f,  0.5f,
          -0.5f,  0.5f
      };

      unsigned int indices[] = {
          0, 1, 2,
          2, 3, 0
      };

      unsigned int vao;
      glGenVertexArrays(1, &vao);
      glBindVertexArray(vao);


      VertexArray va;
      VertexBuffer vb(positions, 4*2* sizeof(float));

      VertexBufferLayout layout;
      layout.push<float>(2);
      va.AddBuffer(vb,layout);

      IndexBuffer ib(indices, 6);



      while (!window.isExisting()) {

        eng::Renderer::clear();
        eng::Renderer::clearColor();
       // glClearColor(1.0f, 0.3f, 0.5f, 1.0f);

        va.bind();
        ib.bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        /* Swap front and back buffers */
        window.swapBuffers(&window.getGlfwWindow());

        /* Poll for and process events */
        window.pollEvents();
        Event event{ };
        while (window.pollEvent(event)){
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