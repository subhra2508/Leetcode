
test cases :
3 , 1 , 5

1 , 4 , 2 , 5

3 , 4 , 2 , 5


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0 ;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                if(count == 1){
                    return false;
                }
                if(i-2 < 0 || nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }
                else{
                    nums[i]=nums[i-1];
                }
                count = 1;
            }
        }
        return true;
    }
};