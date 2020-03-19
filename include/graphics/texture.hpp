//
// Created by asunan9sha on 3/18/2020.
//

#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP

#include <pch.hpp>

namespace eng {
  class Texture {

  private:

    unsigned int _rendererID;
    std::string _filepath;
    unsigned char *_localBuffer;
    int _width, _height, _BPP;

  public:

    Texture(const std::string &_filepath);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;


    inline vec2 getsize() const { return {_width, _height} ; }

  };
}

#endif //ENGINE_TEXTURE_HPP
