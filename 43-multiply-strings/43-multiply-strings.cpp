class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        string res(len1 + len2, '0');
        for (int i = len1 - 1; i >= 0; --i)
        {
            int c = 0;
            for (int j = len2 - 1; j >= 0; --j)
            {
                int t = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] -'0') + c;
                res[i + j + 1] = t % 10 + '0';
                c = t / 10;
            }
            res[i] += c;
        }
        size_t pos = res.find_first_not_of("0");
        if (string::npos != pos)
            return res.substr(pos);
        return "0";
    }
};