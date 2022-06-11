class HitCounter {
public:
    queue<int> q;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        q.push(timestamp);
        while (!q.empty() && timestamp - q.front() >= 300) q.pop();
    }
    
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) q.pop();
        return q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */