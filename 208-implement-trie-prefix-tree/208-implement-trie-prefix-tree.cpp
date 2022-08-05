class Trie {
    Trie* next[26] = {};
    bool isword = false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for (auto it : word)
        {
            it -= 'a';
            if (!node->next[it]) node -> next[it] = new Trie();
            node = node->next[it];
        }
        node->isword = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (auto it : word) {
            it -= 'a';
            if (!node->next[it]) return false;
            node = node->next[it];
        }
        return node->isword;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto it: prefix) {
            it -= 'a';
            if (!node->next[it]) return false;
            node = node->next[it];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */