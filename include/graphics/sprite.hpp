//
// Created by asunan9sha on 3/22/2020.
//

#ifndef ENGINE_SPRITE_HPP
#define ENGINE_SPRITE_HPP

#include <memory>
#include <math/math.hpp>
#include <graphics/texture.hpp>

namespace eng {

  class Sprite {

  public:

    Sprite(const std::shared_ptr<Texture> &texture,
           const vec3 &pos,
           const vec2 &size,
           const vec4 &color = {1.0f, 1.0f, 1.0f, 1.0f})
        : _texture(texture), _pos(pos), _size(size), _color(color), _rot(0.0f), _transform(1.0f), _dirty(true) { }

    const vec3 &getPos() const { return _pos; }
    void setPos(const vec3 &pos) {
      _pos = pos;
      _dirty = true;
    }

    const mat4 &getTransform() const {
      if (_dirty) {
        mat4 translation = glm::translate(mat4(1.0f), _pos);
        _transform = glm::rotate(translation, glm::radians(_rot), {0.0f, 0.0f, 1.0f});
        _dirty = false;
      }
      return _transform;
    }

    const std::shared_ptr<Texture> &getTexture() const { return _texture; }
    void setTexture(const std::shared_ptr<Texture> &texture) { _texture = texture; }

    float getRot() const { return _rot; }
    void setRot(float rot) {
      _rot = rot;
      _dirty = true;
    }
    const vec4 &getColor() const {
      return _color;
    }
    void setColor(const vec4 &color) {
      _color = color;
    }
    vec2 getSize() const {
      return _size;
    }

  private:

    vec3 _pos;
    vec2 _size;
    vec4 _color;
    float _rot;

    mutable bool _dirty;

    mutable mat4 _transform;

    std::shared_ptr<Texture> _texture;
  };
}

#endif //ENGINE_SPRITE_HPP
