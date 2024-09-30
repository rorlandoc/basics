#ifndef RC_ARRAY_HPP
#define RC_ARRAY_HPP

#include <cstddef>
#include <stdexcept>

namespace rc
{

template <typename Data, size_t Size>
class array
{
  public:
    array(Data &&init_value)
    {
        for (size_t i = 0; i < Size; i++)
        {
            m_data[i] = init_value;
        }
    }

    constexpr size_t size() { return Size; }

    Data &operator[](size_t index)
    {
        if (is_index_valid(index)) return m_data[index];
        throw std::runtime_error{"[rc::array] Index out of range."};
    }

    const Data &operator[](size_t index) const
    {
        if (is_index_valid(index)) return m_data[index];
        throw std::runtime_error{"[rc::array] Index out of range"};
    }

  protected:
    bool is_index_valid(size_t index) { return (index >= 0 && index < Size); }

  private:
    Data m_data[Size];
};

} // namespace rc

#endif // !RC_ARRAY_HPP
