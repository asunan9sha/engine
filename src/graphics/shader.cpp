//
// Created by asunan9sha on 3/17/2020.
//
#include "pch.hpp"

#include <graphics/shader.hpp>

#include <macro/glerrorcheck.hpp>



namespace eng {


  Shader::Shader(std::string_view filepath) : _filepath(filepath), _rendererID(0) {

    ShaderProgramSource source = parseShader(filepath);

    _rendererID = createShader(source.vertexSource, source.fragmentSource);
  }
  Shader::~Shader() {
    GLCall(glDeleteProgram(_rendererID));
  }
  void Shader::bind() const {
    GLCall(glUseProgram(_rendererID));
  }

  void Shader::unbind() const {
    GLCall(glUseProgram(0));
  }

  unsigned int Shader::createShader(std::string_view vertexShader, std::string_view fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs))
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
  }
  unsigned int Shader::compileShader(unsigned int type, std::string_view source) {
    unsigned int id = glCreateShader(type);
    const char *src = source.data();
    GLCall(glShaderSource(id, 1, &src, nullptr));
    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
    if (result == GL_FALSE) {
      int length;
      GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
      char *message = (char *) alloca(length * sizeof(char));
      GLCall(glGetShaderInfoLog(id, length, &length, message));
      std::cout << "FAILED TO COMPILE ";
      if (type == GL_VERTEX_SHADER)
        std::cout << " vertex " << std::endl;
      else std::cout << " fragment " << std::endl;
      std::cout << message << std::endl;
      return 0;
    }
    return id;
  }
  ShaderProgramSource Shader::parseShader(std::string_view filepath) {

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
      }
    }
    return {ss[0].str(), ss[1].str()};
  }

  int Shader::getUniformLocation(std::string_view name) {

    int location;
    GLCall (location = (glGetUniformLocation(_rendererID, name.data())));

    if (location == -1)

      std::cout << "uniform " << name << " doesn't exist" << std::endl;

    return location;

  }

  void Shader::setUniform4f(std::string_view name, const vec4 &var) {
    GLCall(glUniform4f(getUniformLocation(name.data()), var.x, var.y, var.z, var.w));
  }

  void Shader::setUniform3f(std::string_view name, const vec3 &var) {
    GLCall(glUniform3f(getUniformLocation(name.data()), var.x, var.y, var.z));
  }
  void Shader::setUniform2f(std::string_view name, const vec2 &var) {
    GLCall(glUniform2f(getUniformLocation(name.data()), var.x, var.y));
  }
  void Shader::setUniform1f(std::string_view name, float var) {
    GLCall(glUniform1f(getUniformLocation(name.data()), var));
  }
  void Shader::setUniform1i(std::string_view name, int var) {
    GLCall(glUniform1i(getUniformLocation(name.data()), var));
  }
  void Shader::setUniform4x4(std::string_view name, const mat4 &var) {
    GLCall(glUniformMatrix4fv(getUniformLocation(name.data()), 1, GL_FALSE, glm::value_ptr(var)));
  }
}