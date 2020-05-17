//
// Created by asunan9sha on 5/17/2020.
//

#ifndef ENGINE_EMBEDDED_HPP
#define ENGINE_EMBEDDED_HPP

#include <string>

namespace cmrc {
  class embedded_filesystem;
}

namespace eng {
  class Embedded {

  public:

    static std::string getShader(const std::string& name);

  private:

    static cmrc::embedded_filesystem* fs();

  };
}

#endif //ENGINE_EMBEDDED_HPP
