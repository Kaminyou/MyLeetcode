class MyCalendar {
private:
    map<int, int> mp; // end, start
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto element = mp.upper_bound(start);
        if (element != mp.end() && element->second < end) return false;
        mp[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */