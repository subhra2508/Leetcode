
//Approach:

//The main concept is we can use ladder for any height. So suppose you are moving from the first building. Use bricks first upto as much you can go. When bricks are finished if height is more than maximum bricks used in a step use ladder or take the bricks from the biggest step and replace that with ladder. Now continue till ladders are finished and bricks are not sufficient.

//So we can take a priority queue for storing the bricks used in each step and so that we can take out the maximum bricks used till a building. We add brick count to the queue whenever we use bricks and take out the max brick whenever we use ladder.

//To reduce complexity of code we can provide brick at each step and if the brick count becomes negetive then add a ladder at the biggest step (In this way we no need to compare the current step with the max brick used before, priority queue will handle the situation).

//Similarly give ladder to a step when needed. If ladder count becomes negetive then we cant go to next building and return the index of present building.

//Note: We run the loop upto the building before the last building.If the loop os passed at the last step then i will increament and will point to the last building.




class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>max_bricks;
        int i = 0;
        int diff = 0;
        for(i=0;i<heights.size()-1;i++){
             diff = heights[i+1]-heights[i];
            if(diff <= 0){
                continue;
            }
            bricks -= diff;
              max_bricks.push(diff);
            if(bricks < 0){
                bricks += max_bricks.top();
                max_bricks.pop();
                ladders -- ;
            }
            if(ladders < 0) break;
        }
        return i;
    }
};