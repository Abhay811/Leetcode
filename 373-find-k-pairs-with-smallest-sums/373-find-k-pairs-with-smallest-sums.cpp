class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> mxheap;
        if (n == 0 || m == 0 || k <= 0) return res;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int s = nums1[i] + nums2[j];
                if (mxheap.size() < k) mxheap.push({s, {nums1[i], nums2[j]}});
                else if (mxheap.top().first > s) {
                    mxheap.pop();
                    mxheap.push({s, {nums1[i], nums2[j]}});
                }
                else break;
            }
        while(!mxheap.empty())
        {
            res.push_back({mxheap.top().second.first, mxheap.top().second.second});
            mxheap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};