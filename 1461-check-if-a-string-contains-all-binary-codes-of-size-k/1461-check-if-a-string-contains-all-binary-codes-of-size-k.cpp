class Solution {
public:
   using Set = unordered_set<string>;
    using Deque = deque<char>;
    bool hasAllCodes(string s, int k, Set seen = {}, Deque q = {}) {
        for (auto c: s) {
            q.push_back(c);
            if (q.size() == k)
                seen.insert({ q.begin(), q.end() }), q.pop_front();
        }
        return seen.size() == 1 << k;
    }
};