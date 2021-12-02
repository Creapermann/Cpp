#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "soundex_export.h"


class Soundex
{
public:
    SOUNDEX_EXPORT Soundex();
    SOUNDEX_EXPORT std::string encode(const std::string& name) const;
    
private:
    std::string fix_formatting(std::string name) const;
    std::string remove_vowel_like_letters(const std::string& name) const;
    std::string remove_adjacend_encoded_duplicates(const std::string& name) const;
    std::string encode_name(const std::string& name) const;
    
    std::string string_to_lower(const std::string& str) const;
    bool contains_vorbidden_characters(const std::string& str) const;
    
    template<typename Container, typename Value>  bool contains_value(const Container& container, const Value& value) const;
    template<typename K, typename V> bool contains_value(const std::unordered_map<K, V>& map, const K& key) const;
    
    
    std::vector<char> letters_to_remove;
    std::vector<char> ignored_duplicate_seperator;
    std::unordered_map<char, int> encode_map;
    static constexpr int soundex_length = 4;
};