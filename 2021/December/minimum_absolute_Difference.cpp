class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int min_diff = INT_MAX;
        vector<vector<int>>output{};
        
        for(int i=1;i<arr.size();i++){
            int diff = arr[i]-arr[i-1];
            
            if(diff <min_diff){
                min_diff = diff;
                output.clear();
            }
            if(diff == min_diff){
                output.push_back(vector<int>{arr[i-1],arr[i]});
            }
        }
        return output;
        
    }
};