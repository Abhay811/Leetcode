class WordDictionary {
    unordered_map<int, vector<string>> words;
    bool isEqual(string wd1, string wd2) {
        for (int i = 0; i < wd1.size(); i++) {
            if (wd2[i] == '.')
                continue;
            if (wd1[i] != wd2[i])
                return false;
        }
        return true;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for (auto &&s : words[word.size()])
            if (isEqual(s, word))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */