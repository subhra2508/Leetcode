
//The idea here is pretty tricky to guess...

//What we do is we initialize a window of size k...
//Now, since we can select either from the start or from the end, we only have access to either the first k items or last k items, and hence we are trying to limit our access using this window...
//So, we include all the elements from start in our window, till its full...
//The sum of elements at each instance in our window will be kept track of using another variable that will store our result.
//Now, we remove the last element from our window, and add the last unvisited element of our cardPoints array... Similarly we keep on removing 1 element from our window and start adding the last unvisited element of our cardPoints array...
//We keep doing this until we reach the start of our array, in this way we have covered all our possible picks...





class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curr = 0;
        int res = 0;
        for(int i = 0; i < k ; i++){
            res+=cardPoints[i];
        }
        curr = res;
        for(int i=k-1;i>=0;i--){
          curr -= cardPoints[i];
            curr+=cardPoints[n-k+i];
            res = max(curr,res);
        }
        return res;
        
    }
};