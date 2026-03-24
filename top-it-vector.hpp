#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>
namespace topit
{
  template< class T >
  struct Vector
  {
    Vector();
    ~Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    Vector& opearator=(const Vector&);
    Vector& operator=(Vector&&);

    bool isEmpty() const noexcept;
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;

    T& operator[](size_t id) noexcept;
    const T& operator[](size_t id) const noexcept;
    T& at(size_t id);
    const T& at(size_t id) const;

    void pushBack(const T&);
    void popBack();
    void insert(size_t, const T&);
    void earse(size_t);
  private:
    T* data_;
    size_t size_, capacity_;
  };
}
template< class T >
void topit::Vector< T >::pushBack(const T&)
{
  
}
template< class T >
topit::Vector< T >::~Vector()
{
  delete [] data_;
}
template< class T >
topit::Vector< T >::Vector():
  data_(nullptr),
  size_(0),
  capacity_(0)
{}
template< class T >
bool topit::Vector< T >::isEmpty() const noexcept
{
  return !size_;
}
template< class T >
size_t topit::Vector< T >::getSize() const noexcept
{
  return size_;
}
template< class T >
size_t topit::Vector< T >::getCapacity() const noexcept
{
  return capacity_;
}
template< class T >
void topit::Vector< T >::pushBack(const T& v)
{
  if (size_ == capacity_)
  {
    T* newData = nullptr;
    size_t i = 0;
    try
    {
      newData = new T [capacity_ + 1];
      for (; i < capacity_; ++i)
      {
        newData[i] = data_[i];
      }
      newData[i++] = v;
    }
    catch (...)
    {
      for (size_t j = 0; j < i; ++j)
      {
        newData[j].~T();
      }
      delete [] newData;
      throw;
    }
    for (size_t j = 0; j < size_; ++j)
    {
      data_[j].~T();
    }
    delete [] data_;
    data_ = newData;
    ++size_;
    ++capacity_;
    return;
  }
  data_[size_] = v;
  ++size_;
}
template< class T >
void topit::Vector< T >::popBack()
{
  if (size_ > 0)
  {
    data_[--size_].~T();
  }
}

template< class T >
T& topit::Vector< T >::operator[](size_t id) noexcept
{
  return data_[id];
}

template< class T >
T& topit::Vector< T >::at(size_t id)
{
  const Vector< T >* cthis = this;
  return const_cast< T& >(cthis->at(id));
}
template< class T >
const T& topit::Vector< T >::at(size_t id) const
{
  if (id < getSize())
  {
    return data_[id];
  }
  throw std::out_of_range("bad id");
}
#endif