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

// V2
// class MyCalendar {
// public:
//     map<int, int> mp;
//     MyCalendar() {
        
//     }
    
//     bool book(int start, int end) {
//         auto hi = mp.upper_bound(start);
//         auto lo = mp.lower_bound(start);
//         if (lo != mp.end() && lo->first == start) return false;
        
//         if (lo != mp.begin()) {
//             --lo;
//         }
//         bool eraseHi = false;
//         bool eraseLo = false;
//         if (hi != mp.end()) {
//             if (end > hi->first) return false;
//             if (end == hi->first) {
//                 end = max(end, hi->second);
//                 eraseHi = true;
//             }
//         }
//         if (lo != hi) {
//             if (start < lo->second) return false;
//             if (start == lo->second) {
//                 start = min(start, lo->first);
//                 eraseLo = true;
//             }
//         }
//         if (eraseHi) mp.erase(hi);
//         if (eraseLo) mp.erase(lo);
//         mp[start] = end;
//         return true;
//     }
// };

// /**
//  * Your MyCalendar object will be instantiated and called as such:
//  * MyCalendar* obj = new MyCalendar();
//  * bool param_1 = obj->book(start,end);
//  */