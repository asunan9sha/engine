//
// Created by asunan9sha on 3/17/2020.
//

#ifndef ENGINE_SHADER_HPP
#define ENGINE_SHADER_HPP

#include <string>
#include <math/math.hpp>

namespace eng {

  struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmentSource;
  };

  class Shader {
  private:

    std::string _filepath;
    unsigned int _rendererID;

    std::unordered_map<std::string , int > _uniformLocationCache;


  public:
    Shader(std::string_view filepath);
    ~Shader();


    void bind() const;
    void unbind() const;

    void setUniform4f(std::string_view name, const vec4 &var);

    void setUniform3f(std::string_view name, const vec3 &var);

    void setUniform2f(std::string_view name, const vec2 &var);

    void setUniformInt64(std::string_view name,  uint64_t var);

    void setUniform1f(std::string_view name, float var);

    void setUniform1i(std::string_view name, int var);

    void setUniform4x4(std::string_view name, const mat4 &var);

  private:

    int getUniformLocation(std::string_view name);

    ShaderProgramSource parseShader(std::string_view filepath);

    unsigned int createShader(std::string_view vertexShader, std::string_view fragmentShader);

    unsigned int compileShader(unsigned int type, std::string_view source);


  };
}


#endif //ENGINE_SHADER_HPP
