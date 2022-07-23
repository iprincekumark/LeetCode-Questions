class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // to keep the total score
        for(char i:s) {
            if(i=='(') {
                st.push(0);
            }
            else {
                int A = st.top(), val=0;
                st.pop();
                if(A>0) 
                    val = 2*A;
                else
                    val = 1;
                st.top() += val;
            }
        }
        return st.top();
    }
};