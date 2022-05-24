class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        int result = 0;
        stk.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                stk.pop();
                if(!stk.empty()){
                    result = max(result,i-stk.top());
                }
                else{
                    stk.push(i);
                }
            }
        }
        return result;
    }
};