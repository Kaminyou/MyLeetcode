class RangeModule {
private:
    // mp store <begin, end> pair
    map<int, int> mp;
    pair<int, int> find(int left, int right) {
        // find segment.first > left and segment.first > right
        auto l = mp.upper_bound(left);
        auto r = mp.upper_bound(right);
        // move back first segment and check if its end < left
        // if yes, move forward first segment
        if (l != mp.begin() && (--l)->second < left) ++l;
        // if now l == r, it does not overlap with others
        if (l == r) return {left, right};
        
        // get the min val
        int minVal = min(l->first, left);
        // get the max val by moving back the second segment
        int maxVal = max(right, (--r)->second);
        // remove overlap segment
        mp.erase(l, ++r);
        // return new interval
        return {minVal, maxVal};
    }
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto x = find(left, right);
        mp[x.first] = x.second;
    }
    
    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);
        return (it != mp.begin()) && ((--it)->second >= right);
    }
    
    void removeRange(int left, int right) {
        auto x = find(left, right);
        if (left > x.first) mp[x.first] = left;
        if (x.second > right) mp[right] = x.second;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */