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

#include <graphics/sprite.hpp>

namespace eng {


  void Application::run() {
    {
      window.initialize(config);

      struct Vertex {
        vec3 pos;
        vec2 texCoord;
        vec4 color;
        vec2u textureId;
      };

//      float positions[] = {
////          -1.0, -1.0, 0.0, 0.0,
////          1.0, -1.0, 1.0, 0.0,
////          1.0, 1.0, 1.0, 1.0,
////          -1.0, 1.0, 0.0, 1.0,
////
////          1.2, -1.0, 0.0, 0.0,
////          3.2, -1.0, 1.0, 0.0,
////          3.2, 1.0, 1.0, 1.0,
////          1.2, 1.0, 0.0, 1.0
//
//      };

      unsigned int indices[] = {
          0, 2, 1,
          0, 3, 2,

          4, 6, 5,
          4, 7, 6
      };

      static const uint64_t size = 8;

      Texture::Params params{ };
      params.bindless = true;

      std::shared_ptr<Texture> texture1 = std::make_shared<Texture>("res/textures/prozra4nost.png", params);
      std::shared_ptr<Texture> texture = std::make_shared<Texture>("res/textures/ebatti.png", params);

      Sprite sprite(texture, {100.0f, 0.0f, 0.0f}, {200.0f, 200.0f});
      //sprite.setRot(10.0f);
      Sprite sprite1(texture1, {0.0f, 0.0f, 0.0f}, {200.0f, 200.0f});

      Vertex *vertex = new Vertex[size];
      {
        uint64_t handle1 = sprite.getTexture()->getHandle();

        vec2 si = sprite.getSize();
        mat4 t = sprite.getTransform();


        vertex[0].pos = math::translateXY(t, vec3(0.0f, 0.0f, 0.0f));
        vertex[0].texCoord = {0.0f, 0.0f};
        vertex[0].color = sprite.getColor();
        vertex[0].textureId = *reinterpret_cast<const vec2u *>(&handle1);

        vertex[1].pos = math::translateXY(t, {si.x, 0.0f, 0.0f});
        vertex[1].texCoord = {1.0f, 0.0f};
        vertex[1].color = sprite.getColor();
        vertex[1].textureId = *reinterpret_cast<const vec2u *>(&handle1);

        vertex[2].pos = math::translateXY(t, {si.x, si.y, 0.0f});
        vertex[2].texCoord = {1.0f, 1.0f};
        vertex[2].color = sprite.getColor();
        vertex[2].textureId = *reinterpret_cast<const vec2u *>(&handle1);

        vertex[3].pos = math::translateXY(t, {0.0f, si.y, 0.0f});
        vertex[3].texCoord = {0.0f, 1.0f};
        vertex[3].color = sprite.getColor();
        vertex[3].textureId = *reinterpret_cast<const vec2u *>(&handle1);
      }

      {
        uint64_t handle1 = sprite1.getTexture()->getHandle();

        vec2 si = sprite1.getSize();
        mat4 t = sprite1.getTransform();

        vertex[4].pos = math::translateXY(t, vec3(0.0f, 0.0f, 0.0f));
        vertex[4].texCoord = {0.0f, 0.0f};
        vertex[4].color = sprite1.getColor();
        vertex[4].textureId = *reinterpret_cast<const vec2u *>(&handle1);

        vertex[5].pos = math::translateXY(t, {si.x, 0.0f, 0.0f});
        vertex[5].texCoord = {1.0f, 0.0f};
        vertex[5].color = sprite1.getColor();
        vertex[5].textureId = *reinterpret_cast<const vec2u *>(&handle1);
//
        vertex[6].pos = math::translateXY(t, {si.x, si.y, 0.0f});
        vertex[6].texCoord = {1.0f, 1.0f};
        vertex[6].color = sprite1.getColor();
        vertex[6].textureId = *reinterpret_cast<const vec2u *>(&handle1);

        vertex[7].pos = math::translateXY(t, {0.0f, si.y, 0.0f});
        vertex[7].texCoord = {0.0f, 1.0f};
        vertex[7].color = sprite1.getColor();
        vertex[7].textureId = *reinterpret_cast<const vec2u *>(&handle1);
      }
//      vertex[2].pos = sprite1.getPos();
//      vertex[2].size = sprite1.getSize();
//      vertex[2].color = sprite1.getColor();
//      uint64_t handle2 = sprite1.getTexture()->getHandle();
//      vertex[2].textureId = *reinterpret_cast<const vec2 *>(&handle2);


      Renderer::enableBlend(true);
      Renderer::blend(Blend::SrcAlpha, Blend::OneMinusSrcAlpha);


      //VertexBuffer vb(positions, sizeof(positions));
      VertexBuffer vb(vertex, size * sizeof(Vertex));


      BufferLayout layout;
      layout.push<vec3>("positions");
      layout.push<vec2>("texCoord");
      layout.push<vec4>("color");
      layout.push<vec2u>("textureId");

      VertexArray va;
      va.addBuffer(vb, layout);

      IndexBuffer ib(indices, sizeof(indices) / sizeof(unsigned int));

      Shader shader("res/shaders/basic.shader");
      shader.bind();
      // shader.setUniform4f("u_Color", {0.8f, 0.3f, 0.8f, 1.0f});


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

        //shader.setUniform1i("u_Texture", 0);

        mat4 model1 = glm::translate(mat4(1), {0.0f, 0.0f, 0.0f});
        mat4 proj = glm::ortho(0.0f, static_cast<float>(config.width) , 0.0f, static_cast<float>(config.height));
        shader.setUniform4x4("u_Model", model1);
        shader.setUniform4x4("u_Proj", proj);
        //  shader.setUniform4f("u_Color", {r, 0.3f, 0.8f, 1.0f});
        //  shader.setUniformInt64("u_Handle", texture->getHandle());

        va.bind();
        ib.bind();


        va.draw(sizeof(indices) / sizeof(unsigned int));

        //shader.setUniform1i("u_Texture", 0);
        shader.setUniform4x4("u_Model", model1);

        //  shader.setUniformInt64("u_Handle", texture1->getHandle());

        va.draw(sizeof(indices) / sizeof(unsigned int));

        if (r > 5.0f)
          increment = -0.55f;
        else if (r < -10.0f)
          increment = 0.55f;
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