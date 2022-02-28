class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool first, second;
        first = false; second = false;
        char a, b;
        
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] != s2[i]) {
                if(!first) 
                {
                    first = true;
                    a = s1[i];
                    b = s2[i];
                }
                else if(!second) 
                {
                    second = true;
                    if(a != s2[i] || b != s1[i])
                        return false;
                }
                else
                    return false;
            }
        }
        return first == second; 
    }
};