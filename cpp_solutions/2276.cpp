class CountIntervals {
public:
    // use map to store interval [start, end)
    map<int, int> mp;
    int length;
    pair<int, int> find(int left, int right) {
        // find segment.first > left and segment.first > right
        auto l = mp.upper_bound(left);
        auto r = mp.upper_bound(right);
        // move back first segment and check if its end < left
        // if yes, move forward first segment
        if (l != mp.begin() && (--l)->second < left) ++l;
        
        // if now l == r, it does not overlap with others
        if (l == r) {
            // update the total covered length
            length += (right - left);
            return {left, right};
        }
        
        // get the min val
        int minVal = min(l->first, left);
        // get the max val by moving back the second segment
        int maxVal = max(right, (--r)->second);
        
        // update the total covered length by deleting overlapped ones
        // r++: [l, r] -> [l, r) to half-open interval
        auto it = l;
        r++; 
        while (it != r) {
            length -= (it->second - it->first);
            it++;
        }
        // update the total covered length by the new interval
        length += (maxVal - minVal);
        
        // remove overlap segment
        mp.erase(l, r);
        // return new interval
        return {minVal, maxVal};
    }
    CountIntervals() {
        length = 0;
    }
    
    void add(int left, int right) {
        // use half-open interval to simply the implementation
        right++;
        auto x = find(left, right);
        mp[x.first] = x.second;
    }
    
    int count() {
        return length;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */