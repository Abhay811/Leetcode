class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        int i = res.size() - 1;
        while (k > 0)
        {
            int t = min(k, 25);
            res[i] += t;
            k -= t;
            --i;
        }
        return res;
    }
};