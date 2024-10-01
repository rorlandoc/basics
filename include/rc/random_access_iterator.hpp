#ifndef RC_RANDOM_ACCESS_ITERATOR_HPP
#define RC_RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef>
#include <iterator>

namespace rc
{

// =============================================================================
// =============================================================================
//
// Declaration of the random_access_iterator class.
//
// =============================================================================
// =============================================================================
template <typename T,
          typename Ptr  = T *,
          typename Ref  = T &,
          typename Diff = ptrdiff_t>
class random_access_iterator
{
  public:
    using value_type        = T;
    using pointer           = Ptr;
    using reference         = Ref;
    using difference_type   = Diff;
    using iterator_category = std::random_access_iterator_tag;

    random_access_iterator(pointer ptr) : m_ptr{ptr} {}

    reference operator*() const { return *m_ptr; }
    reference operator[](difference_type n) const { return m_ptr[n]; }
    pointer operator->() const { return m_ptr; }

    random_access_iterator &operator++()
    {
        ++m_ptr;
        return *this;
    }
    random_access_iterator operator++(int)
    {
        random_access_iterator tmp{m_ptr};
        ++m_ptr;
        return tmp;
    }

    random_access_iterator &operator--()
    {
        --m_ptr;
        return *this;
    }
    random_access_iterator operator--(int)
    {
        random_access_iterator tmp{m_ptr};
        --m_ptr;
        return tmp;
    }

    random_access_iterator &operator+=(difference_type n)
    {
        m_ptr += n;
        return *this;
    }
    random_access_iterator &operator-=(difference_type n)
    {
        m_ptr -= n;
        return *this;
    }

    friend bool operator==(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return lhs.m_ptr == rhs.m_ptr;
    }
    friend bool operator!=(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return !(lhs == rhs);
    }
    friend bool operator<(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return lhs.m_ptr < rhs.m_ptr;
    }
    friend bool operator>(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return rhs < lhs;
    }
    friend bool operator<=(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return !(rhs < lhs);
    }
    friend bool operator>=(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return !(lhs < rhs);
    }

    friend random_access_iterator operator+(const random_access_iterator &lhs, difference_type n)
    {
        return random_access_iterator{lhs.m_ptr + n};
    }
    friend random_access_iterator operator+(difference_type n, const random_access_iterator &rhs)
    {
        return random_access_iterator{rhs.m_ptr + n};
    }
    friend random_access_iterator operator-(const random_access_iterator &lhs, difference_type n)
    {
        return random_access_iterator{lhs.m_ptr - n};
    }
    friend difference_type operator-(const random_access_iterator &lhs, const random_access_iterator &rhs)
    {
        return lhs.m_ptr - rhs.m_ptr;
    }

  private:
    T *m_ptr;
};

} // namespace rc

#endif // !RC_RANDOM_ACCESS_ITERATOR_HPP