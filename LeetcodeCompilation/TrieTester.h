#pragma once

#include "Trie.h"
#include "Tester.h"


class TrieTester : public Tester
{
public:
    TrieTester() : Tester { "Trie" } {}
    bool testAllProblems() override;
    std::unique_ptr<Tester> clone() const override { return std::make_unique<TrieTester>(*this); }

private:
    bool testBasicTrie();
    bool testWildcard();
    bool testWordSearch(std::vector<std::vector<char>> board, std::vector<std::string> words, std::vector<std::string> expected);

    // Add and Search Words DS
    // Search Suggestions System
};
