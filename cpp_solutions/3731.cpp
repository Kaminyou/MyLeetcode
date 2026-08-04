class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> exists(101, false);
        int minV = INT_MAX;
        int maxV = INT_MIN;
        for (auto& num : nums) {
            exists[num] = true;
            minV = min(minV, num);
            maxV = max(maxV, num);
        }
        vector<int> res;
        for (int num = minV; num <= maxV; ++num) {
            if (!exists[num]) {
                res.push_back(num);
            }
        }
        return res;
    }
};
