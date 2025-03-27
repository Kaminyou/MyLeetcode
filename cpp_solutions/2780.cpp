class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& num : nums) mp[num]++;
        int maxElement = -1;
        int maxCnt = -1;
        for (auto& [num, cnt] : mp) {
            if (cnt > maxCnt) {
                maxElement = num;
                maxCnt = cnt;
            }
        }
        int left = 0;
        int right = maxCnt;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            // left: [0, i]
            // right: [i + 1, n - 1]
            if (nums[i] == maxElement) {
                left++;
                right--;
            }
            if ((left * 2 > (i + 1)) && (right * 2 > (n - i - 1))) {
                return i;
            }
        }
        return -1;
    }
};
