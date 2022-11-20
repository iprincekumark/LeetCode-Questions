class Solution {
public:
    void operate(stack<int>& st, char sign, int val){
        if(sign == '+') st.push(val);
        if(sign == '-') st.push(-val);
        if(sign == '*') st.top() *= val;
        if(sign == '/') st.top() /= val;
    }
    int getVal(stack<int> st){
        int ret = 0;
        while(!st.empty()){
            ret += st.top();
            st.pop();
        }
        return ret;
    }
    int idx;
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char op = '+';
        int n = s.size();
        // cout << idx << endl;
        while(idx < n){
            if(s[idx] >= '0' && s[idx] <= '9'){
                num *= 10;
                num += (s[idx] - '0');
            }else if(s[idx] == '+' || s[idx] == '-' || s[idx] == '/' || s[idx] == '*'){
                operate(st, op, num);
                num = 0;
                op = s[idx];
            }else if(s[idx] == '('){
                idx++;
                num = calculate(s);
                // cout << idx << " -- " << num << endl;
                // idx--;
            }else if(s[idx] == ')'){
                // cout << getVal(st) << " -- - " << idx << endl;
                operate(st, op, num);
                return getVal(st);
            }
            // if(idx == 9){
            //     // cout << getVal(st) << endl;
            // }
            idx++;
        }
        operate(st, op, num);
        return getVal(st);
    }
};