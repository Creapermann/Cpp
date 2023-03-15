#pragma once
#include <compare>
#include <variant>
#include "details.hpp"
#include "unexpected.hpp"
#include "bad_expected_access.hpp"
#include <iostream>

namespace my_std
{

template<Copyable T, Copyable E>
class expected
{
public:
    //    expected() requires DefaultConstructable<T>
    //    {
    //    }
    
    expected(const T& value)
        : m_data(value)
    {
    }
    
    constexpr expected(unexpected<E>&& unexpected)
        : m_data(unexpected)
    {
    }
    
    constexpr expected& operator=(unexpected<E>&& unexpected)
    {
        m_data = unexpected;
    }
    
    T& operator*()
    {
        if(!hasValue())
            throw bad_expected_access(*getError());
        
        return *getValue();
    }
    
    constexpr operator bool() const
    {
        return hasValue();
    }
    
    constexpr std::strong_ordering operator<=>(const expected& other) const
    {
        return *getValue() <=> other.m_value;
    }
    
    constexpr std::strong_ordering operator<=>(const T& value) const
    {
        if(*getValue() < value)
            return std::strong_ordering::less;
        if(*getValue() > value)
            return std::strong_ordering::greater;
        return std::strong_ordering::equal;
    }
    
    expected<T, E>& andThen()
    {
        
    }
    
    constexpr bool hasValue()
    {
        return getValue() != nullptr;
    }
    
    T value()
    {
        if(!hasValue())
            throw bad_expected_access(*getError());
        
        return *getValue();
    }
    
    constexpr unexpected<E> error()
    {
        if(hasValue())
            throw bad_expected_access(*getError());
        
        return *getError();
    }
    
private:
    T* getValue()
    {
        auto data = std::get_if<T>(&m_data);
        if(!data)
            throw bad_expected_access(*getError());
        
        return data;
    }
    
    unexpected<E>* getError()
    {
        auto error = std::get_if<unexpected<E>>(&m_data);
        
        return error;
    }
    
    std::variant<T, unexpected<E>> m_data;
};

}