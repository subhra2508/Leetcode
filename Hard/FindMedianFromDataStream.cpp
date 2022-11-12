
//youtube tutorial => https://www.youtube.com/watch?v=1LkOrc-Le-Y
class MedianFinder {
public:
// we are assuming that the max heap contains one element more than the min heap if the number of elements is odd ->
priority_queue<int>max_heap;
priority_queue<int,vector<int>,greater<int>>min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        min_heap.push(num);
        max_heap.push(min_heap.top());
        min_heap.pop();
        if(min_heap.size()<max_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        if(min_heap.size()==max_heap.size()){
            return (min_heap.top()+max_heap.top())/2.0;
        }
        return min_heap.top();
    }
};