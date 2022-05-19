class MedianFinder {
public:
    priority_queue<int> lowHeap;
    priority_queue<int, vector<int>, greater<int>> highHeap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        lowHeap.push(num);
        highHeap.push(lowHeap.top());
        lowHeap.pop();
        if (highHeap.size() > lowHeap.size()) {
            lowHeap.push(highHeap.top());
            highHeap.pop();
        }
    }
    
    double findMedian() {
        if (lowHeap.size() > highHeap.size()) {
            return lowHeap.top();
        }
        return ((double)lowHeap.top() + (double)highHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */