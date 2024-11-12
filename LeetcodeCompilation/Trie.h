#pragma once

#include "Solution.h"
#include "TrieNode.h"

#include <unordered_set>
#include <vector>


class Trie : public Solution
{
public:
    Trie() : Solution("Trie", "Common challenge problems involving prefix trees (tries)."), root { new TrieNode() } {}
    std::unique_ptr<Solution> clone() const override { return std::make_unique<Trie>(*this); }

    void insert(const std::string& word);
    bool search(const std::string& word);
    bool startsWith(const std::string& prefix);
    bool searchWildcard(const std::string& word);
    void insertRef(std::string& word);
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words);

    // Add and Search Words DS
    // Search Suggestions System

private:
    bool dfsWildcard(const std::string& word, unsigned index, TrieNode* root);
    void dfsWordSearch(std::vector<std::vector<char>>& board, int i, int j, TrieNode* cur, const int* DIR, std::vector<std::string>& ans);

    std::unordered_set<std::string> wordset;
    TrieNode* root;
};