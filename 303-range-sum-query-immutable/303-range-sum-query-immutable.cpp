class NumArray {
public:
    vector<int> acc;
    NumArray(vector<int>& nums) {
        acc.push_back(0);
        for (int num : nums)
            acc.push_back(acc.back() + num);
    }
    
    int sumRange(int left, int right) {
        return acc[right + 1] - acc[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */