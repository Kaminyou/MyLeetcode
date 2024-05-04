class MyCircularDeque {
public:
    list<int> l;
    int k;
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int value) {
        if (l.size() == k) return false;
        l.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if (l.size() == k) return false;
        l.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if (l.size() == 0) return false;
        l.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if (l.size() == 0) return false;
        l.pop_back();
        return true;
    }
    
    int getFront() {
        if (l.empty()) return -1;
        return l.front();
    }
    
    int getRear() {
        if (l.empty()) return -1;
        return l.back();
    }
    
    bool isEmpty() {
        return l.empty();
    }
    
    bool isFull() {
        return l.size() == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */