class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        int min_price = prices[0];
        int cost = 0;
        int maxCost = 0;
        for(int i=0;i<n;i++){
            min_price = min(min_price,prices[i]);
            cost = prices[i]-min_price;
            maxCost = max(maxCost,cost);
        }
        return maxCost;
    }
};