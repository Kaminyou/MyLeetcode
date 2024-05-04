class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> mp;
        vector<int> res;
        for (auto& num : changed) mp[num]++;
        for (auto& element : mp) {
            int current = element.first;
            int doubleCurrent = current * 2;
            int count = element.second;
            if (current == 0) {
                if (count & 1) return {};
                count /= 2;
            }
            if (count > 0) {
                if (mp[doubleCurrent] < count) return {};
                for (int i = 0; i < count; ++i) res.push_back(current);
                mp[doubleCurrent] -= count;
                mp[current] -= count;
            }
        }
        return res;
    }
};