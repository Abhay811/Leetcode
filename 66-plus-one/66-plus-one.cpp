class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {      
        int size = digits.size();
        int i = size - 1;
        while(i >= 0){
            if(digits[i] != 9){
                digits[i]++;
                break;
            }
            else {
                digits[i] = 0;
            }
            i--;
        }
        if (digits[0] == 0) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};