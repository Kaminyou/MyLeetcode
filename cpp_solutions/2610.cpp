class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& num : nums) mp[num]++;
        
        vector<vector<int>> res;
        while (!mp.empty()) {
            vector<int> sub;
            vector<int> empty;
            for (auto [num, cnt] : mp) {
                sub.push_back(num);
                mp[num]--;
                if (mp[num] == 0) empty.push_back(num);
            }
            for (auto num : empty) mp.erase(num);
            res.push_back(sub);
        }
        return res;
    }
};