class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= i) {
                diff[0] += 1;
                diff[(i - (nums[i] - 1)) % n] -= 1;
                diff[(i + 1) % n] += 1;
            }
            else {
                diff[0] += 0;
                diff[(i + 1) % n] += 1;
                diff[(i + 1 + n - nums[i]) % n] -= 1;
            }
        }
        int res = 0;
        int maxScore = INT_MIN;
        int score = 0;
        for (int i = 0; i < n; ++i) {
            score += diff[i];
            if (score > maxScore) {
                maxScore = score;
                res = i;
            }
        }
        return res;
    }
};

