class Solution {
public:
    string reverseVowels(string s) {
        string str = "";
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'|| s[i] == 'A' || s[i]=='e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] =='u' || s[i] == 'U'){
                str+=s[i];
            }
        }
        reverse(str.begin(),str.end());
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'|| s[i] == 'A' || s[i]=='e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] =='u' || s[i] == 'U'){

                s[i]= str[count];
                count ++;
            }
        }
        return s;
    }
};