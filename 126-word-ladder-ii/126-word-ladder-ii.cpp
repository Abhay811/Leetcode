class Solution {
public:
    unordered_map<string, vector<string>> adj;
    void dfs(string node, vector<vector<string>> &ans, vector<string> &curr, string beginWord)
    {
        if(node == beginWord)
        {
            ans.push_back(curr);
            return;
        }
        for(string &nbr : adj[node])
        {
            curr.push_back(nbr);
            dfs(nbr, ans, curr, beginWord);
            curr.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        vector<vector<string>> ans;
        
        unordered_map<string, int> list;
        for(string &word : wordList) list[word] = INT_MAX;
        if(list.find(endWord) == list.end()) return ans;
        queue<string> q;
        
        q.push(beginWord);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            ++level;
            for(int i=0; i<n; ++i)
            {
                string front = q.front();
                q.pop();
                for(int j=0; j<front.size(); ++j)
                {
                    string newWord = front;
                    for(char letter='a'; letter<='z'; ++letter)
                    {
                        newWord[j] = letter;
                        if(newWord != front && list.find(newWord) != list.end() && list[newWord] >= level)
                        {
                            adj[newWord].push_back(front);
                            if(list[newWord] == level) continue;
                            list[newWord] = level;
                            if(newWord != endWord) q.push(newWord);
                        }
                    }
                }
            }
        }
        vector<string> curr({endWord});
        dfs(endWord, ans, curr, beginWord);
        for(int i=0; i<ans.size(); ++i) reverse(ans[i].begin(), ans[i].end());
        
        return ans;
    }
};