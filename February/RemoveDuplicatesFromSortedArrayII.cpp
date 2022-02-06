class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i=0;i<nums.size();i++){
            //if it is less than 2 or a new element is coming then
            if(index < 2 || nums[index-2] < nums[i]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};