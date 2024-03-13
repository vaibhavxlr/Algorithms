class TrieNode {
public:
    bool endOfWord;
    vector<TrieNode*> children;

    TrieNode() {
        endOfWord = false;
        children.resize(26, NULL);
    }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* curr = root;
        for (auto& s : word) {
            int ind = s - 'a';
            if (!curr->children[ind]) {
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (auto& ch : word) {
            node = node->children[ch - 'a'];
            if (!node) {
                return false;
            }
        }

        return node->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (auto& ch : prefix) {
            node = node->children[ch - 'a'];
            if (!node) {
                return false;
            }
        }

        return true;
    }

    ~Trie() { clear(root); }

    void clear(TrieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                clear(root->children[i]);
            }
        }

        delete root;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */