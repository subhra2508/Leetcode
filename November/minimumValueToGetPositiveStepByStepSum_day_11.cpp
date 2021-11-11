class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_ele=0,sum = 0;
        for(auto num : nums){
            sum+=num;
            min_ele = min(min_ele,sum);
        }
        return 1-min_ele;
    }
};