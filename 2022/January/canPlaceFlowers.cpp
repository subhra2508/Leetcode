class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0,count = 0;
        int m = flowerbed.size();
        while(i<m-1){
            if(!flowerbed[i] && !flowerbed[i+1]){
                count++;
                i+=2;
            }
            else if(flowerbed[i]==1){
                i+=2;
            }
           else if(flowerbed[i+1]==1){
                i+=3;
            }
            
        }
        if(i<m && flowerbed[i]==0){
            count++;
        }
        return count >=n;
    }
};