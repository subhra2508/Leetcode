class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        for(int i=0;i<nums.size();i++){
            int first = nums[i];
            bool flag = true;
            int second = nums[i];
            while(i+1 < nums.size() && nums[i]+1==nums[i+1]){
                flag = false;
                second = nums[i+1];
                i++;
            }
            if(flag==true){
                result.push_back(to_string(first));
            }
            else{
                string first_string = to_string(first);
                string second_string = to_string(second);
                string res = first_string + "->"+second_string;
                result.push_back(res);
            }
        }
        return result;
    }
};