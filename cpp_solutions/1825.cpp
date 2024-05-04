class MKAverage {
public:
    long long sum;
    int M;
    int K;
    int size;
    queue<int> Q;
    multiset<int> left, middle, right;
    MKAverage(int m, int k) {
        sum = 0;
        M = m;
        K = k;
        size = m - k * 2;
    }
    void remove(int num) {
        if (num <= *(left.rbegin())) {
            left.erase(left.find(num));
        }
        else if (num <= *(middle.rbegin())) {
            middle.erase(middle.find(num));
            sum -= num;
        }
        else {
            right.erase(right.find(num));
        }
        if (left.size() < K) {
            auto it = middle.begin();
            left.insert(*it);
            sum -= *it;
            middle.erase(it);
        }
        if (middle.size() < size) {
            auto it = right.begin();
            middle.insert(*it);
            sum += *it;
            right.erase(it);
        }
    }
    void add(int num) {
        left.insert(num);
        if (left.size() > K) {
            auto it = prev(end(left));
            middle.insert(*it);
            sum += *it;
            left.erase(it);
        }
        if (middle.size() > size) {
            auto it = prev(end(middle));
            right.insert(*it);
            sum -= *it;
            middle.erase(it);
        }
    }
    void addElement(int num) {
        Q.push(num);
        if (Q.size() > M) {
            remove(Q.front());
            Q.pop();
        }
        add(num);
    }
    
    int calculateMKAverage() {
        if (Q.size() < M) return -1;
        return sum / size;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */