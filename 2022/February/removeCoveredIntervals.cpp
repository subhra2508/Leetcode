class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 1;
        sort(intervals.begin(),intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>first && intervals[i][1] > second){
                count++;
            }
            if(intervals[i][1] > second){
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        return count;
    }
};