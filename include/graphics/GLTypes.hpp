//
// Created by asuna on 3/12/2020.
//

#ifndef ENGINE_GLTYPES_HPP
#define ENGINE_GLTYPES_HPP

#define GL_FALSE 0
#define GL_TRUE 1
#define GL_BYTE                           0x1400
#define GL_UNSIGNED_BYTE                  0x1401
#define GL_INT                            0x1404
#define GL_UNSIGNED_INT                   0x1405
#define GL_FLOAT                          0x1406
#define GL_SHORT                          0x1402
#define GL_UNSIGNED_SHORT                 0x1403

#define GL_CLAMP 0x2900

namespace eng {

  enum class Wrapp {
    Repeat,
    MirroredRepeat,
    ClampToEdge,
    ClampToBorder
  };

  enum class TextureMinFilter {
    Nearest,
    Linear,
    NearestMipmapNearest,
    LinearMipmapNearest,
    NearestMipmapLinear,
    LinearMipmapLinear
  };

  enum class TextureMagFilter {
    Nearest,
    Linear,
  };

  enum class Target {
    Texture1D,
    Texture2D,
    Texture2DArray,
    Texture3D,
    TextureCubeMap,
    TextureCubeMapArray
  };

  enum class TextureFormat {
    RGB8,
    RGBA8
  };

}


#endif //ENGINE_GLTYPES_HPP
