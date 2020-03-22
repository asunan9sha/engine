//
// Created by asunan9sha on 3/18/2020.
//

#ifndef ENGINE_TEXTURE_HPP
#define ENGINE_TEXTURE_HPP

#include <graphics/GLTypes.hpp>

#include <string>

namespace eng {


  class Texture {

  public:

    struct Params {

      Target target = Target::Texture2D;

      TextureFormat format = TextureFormat::RGBA8;

      TextureMinFilter minfilter = TextureMinFilter::Linear;
      TextureMagFilter magfilter = TextureMagFilter::Linear;

      Wrapp wrapS = Wrapp::ClampToBorder;
      Wrapp wrapT = Wrapp::ClampToBorder;

      bool bindless = false;

    };

  public:

    explicit Texture(std::string_view filepath, Params params);

    ~Texture();

    void setParams();

    void bind(unsigned int slot = 0) const;

    void unbind() const;

    inline unsigned int getWidth() const { return _width; }
    inline unsigned int getHeight() const { return _height; }

    inline uint64_t getHandle() const { return _handle; }

  private:

    void freeBuffer();

    void loadTexture();

  private:

    uint64_t _handle=0;

    unsigned int _id;
    std::string _filepath;
    unsigned char *_localBuffer;
    unsigned int _width, _height, _BPP;

    Params _params;

  };
}

#endif //ENGINE_TEXTURE_HPP
