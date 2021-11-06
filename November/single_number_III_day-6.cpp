








class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x_or = nums[0];
        vector<int>v;
        long long int x=0,y=0,n=nums.size();
        for(int i=1;i<nums.size();i++){
            x_or^=nums[i];
        }
        long long int lowestbit = x_or & (- x_or);
        for(int i=0;i<n;i++){
            if((nums[i]&lowestbit) == 0){
                x^=nums[i];
            }
            else {
                y^=nums[i];
            }
        }
        v.push_back((int)x);
        v.push_back((int)y);
        return v;
        
    }
   
    
};

//time complexity o(n)
//space complexity o(1)