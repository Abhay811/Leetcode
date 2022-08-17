class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> str{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> res;
        for (int i = 0; i < words.size(); i++)
        {
            string s = "";
            for(auto it : words[i])
                s += str[it - 'a'];
            res.insert(s);
        }
        return res.size();
    }
};