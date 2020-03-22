//
// Created by asunan9sha on 3/18/2020.
//

#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP


#include <string>

namespace eng {
  class Texture {

  private:

    unsigned int _rendererID;
    std::string _filepath;
    unsigned char *_localBuffer;
    unsigned int _width, _height, _BPP;

  public:

    explicit Texture( std::string_view filepath);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline unsigned int getWidth() const { return _width  ; }
    inline unsigned int getHeight() const { return _height  ; }

  };
}

#endif //ENGINE_TEXTURE_HPP
