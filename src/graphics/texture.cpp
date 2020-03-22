//
// Created by asunan9sha on 3/18/2020.
//

#include "pch.hpp"
#include <graphics/texture.hpp>
#include <macro/glerrorcheck.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "util/stbimage.hpp"

#include <graphics/GLTypes.hpp>

namespace eng::convert {
  static uint32_t wrapToGL(Wrapp w) {
    switch (w) {

      case Wrapp::Repeat: return GL_REPEAT;
      case Wrapp::MirroredRepeat: return GL_MIRRORED_REPEAT;
      case Wrapp::ClampToEdge: return GL_CLAMP_TO_EDGE;
      case Wrapp::ClampToBorder: return GL_CLAMP_TO_BORDER;

      default: {
        std::cout << "unsuppurted wrapping" << std::endl;
        return GL_REPEAT;
      }
    }
  }


  static uint32_t minfilterToGL(TextureMinFilter f) {
    switch (f) {

      case TextureMinFilter::Nearest: return GL_NEAREST;
      case TextureMinFilter::Linear: return GL_LINEAR;
      case TextureMinFilter::NearestMipmapNearest: return GL_LINEAR_MIPMAP_NEAREST;
      case TextureMinFilter::LinearMipmapNearest: return GL_LINEAR_MIPMAP_NEAREST;
      case TextureMinFilter::NearestMipmapLinear: return GL_NEAREST_MIPMAP_LINEAR;
      case TextureMinFilter::LinearMipmapLinear: return GL_LINEAR_MIPMAP_LINEAR;

      default: {
        std::cout << "unsuppurted filter" << std::endl;
        return GL_NEAREST;
      }
    }
  }

  static uint32_t magfilterToGL(TextureMagFilter f) {
    switch (f) {

      case TextureMagFilter::Nearest: return GL_NEAREST;
      case TextureMagFilter::Linear: return GL_LINEAR;

      default: {
        std::cout << "unsuppurted filter" << std::endl;
        return GL_NEAREST;
      }
    }
  }

  static uint32_t targetToGL(Target t) {
    switch (t) {

      case Target::Texture1D:return GL_TEXTURE_1D;
      case Target::Texture2D:return GL_TEXTURE_2D;
      case Target::Texture2DArray:return GL_TEXTURE_2D_ARRAY;
      case Target::Texture3D:return GL_TEXTURE_3D;
      case Target::TextureCubeMap:return GL_TEXTURE_CUBE_MAP;
      case Target::TextureCubeMapArray:return GL_TEXTURE_CUBE_MAP_ARRAY;

      default: {
        std::cout << "unsuppurted target" << std::endl;
        return GL_TEXTURE_2D;
      }
    }
  }

  static uint32_t formatToGL(TextureFormat t) {
    switch (t) {

      case TextureFormat::RGB8: return GL_RGB8;
      case TextureFormat::RGBA8:return GL_RGBA8;

      default: {
        std::cout << "unsuppurted format" << std::endl;
        return GL_RGBA8;
      }
    }
  }

  static uint32_t internalFormatToGL(TextureFormat t) {
    switch (t) {

      case TextureFormat::RGB8: return GL_RGB;
      case TextureFormat::RGBA8:return GL_RGBA;

      default: {
        std::cout << "unsuppurted format" << std::endl;
        return GL_RGBA;
      }
    }
  }




}

namespace eng {


  Texture::Texture(std::string_view filepath, Params params)
      : _handle(0), _filepath(filepath), _localBuffer(nullptr),
        _width(0), _height(0), _BPP(0), _params(params) {

    loadTexture();

    GLCall(glGenTextures(1, &_handle));
    GLCall(glBindTexture(convert::targetToGL(_params.target), _handle));

    setParams();

    GLCall(glTexImage2D(convert::targetToGL(_params.target), 0, convert::formatToGL(_params.format),
        _width, _height, 0, convert::internalFormatToGL(_params.format), GL_UNSIGNED_BYTE, _localBuffer));
    GLCall(glBindTexture(convert::targetToGL(_params.target), 0));

    freeBuffer();
  }

  void Texture::loadTexture() {
    stbi_set_flip_vertically_on_load(1);
    _localBuffer = stbi_load(_filepath.data(), (int *) &_width, (int *) &_height, (int *) &_BPP, 4);
  }

  Texture::~Texture() {
    GLCall(glDeleteTextures(1, &_handle));
  }
  void Texture::bind(unsigned int slot) const {
    GLCall(glActiveTexture(GL_TEXTURE0 + slot));
    GLCall(glBindTexture(convert::targetToGL(_params.target), _handle));
  }
  void Texture::unbind() const {
    GLCall(glBindTexture(convert::targetToGL(_params.target), 0));
  }
  void Texture::setParams() {
    GLCall(glTexParameteri(convert::targetToGL(_params.target), GL_TEXTURE_MIN_FILTER, convert::minfilterToGL(_params.minfilter)));
    GLCall(glTexParameteri(convert::targetToGL(_params.target), GL_TEXTURE_MAG_FILTER, convert::magfilterToGL(_params.magfilter)));
    GLCall(glTexParameteri(convert::targetToGL(_params.target), GL_TEXTURE_WRAP_S, convert::wrapToGL(_params.wrapS)));
    GLCall(glTexParameteri(convert::targetToGL(_params.target), GL_TEXTURE_WRAP_T, convert::wrapToGL(_params.wrapT)));

  }
  void Texture::freeBuffer() {
    if (_localBuffer) {
      stbi_image_free(_localBuffer);
    }
  }

}