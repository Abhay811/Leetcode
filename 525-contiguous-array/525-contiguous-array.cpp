class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int s = 0, l = 0;
        map<int, int> sn{{0, -1}};
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i] == 1 ? 1 : -1;
            if (sn.count(s)) l = max(l, i - sn[s]);
            else sn[s] = i;
        }
        return l;
    }
};