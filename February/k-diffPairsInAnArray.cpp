class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(k==0){
                if(itr->second > 1){
                    count++;
                }
            }
                else if(mp.find(itr->first+k)!=mp.end()){
                    count++;
                }
            }
        return count;
    }
};