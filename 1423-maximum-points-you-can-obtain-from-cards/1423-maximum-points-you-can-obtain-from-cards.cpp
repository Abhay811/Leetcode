class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size(), lsum = 0;
        for (int i = 0; i < k; ++i)
            lsum += cardPoints[i];
        
        int res = lsum;
        int ls = size - 1, ks = k - 1;
        for (int rsum = 0, i = 0; i < k; ++i)
        {
            rsum += cardPoints[ls - i];
            lsum -= cardPoints[ks - i];
            res = max(res, lsum + rsum);
        }
        return res;
    }
};