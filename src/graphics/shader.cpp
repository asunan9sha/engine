//
// Created by asunan9sha on 3/17/2020.
//
#include <glad/glad.h>

#include <graphics/shader.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

namespace eng {


  Shader::Shader(std::string_view filepath) : _filepath(filepath), _rendererID(0) {

    ShaderProgramSource source = parceShader(filepath);

    _rendererID = createShader(source.vertexSource, source.fragmentSource);
  }
  Shader::~Shader() {
    glDeleteProgram(_rendererID);
  }
  void Shader::bind() const {
    glUseProgram(_rendererID);
  }

  void Shader::unbind() const {
    glUseProgram(0);
  }

  void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
    glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
  }

  int Shader::getUniformLocation(const std::string& name ) {

    int location = glGetUniformLocation(_rendererID, name.c_str());

    if (location == -1)

     std::cout << "uniform " << name << " doesn't exist" << std::endl;

    return location;

  }

  unsigned int Shader::createShader(const std::string &vertexShader, const std::string &fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
  }
  unsigned int Shader::compileShader(unsigned int type, const std::string &source) {
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
      int length;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
      char *message = (char *) alloca(length * sizeof(char));
      glGetShaderInfoLog(id, length, &length, message);
      std::cout << "FAILED TO COMPILE ";
      if(type == GL_VERTEX_SHADER)
        std::cout<<" vertex "<< std::endl;
      else std::cout<<" fragment "<< std::endl;
      std::cout << message << std::endl;
      return 0;
    }
    return id;
  }
  ShaderProgramSource Shader::parceShader(std::string_view filepath) {

    std::ifstream stream(filepath.data());

    enum class ShaderType {
      NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line)) {
      if (line.find("#shader") != std::string::npos) {
        if (line.find("vertex") != std::string::npos)
          type = ShaderType::VERTEX;
        else if (line.find("fragment") != std::string::npos)
          type = ShaderType::FRAGMENT;
      } else {
        ss[(int) type] << line << '\n';
        std::cout<<line<< std::endl;
      }
    }
    return {ss[0].str(), ss[1].str()};
  }
}