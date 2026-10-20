class Solution {
public:
    bool isSortable(vector<int>& nums, int divisor) {
        int y = nums.size() / divisor;
        int globalMax = -1;
        for (int i = 0; i < y; ++i) {
            int start = i * divisor;
            int end = (i + 1) * divisor;
            bool flag = false;
            if (nums[start] < nums[end - 1]) {
                flag = true;
            }

            int localMax = globalMax;
            for (int j = start; j < end; ++j) {
                if (j != start) {
                    if (nums[j - 1] > nums[j]) {
                        if (flag) return false;
                        flag = true;
                    }
                }
                if (nums[j] < globalMax) return false;
                localMax = max(localMax, nums[j]);
            }
            globalMax = localMax;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divisors;
        for (int x = 1; x * x <= n; ++x) {
            if (n % x == 0) {
                int y = n / x;
                divisors.push_back(x);
                if (x != y) divisors.push_back(y);
            }
        }
        int res = 0;
        for (auto& divisor : divisors) {
            if (isSortable(nums, divisor)) {
                res += divisor;
            }
        }
        return res;
    }
};

