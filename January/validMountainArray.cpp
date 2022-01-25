class Solution {
public:
    int findThePivotPoint(vector<int>v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i] > v[i+1]){
                return i;
            }
        }
        return v.size()-1;
    }
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        int pointIndex= findThePivotPoint(arr);
        if(pointIndex==n-1 || pointIndex == 0)return false;
        
        for(int i=0;i<pointIndex;i++){
            if(arr[i]>=arr[i+1]){
                return false;
            }
        }
        for(int i=pointIndex;i<n-1;i++){
            if(arr[i]<=arr[i+1]) return false;
        }
        return true;
    }
};