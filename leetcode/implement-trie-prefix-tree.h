/**

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/

class TrieNode {
public:
    // Initialize your data structure here.
    static const int N = 26;

public:
    TrieNode(): c(0), isend(0) {
        for (int i = 0; i < N; i++)
            next[i] = nullptr;
    }

    TrieNode(char c): c(c), isend(0) {
        for (int i = 0; i < N; i++)
            next[i] = nullptr;
    }

public:
    bool isend;
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
        curr->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int n = key.length();
        TrieNode *curr = root;
        for (int i = 0; i < n; i++) {
            char ch = key[i];
            int idx = index(ch);
            TrieNode *next = curr->next[idx];
            if (next) {
                curr = next;
            }
            else {
                return false;
            }
        }
        return curr->isend;
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
            if (next) {
                curr = next;
            }
            else {
                return false;
            }
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