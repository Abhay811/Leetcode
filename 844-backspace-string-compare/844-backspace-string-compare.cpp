class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str = "", str2 = "";
        
        for (int i = 0, size = s.size(); i < size; ++i)
            if (s[i] == '#')
                if (str == "") str = "";
                else str.pop_back();
            else str.push_back(s[i]);
        
        for (int i = 0, size = t.size(); i < size; ++i)
            if (t[i] == '#')
                if (str2 == "") str2 = "";
                else str2.pop_back();
            else str2.push_back(t[i]);
        
        return str == str2;
    }
};