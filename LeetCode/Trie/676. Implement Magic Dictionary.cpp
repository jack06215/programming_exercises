#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class MagicDictionary {
public:
    MagicDictionary() {
        root = new TrieNode();
    }

    void buildDict(vector<string> dict) {
        for (auto x : dict) buildTrie(x);
    }

    bool search(string word) {
        TrieNode* p = root;
        int diff = 0;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            for (int j = 0; j < 26; j++) {
                if (p->next[j] == p->next[c - 'a']) {
                    continue;
                }
                if (p->next[j] && find(p->next[j], word.substr(i + 1))) {
                    return true;
                }
            }
            if (p->next[c - 'a']) {
                p = p->next[c - 'a'];
            }
        }
        return false;
    }

private:
    struct TrieNode {
        bool isWord;
        TrieNode* next[26];
        TrieNode() :isWord(false) {
            memset(next, NULL, sizeof(next));
        }
    };
    TrieNode* root;

    void buildTrie(string s) {
        TrieNode* p = root;
        for (auto c : s) {
            if (!p->next[c - 'a']) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }

    bool find(TrieNode* p, string s) {
        for (auto c : s)
            if (p->next[c - 'a']) {
                p = p->next[c - 'a'];
            }
            else return false;
        return p->isWord;
    }
};
