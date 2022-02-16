class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {   
        for (auto &it : image)
        {
            reverse(it.begin(), it.end());
            for (auto &it2 : it)
                it2 ^= 1;
        }
        return image;
    }
};