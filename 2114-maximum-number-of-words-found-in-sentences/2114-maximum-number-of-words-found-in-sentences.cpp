class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int m = -1;
        for (auto it : sentences) 
        {
            int c = 0;
            for (char it2: it)
                if (it2 == ' ')
                    c++;
            m = c > m ? c : m;
        }
        return m + 1;
    }
};