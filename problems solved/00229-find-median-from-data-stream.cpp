class MedianFinder {
public:
    priority_queue <int> front;
    priority_queue <int, vector<int>, greater<int>> back;
    MedianFinder(){}    
    void addNum(int num) {
        if(!back.empty() && back.top() < num){
            back.push(num);
            num = back.top(); back.pop();
        }
        front.push(num);
        if(front.size() - back.size() > 1){
            back.push(front.top()); front.pop();
        }
    }
    double findMedian() {
        if(front.size()>back.size()) return front.top();
        return ((double)front.top() + back.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */