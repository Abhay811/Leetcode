class Solution {
public:
    int minAddToMakeValid(string s) {
        int c = 0, m = 0;
        for (auto it : s)
            if (it == '(') c++;
            else if (it == ')' && c > 0) c--;
            else m++;
        return m + c;
    }
};