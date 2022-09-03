class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<long long> sumSt;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            long long current = nums[i] + nums[i + 1];
            if (sumSt.find(current) != sumSt.end()) return true;
            sumSt.insert(current);
        }
        return false;
        
    }
};