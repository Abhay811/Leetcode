class Solution {
public:
    bool solve(vector<int> &sides, vector<int>&matches, int ind, int tar) {
        if (ind == matches.size())
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matches[ind] > tar) continue;
            int j = i;
            while(--j >= 0)
                if(sides[i] == sides[j])
                    break;
            if (j != -1) continue;
            sides[i] += matches[ind];
            if (solve(sides, matches, ind + 1, tar)) return true;
            sides[i] -= matches[ind];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int s = 0;
        for (auto it: matchsticks) s += it;
        if (s % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sides(4, 0);
       
        return solve(sides, matchsticks, 0, s/4);
    }
};