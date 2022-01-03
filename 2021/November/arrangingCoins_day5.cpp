//You have n coins and you want to build a staircase with these coins. 
//The staircase consists of k rows where the ith row has exactly i coins. 
//The last row of the staircase may be incomplete.

//Given the integer n, return the number of complete rows of the staircase you will build.

//Input: n = 5
//Output: 2
//Explanation: Because the 3rd row is incomplete, we return 2.




class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0,right = n;
        long k,curr;
        while(left<=right){
            k = left+(right-left)/2;
            curr = k*(k+1)/2;
            if(n==curr)return k;
            if(n<curr){
                right = k-1;
            }
            else{
                left = k+1;
            }
        }
        return right;
        
    }
};