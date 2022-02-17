class Solution {
public:
    string toLowerCase(string s) {
        for (auto &it : s)
            if (isupper(it))
                it ^= 32;
        return s;
    }
};