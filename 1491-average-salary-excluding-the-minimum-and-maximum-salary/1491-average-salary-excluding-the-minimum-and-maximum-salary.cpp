class Solution {
public:
    double average(vector<int>& salary) {
        float mx = *max_element(salary.begin(), salary.end());
        float mn = *min_element(salary.begin(), salary.end());
        return double(accumulate(salary.begin(), salary.end(), 0) - mx - mn) / (salary.size() - 2);
    }
};