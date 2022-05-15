class Solution {
public:
   int maxScore_v2_gcd(int a, int b) {
	if (a % b == 0) return b;
	return maxScore_v2_gcd(b, a % b);
}

void maxScore_v2_(int idx, vector<int>& nums, vector<bool>& visited, vector<int>& vec, int& res) {

	if (idx >= nums.size()) {
		vector<int> tmp = vec;
		sort(tmp.begin(), tmp.end());
		int val = 0;
		for (int i = 1; i <= tmp.size(); ++i) {
			val += i * tmp[i - 1];
		}
		res = max(res, val);
		return;
	}

	if (visited[idx])
		return maxScore_v2_(idx + 1, nums, visited, vec, res);

	visited[idx] = true;

	for (int i = idx + 1; i < nums.size(); ++i) {
		if (visited[i]) continue;
		visited[i] = true;
		vec.push_back(maxScore_v2_gcd(max(nums[idx], nums[i]), min(nums[idx], nums[i])));
		maxScore_v2_(idx + 1, nums, visited, vec, res);
		vec.pop_back();
		visited[i] = false;
	}

	visited[idx] = false;
	return;
}

int maxScore(vector<int>& nums) {
	int res = 0;
	vector<bool> visited(nums.size(), 0);
	vector<int> vec;
	maxScore_v2_(0, nums, visited, vec, res);
	return res;
}
};