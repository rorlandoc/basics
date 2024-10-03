#ifndef RC_VECTOR_HPP
#define RC_VECTOR_HPP

#include <cstddef>

#include "rc/allocator.hpp"
#include "rc/random_access_iterator.hpp"

namespace rc
{

// =============================================================================
// =============================================================================
//
// Declaration of the vector class.
//
// =============================================================================
// =============================================================================
template <typename T, typename A = allocator<T>>
class vector
{
  public:
    using iterator       = random_access_iterator<T>;
    using const_iterator = random_access_iterator<const T>;

    vector(size_t n, const T &value = T{});
    ~vector();

    T &operator[](size_t index) { return m_data[index]; }
    const T &operator[](size_t index) const { return m_data[index]; }

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }

    iterator begin() { return iterator{m_data}; }
    iterator end() { return iterator{m_data + m_size}; }

    const_iterator begin() const { return const_iterator{m_data}; }
    const_iterator end() const { return const_iterator{m_data + m_size}; }

    void reserve(size_t n);

    void push_back(const T &value);

  private:
    A m_allocator;
    T *m_data;
    size_t m_size;
    size_t m_capacity;
};

// =============================================================================
// =============================================================================
//
// Definition of the vector class.
//
// =============================================================================
// =============================================================================
template <typename T, typename A>
vector<T, A>::vector(size_t n, const T &value)
    : m_allocator(A{}), m_size(n), m_capacity(n)
{
    m_data = m_allocator.allocate(n);
    for (size_t i = 0; i < m_size; i++)
    {
        m_allocator.construct(&m_data[i], value);
    }
}

template <typename T, typename A>
vector<T, A>::~vector()
{
    for (size_t i = 0; i < m_size; i++)
    {
        m_allocator.destroy(&m_data[i]);
    }
    m_allocator.deallocate(m_data, m_capacity);
}

template <typename T, typename A>
void vector<T, A>::reserve(size_t n)
{
    if (n <= m_capacity)
    {
        return;
    }

    T *new_data = m_allocator.allocate(n);
    for (size_t i = 0; i < m_size; i++)
    {
        m_allocator.construct(&new_data[i], m_data[i]);
        m_allocator.destroy(&m_data[i]);
    }
    for (size_t i = m_size; i < n; i++)
    {
        m_allocator.construct(&new_data[i], T{});
    }
    m_allocator.deallocate(m_data, m_capacity);

    m_data     = new_data;
    m_capacity = n;
}

template <typename T, typename A>
void vector<T, A>::push_back(const T &value)
{
    if (m_size == m_capacity)
    {
        reserve(m_capacity * 2);
    }
    m_allocator.construct(&m_data[m_size++], value);
}

} // namespace rc

#endif // !RC_VECTOR_HPP