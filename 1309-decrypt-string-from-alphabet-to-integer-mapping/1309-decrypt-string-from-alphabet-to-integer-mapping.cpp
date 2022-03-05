class Solution {
public:
    string freqAlphabets(string s) {
        stack<char> st;
        for(auto it : s) st.push(it);
        string res = "";
        while (!st.empty())
        {
            char c = st.top();
            st.pop();
            if (c == '#')
            {
                char t, p;
                t = st.top();
                st.pop();
                p = st.top();
                st.pop();
                int r = (p - '0') * 10 + (t - '0') - 1;
                res = char (r + 'a') + res;
            }
            else res = char (c - '0' + 'a' - 1) + res;
            
        }
        return res;
    }
};