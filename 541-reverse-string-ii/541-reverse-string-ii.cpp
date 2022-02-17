class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0, size = s.length(); i < size; i += k + k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};