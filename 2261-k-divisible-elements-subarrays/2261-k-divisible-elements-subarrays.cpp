class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
                int n(size(nums)), res(0);
            unordered_set<string> us; // stores unique subarray which satisfy the given condition.
        
            for (int i=0; i<n; i++) {
                for (int len=i; len<=n; len++) {
                    int cnt(0);
                    string currSubArray; // stores subarray starting from index i of length len in the form of ascii.
                    for (int j=i; j<len; j++) {
                        currSubArray.push_back(nums[j]);
                        if (nums[j] % p == 0)  cnt++;
                    }
                // if the current array have at most k elements divisible by  then add it to the set.
                    if (cnt <= k and !currSubArray.empty())    us.insert(currSubArray);
                }
            }
        return size(us);
    }
};