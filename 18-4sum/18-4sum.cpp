class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        vector<vector<int>> res;
        int size = num.size();
        if (size < 4) return res;
        sort(num.begin(),num.end());
        for (int i = 0; i < size; i++) 
        {
            int target_3 = target - num[i];
            for (int j = i + 1; j < size; j++) 
            {
                int target_2 = target_3 - num[j];
                int front = j + 1;
                int back = size - 1;
                while(front < back) 
                {
                    int two_sum = num[front] + num[back];
                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else 
                    {
                        vector<int> quad(4, 0);
                        quad[0] = num[i];
                        quad[1] = num[j];
                        quad[2] = num[front];
                        quad[3] = num[back];
                        res.push_back(quad);
                        while (front < back && num[front] == quad[2]) ++front;
                        while (front < back && num[back] == quad[3]) --back;
                    }
                }
                while(j + 1 < size && num[j + 1] == num[j]) ++j;
            }
        while (i + 1 < size && num[i + 1] == num[i]) ++i;
        }
    
        return res;
    }
};