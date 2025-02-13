class Solution {
public:
    unordered_map<int, int> memo;
    int greatestNum(int num) {
        if (memo.count(num)) return memo[num];
        int res = -1;
        for (int i = 2; i * i <= num; ++i) {
            int a = i;
            int b = num / a;
            if (a * b == num) {
                res = max(res, a);
                res = max(res, b);
            }
        }
        return memo[num] = res;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = n - 2; i >= 0; --i) {
            int next = nums[i + 1];
            while (nums[i] > next) {
                int divide = greatestNum(nums[i]);
                if (divide == -1) return -1;
                nums[i] /= divide;
                res++;
            }
        }
        return res;
    }
};
