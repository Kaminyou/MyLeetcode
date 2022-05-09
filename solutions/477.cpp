class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnts(32, 0);
        for (auto num : nums) {
            int index = 0;
            while (num) {
                cnts[index++] += (num & 0x1);
                num >>= 1;
            }
        }
        int res = 0;
        for (auto cnt : cnts) {
            res += (cnt * (n - cnt));
        }
        return res;
    }
};