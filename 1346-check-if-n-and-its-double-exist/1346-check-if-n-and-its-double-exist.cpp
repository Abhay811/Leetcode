class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        for (int i = 0, size = arr.size(); i < size; ++i)
        {
            if (s.count(2 * arr[i]) > 0 || (arr[i] % 2 == 0) && s.count(arr[i] / 2) > 0)
                return true;
            s.insert(arr[i]);
        }
        return false;
    }
};