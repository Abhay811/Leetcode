class Solution {
public:
    int tribonacci(int n) {
        int v[3] = {0, 1, 1};
        if (n == 0)
            return 0;
        if (n < 3)
            return 1;
        int prevInd = 2;
        int secondlastInd = 1;
        int thirdlastInd = 0;
        for (int i = 3; i <= n; i++)
        {
            int t = v[prevInd] + v[secondlastInd] + v[thirdlastInd];
            v[thirdlastInd] = v[secondlastInd];
            v[secondlastInd] = v[prevInd];
            v[prevInd] = t;
        }
        return v[prevInd];
        
    }
};