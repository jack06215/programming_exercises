#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    bool is_word;
    TrieNode* children[26];
    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word_len; i++) {
            k = word[i] - 'a';
            if (cur->children[k] == nullptr) {
                cur->children[k] = new TrieNode();
            }
            cur = cur->children[k];
        }
        cur->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word_len; i++) {
            k = word[i] - 'a';
            cur = cur->children[k];

            if (cur == nullptr) {
                return false;
            }
        }

        return cur->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int word_len = prefix.length();
        int k = 0;
        TrieNode* cur = root;

        for (int i = 0; i < word_len; i++) {
            k = prefix[i] - 'a';
            cur = cur->children[k];

            if (cur == nullptr) {
                return false;
            }
        }
        return true;
    }
private:
    TrieNode* root;
};

class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }

private:
    unordered_map<char, Trie*> next = {};
    bool isword = false;
};
