class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> counts(101, 0);
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < k - 1; ++i) {
            counts[nums[i] + 50]++;
        }
        
        for (int i = k - 1; i < n; ++i) {
            counts[nums[i] + 50]++;
            
            int cum = 0;
            int index = 0;
            while (cum + counts[index] < x) {
                cum += counts[index];
                index++;
            }
            int current = min(0, index - 50);
            res.push_back(current);
            counts[nums[i - k + 1] + 50]--;
        }
        return res;
    }
};