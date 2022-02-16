class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        int n = candyType.size() / 2;
        for (auto it : candyType)
            s.insert(it);
        int size = s.size();
        return size > n ? n : size;
    }
};