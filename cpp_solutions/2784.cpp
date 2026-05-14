class Solution {
public:
    int hash[201];
    bool isGood(vector<int>& nums) {
        for (int i = 0; i <= 200; ++i) hash[i] = 0;
        int maxVal = 0;
        for (auto& num : nums) {
            maxVal = max(maxVal, num);
            hash[num] += 1;
        }
        if (nums.size() != maxVal + 1) return false;
        for (int i = 1; i < maxVal; ++i) {
            if (hash[i] != 1) return false;
        }
        return hash[maxVal] == 2;
    }
};
