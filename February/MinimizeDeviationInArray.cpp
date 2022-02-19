class Solution {
public:
 
    int minimumDeviation(vector<int>& nums) {
        int minVal=INT_MAX;
       int n = nums.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
          
            if(nums[i]%2==1){
                nums[i]*=2;
            }
                
            minVal = min(minVal,nums[i]);
              pq.push(nums[i]);
        }
        bool flag = true;
        int diff = INT_MAX;
        while(!pq.empty() && pq.top() %2 ==0){
            int maxEle = pq.top();
            pq.pop();
            diff = min(diff,maxEle-minVal);
            minVal = min(minVal,maxEle/2);
            pq.push(maxEle/2);   
        }
        return min(diff,pq.top()-minVal);
    }
};