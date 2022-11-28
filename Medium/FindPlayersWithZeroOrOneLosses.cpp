class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>Lost_mp;
        map<int,int>win_mp;
        vector<int>winner;
        for(int i=0;i<matches.size();i++){
            vector<int>temp = matches[i];
            Lost_mp[temp[1]]++;
        }
        for(int i=0;i<matches.size();i++){
            vector<int>temp = matches[i];
            
            if(Lost_mp[temp[0]] == 0){
                win_mp[temp[0]]++;
            }
        }
        vector<int>lostOne;
        for(auto itr=Lost_mp.begin();itr!=Lost_mp.end();itr++){
            if(itr->second == 1){
                lostOne.push_back(itr->first);
            }
        }
        for(auto itr=win_mp.begin();itr!=win_mp.end();itr++){
            if(itr->second >= 1){
                winner.push_back(itr->first);
            }
        }
        vector<vector<int>>sol;
        sol.push_back(winner);
        sol.push_back(lostOne);
        return sol;
    }
};