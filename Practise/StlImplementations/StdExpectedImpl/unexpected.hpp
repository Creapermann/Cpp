#pragma once
#include "details.hpp"
#include <utility>

namespace my_std
{

template<typename E>
class unexpected
{
public:
    using m_type = typename std::decay<E>::type;
    
    unexpected() = delete;
    
    template<typename G>
    unexpected(G&& error)
        : m_error(std::forward<G>(error))
    {
    }
    
    m_type getError() const
    {
        return m_error;
    }
    
    
private:
    m_type m_error;
};

template<typename E>
unexpected(E&&) -> unexpected<typename std::decay<E>::type>;  // deduction guide

}