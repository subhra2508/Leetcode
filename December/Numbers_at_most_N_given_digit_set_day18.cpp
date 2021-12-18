class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
       string upperLimit = to_string(n);
        int digit = upperLimit.size();
        int digitsize = digits.size();
        int result = 0;
        
        for(int i=1;i<digit;i++){
            result+=pow(digitsize,i);
        }
        
        for(int i=0;i<digit;i++){
            //if the number start with the same number
            bool startingSameNum = false;
            for(string &d:digits){
                
                //this is like we 4 digits , 3 digits done by first for loop
                //the last digits numbers we have to check so the power is digit-i-1 is
                //like 5xxx,52xx,523x 
                //check out the video
                //https://www.youtube.com/watch?v=nqCM8opotjU
                if(d[0]<upperLimit[i])result+=pow(digitsize,digit-i-1);
                
                // this is the last one that is build using the digits
                else if(d[0]==upperLimit[i])startingSameNum = true;
            }
            if(!startingSameNum)return result;
        }
        return result+1;
    }
};