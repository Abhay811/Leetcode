class Solution {
public:
    string interpret(string command) {
        string res = "";
        for (int i = 0, size = command.length(); i < size; ++i)
            if (command[i] == '(' && command[i + 1] == ')')
                res += "o", i++;
            else if (command[i] == '(')
                continue;
            else if (command[i] == ')')
                continue;
            else
                res += command[i];
        return res;
    }
};