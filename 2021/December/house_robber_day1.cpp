class Solution {
public:
    int rob(vector<int>& nums) {
        int incl = nums[0];
        int excl = 0;
        int excl_new;
        for(int i=1;i<nums.size();i++){
            excl_new = max(incl,excl);
	    incl = excl+nums[i];
	    excl = excl_new;
        }
        return max(incl,excl);
    }
};

