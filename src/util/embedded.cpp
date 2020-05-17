//
// Created by asunan9sha on 5/17/2020.
//

#include "pch.hpp"
#include "embedded.hpp"
#include <cmrc/cmrc.hpp>

CMRC_DECLARE(eng);

namespace eng {
  std::string Embedded::getShader(const std::string &name) {
    static const std::string path = "eng/src/graphics/opengl/shaders/";
    auto data = fs()->open(path+name);
    return {data.begin(), data.end()};
  }
  cmrc::embedded_filesystem *Embedded::fs() {
    static auto fs=cmrc::eng::get_filesystem();
    return &fs;
  }
}