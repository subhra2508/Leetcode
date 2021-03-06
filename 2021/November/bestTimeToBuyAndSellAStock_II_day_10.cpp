class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_cost = 0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                max_cost +=prices[i]-prices[i-1];
            }
        }
        return max_cost;
    }
};



 