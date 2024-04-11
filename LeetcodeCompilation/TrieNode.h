#pragma once

#include <string>


struct TrieNode
{
    TrieNode* children[26] { nullptr };
    bool isWord            { false };
    std::string* word      { nullptr }; // will only point to a value if word is valid
};