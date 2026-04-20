class MedianFinder {
private:
    
    //minHeap 6 7 8 9 10
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    // maxHeap 5 4 3 2 1
    std::priority_queue<int> maxHeap;

public:

    MedianFinder() 
    {
    }
    
    void addNum(int num) 
    {
        if(minHeap.empty() || num > minHeap.top())
        {
            std::cout << "min heap push: " << num << "\n";
            minHeap.push(num);
        }
        else
        {
            std::cout << "max heap push: " << num << "\n";
            maxHeap.push(num);
        }

        if(minHeap.size() > maxHeap.size() + 1)
        {
            int num = minHeap.top();
            minHeap.pop();
            maxHeap.push(num);
        }
        else if(maxHeap.size() > minHeap.size() + 1)
        {
            int num = maxHeap.top();
            maxHeap.pop();
            minHeap.push(num);
        }
    }
    
    double findMedian() 
    {
        if(minHeap.size() == maxHeap.size())
            return ((minHeap.top() + maxHeap.top())/2.0);
        else if(minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};


