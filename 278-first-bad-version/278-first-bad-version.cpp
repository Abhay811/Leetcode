// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
     
        int l = 0, r = n;
        int val = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) val = m, r = m -1;
            else l = m + 1;
        }
        return val;
    }
};