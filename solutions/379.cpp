class PhoneDirectory {
public:
    queue<int> q;
    vector<bool> used;
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; i++) q.push(i);
        used.resize(maxNumbers, false);
    }
    
    int get() {
        if (q.empty()) return -1;
        int number = q.front();
        q.pop();
        used[number] = true;
        return number;
    }
    
    bool check(int number) {
        return !used[number];
    }
    
    void release(int number) {
        if (used[number] == false) return;
        used[number] = false;
        q.push(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */