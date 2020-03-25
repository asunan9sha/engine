//
// Created by asunan9sha on 3/17/2020.
//

#ifndef ENGINE_MATH_HPP
#define ENGINE_MATH_HPP


#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace eng {
  using vec2 = glm::vec2;
  using vec3 = glm::vec3;
  using vec4 = glm::vec4;
  using mat4 = glm::mat4;
  using quat = glm::quat;
  using vec2u= glm::uvec2;

  namespace math {
    static vec3 translateXY(const mat4 &mat, const vec3 &vec) {
      return vec3(mat[0][0] * vec.x + mat[1][0] * vec.y + mat[2][0] * vec.z + mat[3][0],
                  mat[0][1] * vec.x + mat[1][1] * vec.y + mat[2][1] * vec.z + mat[3][1],
                  vec.z);
    }
  }
}


#endif //ENGINE_MATH_HPP
