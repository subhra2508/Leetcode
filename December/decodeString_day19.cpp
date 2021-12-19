class Solution {
public:
    string decodeString(string s) {
        stack<char>stk;
        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                stk.push(s[i]);
            }
            else{
                string ss = "";
                while(!stk.empty() && stk.top()!='['){
                    ss=stk.top()+ss;
                    stk.pop();
                }
                stk.pop();
                string number = "";
                while(!stk.empty() && isdigit(stk.top())){
                    number = stk.top()+number;
                    stk.pop();
                }
                
                
                int k = stoi(number);
                
                 while(k--){
                     for(int j=0;j<ss.length();j++){
                         stk.push(ss[j]);
                     }
                 }
                
            }
        }
    string ans = "";
        while(!stk.empty()){
            ans=stk.top()+ans;
            stk.pop();
        }
        return ans;
    }
};