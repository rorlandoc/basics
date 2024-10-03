#ifndef RC_ARRAY_HPP
#define RC_ARRAY_HPP

#include <cstddef>

#include "rc/random_access_iterator.hpp"

namespace rc
{

// =============================================================================
// =============================================================================
//
// Declaration of the allocator class.
//
// =============================================================================
// =============================================================================
template <typename T, size_t N>
class array
{
  public:
    using iterator       = random_access_iterator<T>;
    using const_iterator = random_access_iterator<const T>;

    T &operator[](size_t index) { return m_data[index]; }
    const T &operator[](size_t index) const { return m_data[index]; }

    constexpr size_t size() const noexcept { return N; }

    iterator begin() { return iterator{m_data}; }
    iterator end() { return iterator{m_data + N}; }

    const_iterator begin() const { return const_iterator{m_data}; }
    const_iterator end() const { return const_iterator{m_data + N}; }

  private:
    T m_data[N];
};

} // namespace rc

#endif // !RC_ARRAY_HPP
