class Solution {
    bool check(vector<int> &count, vector<int> &count2)
    {
        for (int i = 0; i < 26; i++)
            if (count[i] != count2[i])
                return false;
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26, 0), count2(26, 0);
        int size = s1.length(), size2 = s2.length();
        for (int i = 0; i < size; i++)
            count[s1[i] - 'a']++;
        int k = 0;
        while (k < size && k < size2)
            count2[s2[k] - 'a']++, k++;
        if (check(count, count2))
            return true;
        // for (auto it : count)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : count2)
        //     cout << it << " ";
        //
        //sliding window
        while (k < size2)
        {
            count2[s2[k] - 'a']++;
            count2[s2[k - size] - 'a']--;
            k++;
            if (check(count, count2))
                return true;
        }
        return false;
    }
};