class Solution {
public:
    int nthUglyNumber(int k, int A, int B, int C) {
        //venn diagram
        
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int m = lo + (hi - lo)/2;
            int cnt = m/a + m/b + m/c - m/ab - m/bc - m/ac + m/abc;
            if(cnt < k) 
                lo = m + 1;
            else
                hi = m;
        }
        return lo;
    }
};