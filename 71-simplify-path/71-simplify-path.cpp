class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> str;
        stringstream ss(path);
        while (getline(ss, temp, '/'))
        {
            if (temp == "" or temp == ".") continue;
            if (temp == ".." and !str.empty()) str.pop_back();
            else if (temp != "..") str.push_back(temp);
        }
        for (auto s : str) res += "/" + s;
        return res.empty() ? "/" : res;
    }
};