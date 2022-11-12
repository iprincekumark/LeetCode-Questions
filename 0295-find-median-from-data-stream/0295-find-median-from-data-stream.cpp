typedef double lli;
class MedianFinder {
    priority_queue <int> left;
    priority_queue <int, vector <int>, greater<int>> right;
public:
    /** initialize your data structure here. */
    
    void addNum(int num) {
        if(left.empty() || num<left.top()){
        left.push(num);
    }else right.push(num);
        
        if(left.size()<right.size()){
        lli temp = right.top();
        right.pop();
        left.push(temp);
    }
    if(left.size()-right.size()>1){
        lli temp = left.top();
        left.pop();
        right.push(temp);
    }
    }
    
    double findMedian() {
            return left.size()>right.size()?left.top():(left.top()+right.top())*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */