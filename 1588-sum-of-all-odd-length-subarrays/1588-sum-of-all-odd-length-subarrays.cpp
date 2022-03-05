class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for (int i = 0, size = arr.size(); i < size; ++i)
            res += ((size - i) * (i + 1) + 1) / 2 * arr[i];
        return res;
    }
};