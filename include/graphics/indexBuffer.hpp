//
// Created by asuna on 3/11/2020.
//

#ifndef ENGINE_INDEXBUFFER_HPP
#define ENGINE_INDEXBUFFER_HPP


namespace eng {
  class IndexBuffer {

  private:

    unsigned int _rendererID;
    unsigned int _count;

  public:

    IndexBuffer(const unsigned int *data, unsigned int count);
    ~IndexBuffer();
    void bind() const;
    void unbind() const;

    unsigned int getCount() const;
  };
}


#endif //ENGINE_INDEXBUFFER_HPP
