//
// Created by asuna on 3/11/2020.
//

#include "pch.hpp"
#include "../../modules/glfw-3.3.2/deps/glad/gl.h"
#include <application/application.hpp>
#include <graphics/renderer.hpp>

#include <graphics/vertexBuffer.hpp>
#include <graphics/indexBuffer.hpp>
#include <graphics/vertexArray.hpp>
#include <graphics/texture.hpp>
#include <graphics/shader.hpp>



namespace eng {


  void Application::run() {
    {
      window.initialize(config);

      float positions[] = {
          -1.0, -1.0, 0.0, 0.0,
          1.0, -1.0,  1.0, 0.0,
          1.0, 1.0, 1.0, 1.0,
          -1.0, 1.0,  0.0, 1.0,

          1.2, -1.0, 0.0, 0.0,
          3.2, -1.0,  1.0, 0.0,
          3.2, 1.0, 1.0, 1.0,
          1.2, 1.0,  0.0, 1.0

      };

      unsigned int indices[] = {
          0, 2, 1,
          0, 3, 2,

          4, 6, 5,
          4, 7, 6
      };


      Renderer::enableBlend(true);
      Renderer::blend(Blend::SrcAlpha, Blend::OneMinusSrcAlpha);


      VertexBuffer vb(positions, sizeof(positions));

      BufferLayout layout;
      layout.push<vec2>("positions");
      layout.push<vec2>("texCoord");

      VertexArray va;
      va.addBuffer(vb, layout);

      IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

      Shader shader("res/shaders/basic.shader");
      shader.bind();
      shader.setUniform4f("u_Color", {0.8f, 0.3f, 0.8f, 1.0f});

      Texture::Params params {};
      Texture texture("res/textures/ebatti.png", params);
      Texture texture1("res/textures/prozra4nost.png", params);


      float r = 0.0f;
      float increment = 0.05f;


      va.unbind();
      vb.unbind();
      ib.unbind();
      shader.unbind();

      while (!window.isExisting()) {

        eng::Renderer::clear();
        eng::Renderer::clearColor();

        shader.bind();

        texture.bind();
        shader.setUniform1i("u_Texture", 0);

        mat4 model1 = glm::translate(mat4(1), {0.0f, 0.5f, 0.f});
        mat4 model2 = mat4(1.0f);
        mat4 proj = glm::ortho(-4.0f, 4.0f, -4.0f, 4.0f);
        shader.setUniform4x4("u_Model", model2);
        shader.setUniform4x4("u_Proj", proj);
        shader.setUniform4f("u_Color", {r, 0.3f, 0.8f, 1.0f});

        va.bind();
        ib.bind();

        va.draw(sizeof(indices) / sizeof(unsigned int));

        texture1.bind();
        shader.setUniform1i("u_Texture", 0);
        shader.setUniform4x4("u_Model", model1);

        va.draw(sizeof(indices) / sizeof(unsigned int));

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
      exit(0);
    }
  }
}