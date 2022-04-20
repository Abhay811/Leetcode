class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size(), lsum = 0;
        for (int i = 0; i < k; ++i)
            lsum += cardPoints[i];
        
        int res = lsum;
        for (int rsum = 0, i = 0; i < k; ++i)
        {
            rsum += cardPoints[size - 1 - i];
            lsum -= cardPoints[k - 1 - i];
            res = max(res, lsum + rsum);
        }
        return res;
    }
};