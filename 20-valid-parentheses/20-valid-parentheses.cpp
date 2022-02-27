class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
        for(auto x:s)
        {
            if(x=='('|| x=='{'||x=='[')
                st.push(x);
            else if(x==')'|| x=='}'||x==']')
            {
                if(st.empty())
                    return false;              
                if((x==')' and st.top()=='(') || (x=='}' and st.top()=='{') ||(x==']' and st.top()=='['))
                    st.pop();
                else
                    return false;               
            }
        }
        if(st.empty())
            return true;
        return false; 
    }
};