class Solution {
public:
    int integerReplacement(int n) {
        long t = n;
        int c = 0;
        while (t != 1)
        {
            if (t == 3) c += 1, t >>= 1;
            else if (t & 1) 
                if ((t + 1) % 4 == 0)
                    t += 1;
                else
                    t -= 1;
            else t >>= 1;
            c++;
        }
        return c;
    }
};