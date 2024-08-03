class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> hash(1001, 0);
        for (auto& num : target) hash[num]++;
        for (auto& num : arr) {
            hash[num]--;
            if (hash[num] < 0) return false;
        }
        return true;
    }
};
