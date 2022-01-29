class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int s = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0)
                s += num1[i--] - '0';
            if (j >= 0)
                s += num2[j--] - '0';
            res = char(s % 10 + '0') + res;
            s = s / 10;
        }
        if (s)
            res = char(s + '0') + res;
        cout << res;
        return res;
    }
};