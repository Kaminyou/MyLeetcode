class RandomizedSet {
public:
    unordered_map<int, int> mp; // val -> index
    vector<int> v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        int n = v.size();
        v.push_back(val);
        mp[val] = n;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int index = mp[val];
        int n = v.size() - 1;
        swap(v[index], v[n]);
        mp[v[index]] = index;
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int rnd = rand() % n;
        return v[rnd];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

 class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> v;
    int index = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val)) return false;
        mp[val] = index;
        index++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!mp.count(val)) return false;
        int removeIdx = mp[val];
        index--;
        int exchangeVal = v[index];
        mp[exchangeVal] = removeIdx;
        swap(v[removeIdx], v[index]);
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rndIdx = rand() % index;
        return v[rndIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */