class Solution {
public:
    int romanToInt(string s) {
         map<char, int> mp {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int size = s.size();
        int t = 0;
        for (int i = 0; i < size; i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
                t -= mp[s[i]];
            else
                t += mp[s[i]];
        }
        return t;
    }
};