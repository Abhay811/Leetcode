class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0;
        bitset<32> b(n);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        cout << s << endl;
        bitset<32> b2(s);
        t = b2.to_ullong();
        return t;
    }
};