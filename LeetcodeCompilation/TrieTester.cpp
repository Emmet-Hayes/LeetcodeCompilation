#include "TrieTester.h"


bool TrieTester::testAllProblems()
{
    addTestCase(testBasicTrie());
    addTestCase(testWildcard());
    addTestCase(testWordSearch({ { 'o', 'a', 'a', 'n' },
                                 { 'e', 't', 'a', 'e' },
                                 { 'i', 'h', 'k', 'r' },
                                 { 'i', 'f', 'l', 'v' } },
                                 { "oath", "pea", "eat", "rain" },
                                 { "oath", "eat" }));

    addTestCase(testWordSearch({ { 'a', 'b' },
                                 { 'c', 'd' }},
                                 { "abcb" }, {}));

    return runAllTests();
}

bool TrieTester::testBasicTrie()
{
    Trie t;
    t.insert("apple");
    if (true != t.search("apple")) return false;
    if (false != t.search("app")) return false;
    if (true != t.startsWith("app")) return false;
    t.insert("app");
    if (true != t.search("app")) return false;
    return true;
}

bool TrieTester::testWildcard()
{
    Trie t;
    t.insert("bad");
    t.insert("dad");
    t.insert("mad");
    if (false != t.searchWildcard("pad")) return false;
    if (true != t.searchWildcard("bad")) return false;
    if (true != t.searchWildcard(".ad")) return false;
    if (true != t.searchWildcard("b..")) return false;
    return true;
}

bool TrieTester::testWordSearch(std::vector<std::vector<char>> board, 
                                std::vector<std::string> words, 
                                std::vector<std::string> expected)
{
    Trie t;
    std::vector<std::string> actual = t.findWords(board, words);
    if (getVerbose())
    {
        ss << "\nWord Search Test Run on Given Board:\n\n";
        for (std::vector<char> row : board)
        {
            for (char c : row)
                ss << c << " ";
            ss << "\n";
        }
        ss << "\nWords: ";
        for (std::string word : words)
            ss << word << " ";
        ss << "\nResult:   ";
        for (std::string word : actual)
            ss << word << " ";
        ss << "\nExpected: ";
        for (std::string word : expected)
            ss << word << " ";
        ss << "\n";
    }
    if (actual.size() != expected.size()) return false;
    for (unsigned i = 0; i < expected.size(); ++i)
        if (actual[i].compare(expected[i]) != 0)
            return false;
    return true;
}
