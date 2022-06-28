class MyCalendarTwo {
public:
    map<int, int> mp; // point: val
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int state = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            state += it->second;
            if (state == 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */