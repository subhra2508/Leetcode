class Solution {
public:
    char findTheDifference(string s, string t) {
        int x = 0,i;
          for(i=0;i<s.size();i++){
              x^=s[i];
              x^=t[i];
          }
        x^=t[i];
        return char(x);
    }
};