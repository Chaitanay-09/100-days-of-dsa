#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxHeap; // left side
    priority_queue<int, vector<int>, greater<int>> minHeap; // right side

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};