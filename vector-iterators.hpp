#ifndef VECTOR_ITERATORS_HPP
#define VECTOR_ITERATORS_HPP
#include <cstddef> 
namespace topit
{
  template< class T > struct Vector;

  template< class T >
  struct VIter
  {
    VIter();
    VIter(const VIter&);
    VIter(T*);
    
    VIter< T >& operator++();
    VIter< T > operator++(int);
    VIter< T > operator+=(int);

    T& operator*() const noexcept;
    T* operator->() const noexcept;

    bool operator==(const VIter< T >&) const noexcept;
    bool operator!=(const VIter< T >&) const noexcept;
  private:
    T* node;
  };
}
#endif