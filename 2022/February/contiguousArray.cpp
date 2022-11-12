class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int longestSubarray = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum += nums[i] == 0 ? -1:1;
            if(sum == 0){
                if(longestSubarray < i+1){
                    longestSubarray = i+1;
                }
            }
            else if(mp.find(sum)!=mp.end()){
                if(longestSubarray < i-mp[sum]){
                    longestSubarray = i-mp[sum];
                }
            }
            else{
                mp[sum] = i;
            }
        }
        return longestSubarray;
    }
};