class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target)){
            auto itr=find(nums.begin(),nums.end(),target);
            if(itr!=nums.end()){
                return itr-nums.begin();
            }
        }
        else{
            if(target<nums[0]){
                return 0;
            }
            else if(target>nums[nums.size()-1]){
                return nums.size();
            }
            else{
                for(int i=0;i<nums.size()-1;i++){
                    if(target>nums[i]&&target<nums[i+1]){
                        return i+1;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return INT_MIN;
    }
};