class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int first;
    int last;
    vector <int> v;
    int cnt;
    MyCircularQueue(int k) {
        first = last = 0;
        v = vector <int>(k);
        cnt = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        v[last] = value;
        //cout << "Insert " << value << " " << last << endl;
        last = (last + 1) % (int)v.size();
        //cout << last << endl;
        cnt++;
        return true;
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        //cout << "Delete " << first << endl;
        first = (first + 1) %(int)v.size();
        cnt--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return v[first];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        //cout << "Rear" << endl;
        if(isEmpty()) {
            //cout << "Empty!! REar" << endl;
            return -1;
        }
        int temp = ((last - 1) + v.size()) % (int)v.size();
        //cout << temp << endl;
        return v[temp];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        //cout << cnt << " " << v.size() << " " << "Empty" << endl;
        return cnt == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        //cout << cnt << " " << v.size() << " " << "Full" << endl;
        return cnt == v.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */