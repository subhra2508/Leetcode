class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n);
        vector<int>prefix(n);
        vector<int>postfix(n);
        prefix[0]=1;
        postfix[n-1]=1;
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            postfix[i]=postfix[i+1]*nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++){
            v[i]=prefix[i]*postfix[i];
        }
        return v;
    }
};