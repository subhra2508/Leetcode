class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxCount = INT_MIN;
        int num ;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
           
            if(maxCount < itr->second){
                maxCount = itr->second;
                num = itr->first;
            }
        }
        return num;
    }
};