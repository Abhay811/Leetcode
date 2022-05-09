class Solution {
public:
     const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
		vector<string> res;
        res.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp;
            for(auto candidate: pad[digit - '0']) {
                for(auto s: res) {
                    tmp.push_back(s + candidate);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};