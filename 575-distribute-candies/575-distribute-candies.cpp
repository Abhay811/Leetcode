class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s(candyType.begin(), candyType.end());
        int n = candyType.size() / 2;
        int size = s.size();
        return size > n ? n : size;
    }
};