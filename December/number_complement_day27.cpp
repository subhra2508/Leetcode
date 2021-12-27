class Solution {
public:
    //https://www.youtube.com/watch?v=LA1BnKiarEQ
    int findComplement(int num) {
        int result = 0;
        int i = 0;//for the bit number we are processing
        
        while(num){
            if((num&1)==0){
                //left shift it to the bit number and add it to the result
                result += 1<<i;  
            }
             i++;
            num>>=1;//right shift the bit so that it gone now ,we are
            //dealing with other bits that are there
           
        }
         return result;
        
    }
};