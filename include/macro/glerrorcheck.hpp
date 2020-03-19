//
// Created by asunan9sha on 3/18/2020.
//

#ifndef ENGINE_GLERRORCHECK_HPP
#define ENGINE_GLERRORCHECK_HPP

#include "assert.hpp"
#include <glad/glad.h>

#define GLCall(x) GLClearError();\
        x;\
        ASSERT(GLLogCall())

        static void GLClearError(){
          while (glGetError() != GL_NO_ERROR);
        }

        static bool (GLLogCall)(){
          while (GLenum error = glGetError()){
            std::cout<< "[OpenGL Error] (" << error << ")"<<std::endl;
            return false;
          }
          return true;
        }


#endif //ENGINE_GLERRORCHECK_HPP
