class Solution {
public:
    string oddString(vector<string>& words) {
        int size = words.size();
        int len = words[0].size();
        vector<int> res, res2, res3;
        for (int j = 1; j < len; j++)
            res.emplace_back(words[0][j] - words[0][j - 1]),
            res2.emplace_back(words[1][j] - words[1][j - 1]),
            res3.emplace_back(words[2][j] - words[2][j - 1]);
        bool r = true, r2 = true, r3 = true;
        for (int i = 0; i < len - 1; i++)
            if (res[i] != res2[i])
                r = false;
        for (int i = 0; i < len - 1; i++)
            if (res[i] != res3[i])
                r2 = false;
        for (int i = 0; i < len - 1; i++)
            if (res2[i] != res3[i])
                r3 = false;
        
        if (!r && !r2) res = res2;
        
        for (int i = 0; i < size; i++)
        {
            int k = 0;
            for (int j = 1; j < len; j++)
                if (words[i][j] - words[i][j - 1] != res[k++])
                    return words[i];
        }
        return "";
    }
};