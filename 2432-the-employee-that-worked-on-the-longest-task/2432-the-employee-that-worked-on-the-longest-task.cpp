class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& A) {
        int len = A[0][1], id = A[0][0];
        for (int i = 1; i < size(A); i++){
            int curr = A[i][1] - A[i - 1][1];
            if (curr > len || curr == len and id > A[i][0])  len = curr, id = A[i][0]; 
        }
        return id;
    }
};