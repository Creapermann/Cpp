#include "Soundex.hpp"


Soundex::Soundex()
    : 
      letters_to_remove{'a', 'e', 'i', 'o', 'u', 'y', 'h', 'w'},
      ignored_duplicate_seperator{'h', 'w', 'y'},
      encode_map {
                    {'b', 1}, {'f', 1}, {'p', 1}, {'v', 1},
                    {'c', 2}, {'g', 2}, {'j', 2}, {'k', 2}, {'q', 2}, {'s', 2}, {'x', 2}, {'z', 2},
                    {'d', 3}, {'t', 3},
                    {'l', 4},
                    {'m', 5}, {'n', 5},
                    {'r', 6}
                 }
{
}


std::string Soundex::encode(const std::string& name) const
{
    if(name.empty()) return "0000";
    if(contains_vorbidden_characters(name)) throw std::invalid_argument("Name may only contain letters");
    
    
    std::string result = remove_adjacend_encoded_duplicates(string_to_lower(name));
    
    char first_letter = std::toupper(name.front());
    result = first_letter + remove_vowel_like_letters(result.substr(1));
    
    result = fix_formatting(result);
    
    return encode_name(result);
}

std::string Soundex::fix_formatting(std::string name) const
{
    // Appends 0 to the string for every missing character
    for(std::size_t i{name.size()}; i < soundex_length; ++i)
    {
        name.append("0");
    }
    
    // Shortens string to 4 characters max
    return name.substr(0, 4);
}

std::string Soundex::remove_vowel_like_letters(const std::string& name) const
{
    /* Vowel like letters defined as: a,e,i,o,u,h,w,y */
    std::string result;
    
    for(char letter : name)
    {
        if(std::find(letters_to_remove.begin(), letters_to_remove.end(), letter) == letters_to_remove.end())
            result += letter;
    }
    
    return result;
}

std::string Soundex::remove_adjacend_encoded_duplicates(const std::string& name) const
{
    std::string result;
    
    int prev_value = -1;
    for(int i{0}; i < name.length(); ++i)
    {
        if(!contains_value(encode_map, name.at(i)))                    // Vowel
        {
            result += name.at(i);
            
            if(!contains_value(ignored_duplicate_seperator, name[i]))  // Not an ignored seperator
                prev_value = -1;
            
        }
        else if(encode_map.at(name.at(i)) != prev_value)               // New value
        {
            result += name.at(i);
            prev_value = encode_map.at(name.at(i));
        }
    }
    return result;
}

std::string Soundex::encode_name(const std::string& name) const
{
    std::string result;
    result += name.front();
    
    for(char c : name.substr(1))
    {
        if(c == '0')
            result += "0";
        else
            result += std::to_string(encode_map.at(c));
    }
    
    return result;
}

std::string Soundex::string_to_lower(const std::string& str) const
{
    std::string result = str;
    std::transform(str.begin(), str.end(), result.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
    
    return result;
}

bool Soundex::contains_vorbidden_characters(const std::string& str) const
{
    if(str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos)
        return true;
    return false;
}

template<typename Container, typename Value>
bool Soundex::contains_value(const Container& container, const Value& value) const
{
    return std::find(container.begin(), container.end(), value) != container.end();
}

template<typename K, typename V>
bool Soundex::contains_value(const std::unordered_map<K, V>& map, const K& key) const
{
    return map.find(key) != map.end();
}
