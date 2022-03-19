class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int size = num.size();
        for (int i = size - 1; i >= 0 && k > 0; --i)
        {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while (k > 0)
        {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        return num;
    }
};