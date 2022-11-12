class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int index1,index2;
        unordered_map<int,int>mp;
        for(int i=0;i<numbers.size();i++){
            index1=i;
            int val = target-numbers[i];
            // cout<<val<<endl;
            if(mp.find(val)!=mp.end()){
                index2=mp[val];
                // cout<<index2<<endl;
                break;
            }
            else{
                mp.insert({numbers[i],i});
            }
        }
        v.push_back(index2+1);
        v.push_back(index1+1);
        return v;
    }
};