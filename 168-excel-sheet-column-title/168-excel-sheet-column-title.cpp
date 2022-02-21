class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while (n)
        {
            n--;
            s += n % 26 + 'A';
            n /= 26;            
        }
        reverse(s.begin(), s.end());
        return s; 
    }
};