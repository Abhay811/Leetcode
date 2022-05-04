class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 < n2) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, h = n2 * 2;
        while (l <= h)
        {
            int m2 = (l + h) / 2;
            int m1 = n1 + n2 - m2;
            
            double l1 = m1 == 0 ? INT_MIN : nums1[(m1 - 1) / 2];
            double l2 = m2 == 0 ? INT_MIN : nums2[(m2 - 1) / 2];
            double r1 = m1 == n1 * 2 ? INT_MAX : nums1[m1/ 2];
            double r2 = m2 == n2 * 2 ? INT_MAX : nums2[m2 / 2];
            
            if (l1 > r2) l = m2 + 1;
            else if (l2 > r1) h = m2 - 1;
            else return (max(l1, l2) + min(r1, r2)) / 2;
        }
        return -1;
    }
};