#ifndef RC_ARRAY_HPP
#define RC_ARRAY_HPP

#include <cstddef>
#include <expected>
#include <memory>

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
    T &operator[](size_t index);
    const T &operator[](size_t index) const;

    constexpr size_t size();

    void fill(T &&value);

  protected:
    bool is_index_valid(size_t index);

  private:
    T m_data[N];
};

// =============================================================================
// =============================================================================
//
// Definition of the allocator class.
//
// =============================================================================
// =============================================================================
template <typename T, size_t N>
T &array<T, N>::operator[](size_t index)
{
    if (is_index_valid(index)) return m_data[index];
    throw std::runtime_error{"[rc::array] Index out of range."};
}

template <typename T, size_t N>
const T &array<T, N>::operator[](size_t index) const
{
    if (is_index_valid(index)) return m_data[index];
    throw std::runtime_error{"[rc::array] Index out of range"};
}

template <typename T, size_t N>
constexpr size_t array<T, N>::size()
{
    return N;
}

template <typename T, size_t N>
void array<T, N>::fill(T &&value)
{
    for (size_t i = 0; i < N; ++i)
        m_data[i] = value;
}

template <typename T, size_t N>
bool array<T, N>::is_index_valid(size_t index)
{
    return (index >= 0 && index < N);
}

} // namespace rc

#endif // !RC_ARRAY_HPP
