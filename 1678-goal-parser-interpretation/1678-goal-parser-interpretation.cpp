class Solution {
public:
    string interpret(string command) {
        string res = "";
        int flag = 0;
        for (int i = 0, size = command.length(); i < size; ++i)
            if (command[i] == '(' && command[i + 1] == ')')
                res += "o", i++;
            else if (command[i] == '(')
            {
                flag = 1;
                continue;
            }
            else if (command[i] == ')')
            {
                flag = 0;
                continue;
            }
            else
                res += command[i];
        return res;
    }
};