class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long> counts;
        int n = nums.size();
        int index = 0;
        while (index < n) {
            if (nums[index] == 0) {
                int start = index;
                while (index + 1< n && nums[index + 1] == 0) index++;
                counts.push_back(index - start + 1);
            }
            index++;
        }
        long long res = 0;
        for (auto& num : counts) {
            res += (num + 1) * num / 2;
        }
        return res;
    }
};