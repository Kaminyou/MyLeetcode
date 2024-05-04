class RandomizedCollection {
public:
    vector<int> nums;
    int index = 0;
    unordered_map<int, unordered_set<int>> val2idx;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool res = val2idx[val].size() == 0;
        val2idx[val].insert(index);
        nums.push_back(val);
        index++;
        return res;
    }
    
    bool remove(int val) {
        bool res = val2idx[val].size() > 0;
        if (!res) return res;
        auto removeIdxIt = val2idx[val].begin();
        int removeIdx = *removeIdxIt;
        val2idx[val].erase(removeIdxIt);
        
        index--;
        if (removeIdx == index) {
            nums.pop_back();
            return res;
        }
        int exchangeIdx = index;
        int exchangeVal = nums[index];
        
        swap(nums[removeIdx], nums[exchangeIdx]);
        val2idx[exchangeVal].erase(exchangeIdx);
        val2idx[exchangeVal].insert(removeIdx);
        nums.pop_back();
        return res;
    }
    int getRandom() {
        int n = nums.size();
        int rnd = rand() % n;
        return nums[rnd];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */