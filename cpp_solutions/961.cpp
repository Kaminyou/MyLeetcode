class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> count(10001, false);
        for (auto& num : nums) {
            if (count[num]) return num;
            count[num] = true;
        }
        return -1;
    }
};