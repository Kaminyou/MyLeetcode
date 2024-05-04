class MovingAverage {
private:
    int n;
    int curr;
    queue<int> q;
    double sum;
public:
    MovingAverage(int size) {
        n = size;
        curr = 0;
        sum = 0.0;
    }
    
    double next(int val) {
        q.push(val);
        curr++;
        sum += val;
        if (q.size() > n) {
            curr--;
            sum -= q.front();
            q.pop();
        }
        return sum / curr;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */