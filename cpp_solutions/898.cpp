class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> current;
        unordered_set<int> res;
        unordered_set<int> next;
        
        current.insert(0);
        for (auto& num : arr) {
            next.clear();
            next.insert(num);
            for (auto& y : current) next.insert(y | num);
            for (auto& x : next) res.insert(x);
            current.swap(next);
        }
        return res.size();
    }
};
