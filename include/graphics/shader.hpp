//
// Created by asunan9sha on 3/17/2020.
//

#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include "iostream"

namespace eng {

  struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
  };

  class Shader {
  private:

    std::string _filepath;
    unsigned int _rendererID;



  public:
    Shader(std::string_view filepath);
    ~Shader();


    void bind() const;
    void unbind() const;

    void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3);

  private:

    int getUniformLocation(const std::string &name);

    ShaderProgramSource parceShader(std::string_view filepath);

    unsigned int createShader(const std::string &vertexShader, const std::string &fragmentShader);

    unsigned int compileShader(unsigned int type, const std::string &source);


  };
}


#endif //ENGINE_SHADER_HPP
