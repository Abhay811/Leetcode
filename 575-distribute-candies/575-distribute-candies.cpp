class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        int n = candyType.size();
        for (auto it : candyType)
            s.insert(it);
        int size = s.size();
        return size > n / 2 ? n / 2 : size;
    }
};