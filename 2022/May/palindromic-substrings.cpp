1st video ->
https://www.youtube.com/watch?v=XmSOWnL6T_I
2nd video ->
https://www.youtube.com/watch?v=pp8K5C2hMr4

code :

class Solution {
public:
    int countSubstrings(string s) {
       int n = s.length();
       vector<vector<int>>dp(n+1,vector<int>(n+1,false));
        int count = n;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
		
		//checking if the end char are equal
                if(s[i]==s[j]){

		//j-i==1 for checking if the substring has 2 char that is the 2nd diagonal case and if both of the char are
		//equal then it's true ,increase the count
		//dp[i+1][j-1] , if the substring has greater than 2 length and s[i],s[j] last char are equal and in between
		//is a palindrome then the whole substring is a palindrome, here dp[i+1][j-1] checking the in between substring
		//is palindrome or not
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=true;
                        count++;
                    }
                }
            }
        }
        return count ;
    }
};