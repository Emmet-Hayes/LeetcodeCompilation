#include "Trie.h"


void Trie::insert(const std::string& word)
{
    TrieNode* curr = root;

    for (char c : word)
    {
        if (!curr->children[c - 'a'])
            curr->children[c - 'a'] = new TrieNode();
        curr = curr->children[c - 'a'];
    }

    curr->isWord = true;
    wordset.insert(word);
}

bool Trie::search(const std::string& word)
{
    if (wordset.find(word) != wordset.end())
        return true; // skip the search if we already have it in the set
    TrieNode* curr = root;

    for (char c : word)
    {
        if (!curr->children[c - 'a'])
            return false;
        curr = curr->children[c - 'a'];
    }

    return curr->isWord;
}

bool Trie::startsWith(const std::string& prefix)
{
    TrieNode* curr = root;

    for (char c : prefix)
    {
        if (!curr->children[c - 'a'])
            return false;
        curr = curr->children[c - 'a'];
    }

    return true;
}

bool Trie::searchWildcard(const std::string& word)
{
    if (wordset.find(word) != wordset.end())
        return true; // skip the search if we already have it in the set
    return dfsWildcard(word, 0, root);
}

bool Trie::dfsWildcard(const std::string& word, int index, TrieNode* node)
{
    if (index == word.size()) return node->isWord;

    if (word[index] == '.')
    {
        for (int j = 0; j < 26; ++j)
            if (node->children[j] && dfsWildcard(word, index + 1, node->children[j]))
                return true;
        return false;
    }
    else
    {
        int idx = word[index] - 'a';
        return node->children[idx] && dfsWildcard(word, index + 1, node->children[idx]);
    }
}

void Trie::insertRef(std::string& word)
{
    TrieNode* curr = root;
    for (char c : word)
    {
        c -= 'a';
        if (!curr->children[c])
            curr->children[c] = new TrieNode();
        curr = curr->children[c];
    }
    curr->word = &word;
}

std::vector<std::string> Trie::findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
{
    int m = static_cast<int>(board.size()); 
    int n = static_cast<int>(board[0].size());
    int DIR[5] = { 0, 1, 0, -1, 0 };

    Trie trie;
    for (std::string& word : words)
        trie.insertRef(word);

    std::vector<std::string> ans;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            dfsWordSearch(board, i, j, trie.root, DIR, ans);

    return ans;
}

void Trie::dfsWordSearch(std::vector<std::vector<char>>& board, int i, int j, TrieNode* cur, const int* DIR, std::vector<std::string>& ans)
{
    if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] == '#' || !cur->children[board[i][j] - 'a'])
        return;

    char orgChar = board[i][j];
    cur = cur->children[orgChar - 'a'];

    if (cur->word)
    {
        ans.push_back(*cur->word);
        cur->word = nullptr;
    }

    board[i][j] = '#'; // cheaply mark as visited
    for (int k = 0; k < 4; ++k)
        dfsWordSearch(board, i + DIR[k], j + DIR[k + 1], cur, DIR, ans);
    board[i][j] = orgChar; // restore original state for next dfs runs
}