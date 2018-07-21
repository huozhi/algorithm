/**

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.

Hide Tags Backtracking Trie


*/

class TrieNode {
public:
    // Initialize your data structure here.
    static const int N = 26;

public:
    TrieNode(): c(0), word(0) {
        for (int i = 0; i < N; i++)
            next[i] = nullptr;
    }

    TrieNode(char c): c(c), word(0) {
        for (int i = 0; i < N; i++)
            next[i] = nullptr;
    }

public:
    bool word;
    char c;
    TrieNode *next[N];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int n = s.length();
        TrieNode *curr = root;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            int idx = index(ch);
            TrieNode *next = curr->next[idx];
            if (!next) {
                curr->next[idx] = new TrieNode(ch);
            }
            curr = curr->next[idx];
        }
        curr->word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int n = key.length();
        TrieNode *curr = root;
        for (int i = 0; i < n; i++) {
            char ch = key[i];
            int idx = index(ch);
            TrieNode *next = curr->next[idx];
            if (next)
                curr = next;
            else
                return false;
        }
        return curr->word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode *curr = root;
        for (int i = 0; i < n; i++) {
            char ch = prefix[i];
            int idx = index(ch);
            TrieNode *next = curr->next[idx];
            if (next)
                curr = next;
            else
                return false;
        }
        return true;
    }

private:
    int index(char ch) {
        return ch - 'a';
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> uniq;
        vector<string> result;
        int n = board.size(), m = board.front().size();
        if (n == 0 || m == 0 || words.empty()) {
            result.assign(uniq.begin(), uniq.end());
            return result;
        }

        Trie trie;
        for (string& s : words)
            trie.insert(s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, uniq, trie, "", i, j);
            }
        }
        result.assign(uniq.begin(), uniq.end());
        return result;
    }

    void dfs(vector<vector<char>>& board,
        set<string>& uniq, Trie& trie, string word, int i, int j) {
        int n = board.size(), m = board.front().size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '\0')
            return;

        word.push_back(board[i][j]);
        if (!trie.startsWith(word)) {
            return;
        }
        if (trie.search(word)) {
            uniq.insert(word);
        }
        char temp = board[i][j];
        board[i][j] = '\0';
        dfs(board, uniq, trie, word, i + 1, j);
        dfs(board, uniq, trie, word, i, j + 1);
        dfs(board, uniq, trie, word, i - 1, j);
        dfs(board, uniq, trie, word, i, j - 1);
        board[i][j] = temp;
    }
};