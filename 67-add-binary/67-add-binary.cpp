class Solution {
public:
    string addBinary(string a, string b) {
        
        int n = a.length() - 1, m = b.length() - 1;
        
        string str = "";
        int s = 0;
        while (n >= 0 || m >= 0 || s == 1)
        {
            s += ((n >= 0) ? a[n] - '0' : 0);
            s += ((m >= 0) ? b[m] - '0' : 0);
            
            str = char(s % 2 + '0') + str;
            s /= 2;
            n--, m--;
        }
        return str;        
    }
};