class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> arr;
        while (n)
        {
            arr.emplace_back(n % 10);
            n /= 10;
        }
        int s = 0, p = 1;
        for (auto it : arr)
            s += it, p *= it;
        return p - s;
    }
};