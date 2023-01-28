class SummaryRanges {
public:
    map<int, int> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int left = val;
        int right = val;
        auto hi = intervals.upper_bound(val); // >
        auto lo = intervals.lower_bound(val); // >=
        // if lower bound cover val => return
        if (lo != intervals.end() && lo->first == val) return;
        // move back
        if (lo != intervals.begin()) {
            lo--;
            // if the previous one's end >= val: return
            if (lo != intervals.end() && lo->second >= val) return;
        }
        
        // merge left
        if (lo != intervals.end() && lo->second == val - 1) {
            left = min(left, lo->first);
            intervals.erase(lo);
        }
        // merge right
        if (hi != intervals.end() && hi->first == val + 1) {
            right = max(right, hi->second);
            intervals.erase(hi);
        }
        intervals[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto [l, r] : intervals) {
            res.push_back({l, r});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

 // v2
 class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        int left = value;
        int right = value;
        auto it = mp.upper_bound(value);  // >
        auto itL = it;
        // deal with the left bound
        if (it != mp.begin()) {
            itL--;
            if (itL->second >= value - 1) {
                if (itL->second >= right) return;
                left = itL->first;
                mp.erase(itL);
            }
        }
        // deal with the right bound
        if (it != mp.end()) {
            if (it->first <= value + 1) {
                right = it->second;
                mp.erase(it);
            }

        }
        mp[left] = right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto& [l, r] : mp) {
            res.push_back({l ,r});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */