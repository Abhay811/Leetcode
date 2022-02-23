class Solution {
public:
    string recurse(string &s, int &ind)
    {
        int c = 0;
        string res;
        for (int i = ind; i < s.length(); ++i)
        {
            if (s[i] == ']')
            {
                ind = i;
                return res;
            }
            else if (!isdigit(s[i])) res.push_back(s[i]);
            else
            {
                c = 0;
                while (isdigit(s[i]))
                {
                    c *= 10;
                    c += (s[i] - '0');
                    ++i;
                }
                ++i;
                string temp = recurse(s, i);
                while (c-- > 0) res.append(temp);
            }
        }
        return res;
    }
    string decodeString(string s) {
        int ind = 0;
        string res = recurse(s, ind);
        return res;
    }
};