class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = *min_element(divisors.begin(), divisors.end());
        int maxScore = 0;
        for (auto divisor : divisors) {
            int cnt = 0;
            for (auto& num : nums) {
                if (num % divisor == 0) cnt++;
            }
            if (cnt > maxScore) {
                maxScore = cnt;
                ans = divisor;
            }
            if (cnt >= maxScore) ans = min(ans, divisor);
        }
        return ans;
    }
};