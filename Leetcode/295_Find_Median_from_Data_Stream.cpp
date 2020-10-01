class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        while(!min_heap.empty())
            min_heap.pop();
        while(!max_heap.empty())
            max_heap.pop();
    }
    
    void addNum(int num) {
        if(min_heap.size() == 0 && max_heap.size() == 0)
            min_heap.push(num);
        else if(min_heap.top() < num)
            min_heap.push(num);
        else
            max_heap.push(num);
        
        if(min_heap.size() > max_heap.size() + 1)
        {
            int temp=min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
        else if(max_heap.size() > min_heap.size() + 1)
        {
            int temp=max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
            return (double)(min_heap.top()+max_heap.top())/2.0;
        else if(max_heap.size() > min_heap.size())
            return max_heap.top();
        return min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */