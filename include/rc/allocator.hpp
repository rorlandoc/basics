#ifndef RC_ALLOCATOR_HPP
#define RC_ALLOCATOR_HPP

#include <cstddef>
#include <type_traits>

namespace rc
{

// =============================================================================
// =============================================================================
//
// Declaration of the allocator class.
//
// =============================================================================
// =============================================================================
template <typename T>
class allocator
{
  public:
    T *allocate(size_t n, const void *hint = nullptr);
    void deallocate(T *p, size_t n = 0);

    template <typename... Args>
    void construct(T *p, Args &&...args);
    void destroy(T *p);
};

// =============================================================================
// =============================================================================
//
// Definition of the allocator class.
//
// =============================================================================
// =============================================================================
template <typename T>
constexpr T *allocator<T>::allocate(size_t n, const void *)
{
    return static_cast<T *>(::operator new(n * sizeof(T)));
}

template <typename T>
constexpr void allocator<T>::deallocate(T *p, size_t)
{
    ::operator delete(p);
}

template <typename T>
template <typename... Args>
constexpr void allocator<T>::construct(T *p, Args &&...args)
{
    new (p) T(std::forward<Args>(args)...);
}

template <typename T>
constexpr void allocator<T>::destroy(T *p)
{
    p->~T();
}

} // namespace rc

#endif // !RC_ALLOCATOR_HPP