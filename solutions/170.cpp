class TwoSum {
public:
    unordered_map<long long, int> mp;
    TwoSum() {
        
    }
    
    void add(int number) {
        mp[number]++;
    }
    
    bool find(int value) {
        for (auto [num, count] : mp) {
            if (mp.find(value - num) != mp.end()) {
                if (value - num != num) return true;
                else if (count >= 2) return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */