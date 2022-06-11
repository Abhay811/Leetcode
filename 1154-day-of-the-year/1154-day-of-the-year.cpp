class Solution {
    vector<int> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    
    int dayOfYear(string date) {
        int yr = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int days = stoi(date.substr(8, 2));
        int leap = 0;
        if (yr % 400 == 0 || ((yr % 4 == 0) && (yr % 100 != 0)))
            leap = 1;
        int res = 0;
        for (int i = 1; i < month; i++) 
            res += months[i];
        if (month > 2)
            res += days + leap;
        else res += days;
        return res;
    }
};