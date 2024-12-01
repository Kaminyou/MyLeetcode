class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto& num : arr) {
            mp[num]++;
        }
        for (auto& num : arr) {
            if (mp[num * 2] >= 1) {
                if (num == 0 && mp[num] >= 2) return true;
                else if (num == 0 && mp[num] < 2) continue;
                else return true;
            }
        }
        return false;
    }
};
