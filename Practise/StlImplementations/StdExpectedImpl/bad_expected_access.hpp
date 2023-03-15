#pragma once
#include <exception>
#include <type_traits>

namespace my_std
{

template<typename E>
class bad_expected_access : public std::exception
{
public:
    template<typename G>
    explicit bad_expected_access(G&& error)
        : m_error(std::forward<G>(error))
    {
    }
    
    E getError()
    {
        return m_error;
    }
    
private:
    E m_error;
};

template<typename E>
bad_expected_access(E&& error) -> bad_expected_access<typename std::decay<E>::type>;

}