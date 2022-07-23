class Solution {
public:/*
    bool isValid(string s) {
        stack<int> st;
        for(auto i:s) {
            if(i == '(' || i == '{' || i == '[')
                st.push(i);
            else {
                if(st.empty() || (s[i] == '(' && st.top() == ')') || (s[i] == '{' && st.top() == '}') || (s[i] == '[' && st.top() == ']'))
                   return false;
                st.pop();
            }
        }
        return st.empty();
    }

    */
    bool isValid(string s) {
        stack<char> st;  
        for(auto i:s)  
        {
            if(i=='(' or i=='{' or i=='[') st.push(i); 
            else  {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or(st.top()=='[' and i!=']')) 
                    return false;
                st.pop();  
            }
        }
        return st.empty();  
    }
};