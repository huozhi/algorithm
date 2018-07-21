/**

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters 'a-z' or '.'.
A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

*/

class WordDictionary {
public:
    struct node {
        bool word;
        node* next[26];
        node(): word(false) {
            memset(next, 0, sizeof(next));
        }
    };


    // Adds a word into the data structure.
    void addWord(string word) {
        node *curr = &root;
        for (int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (!curr->next[idx]) {
                curr->next[idx] = new node;
            }
            curr = curr->next[idx];
        }
        curr->word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.empty())
            return false;
        return search(word, 0, &root);
    }

private:
    bool search(string &word, int index, node *curr) {
        if (index == word.length()) {
            return curr && curr->word;
        }
        if (!curr)
            return false;
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->next[i] && search(word, index + 1, curr->next[i])) {
                    return true;
                }
            }
            return false;
        }
        else {
            int i = word[index] - 'a';
            return search(word, index + 1, curr->next[i]);
        }
    }

private:
    node root;
};




// Your WordDictionary object will be instantiated and called as such:
    // WordDictionary dict;

    // dict.addWord("ran"),
    // dict.addWord("rune"),
    // dict.addWord("runner"),
    // dict.addWord("runs"),
    // dict.addWord("add"),
    // dict.addWord("adds"),
    // dict.addWord("adder"),
    // dict.addWord("addee"),
    // cout << dict.search("r.n") << endl;//1
    // cout << dict.search("ru.n.e") << endl;//0
    // cout << dict.search("add") << endl;//1
    // cout << dict.search("add.") << endl;//1
    // cout << dict.search("adde.") << endl;//1
    // cout << dict.search(".an.") << endl; // 0
    // cout << dict.search("...s") << endl;//1
    // cout << dict.search("....e.") << endl;//1
    // cout << dict.search(".......") << endl;//0
    // cout << dict.search("..n.r") << endl;//0
