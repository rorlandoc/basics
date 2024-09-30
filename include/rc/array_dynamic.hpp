#ifndef RC_ARRAY_DYNAMIC_HPP
#define RC_ARRAY_DYNAMIC_HPP

#include "rc/allocator.hpp"

namespace rc
{

// =============================================================================
// =============================================================================
//
// Declaration of the array_dynamic class.
//
// =============================================================================
// =============================================================================
template <typename T, typename A = allocator<T>>
class array_dynamic
{
  public:
    array_dynamic(size_t n, const T &value = T{});
    ~array_dynamic();

    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    size_t size() const;

  private:
    T *m_data;
    A m_allocator;
    size_t m_size;
};

// =============================================================================
// =============================================================================
//
// Definition of the array_dynamic class.
//
// =============================================================================
// =============================================================================
template <typename T, typename A>
array_dynamic<T, A>::array_dynamic(size_t n, const T &value)
    : m_allocator(A{}), m_size(n)
{
    m_data = m_allocator.allocate(n);
    for (size_t i = 0; i < m_size; i++)
    {
        m_allocator.construct(&m_data[i], value);
    }
}

template <typename T, typename A>
array_dynamic<T, A>::~array_dynamic()
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_allocator.destroy(&m_data[i]);
    }
    m_allocator.deallocate(m_data);
}

template <typename T, typename A>
T &array_dynamic<T, A>::operator[](size_t index)
{
    return m_data[index];
}

template <typename T, typename A>
const T &array_dynamic<T, A>::operator[](size_t index) const
{
    return m_data[index];
}

template <typename T, typename A>
size_t array_dynamic<T, A>::size() const
{
    return m_size;
}

} // namespace rc

#endif // !RC_ARRAY_DYNAMIC_HPP