class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> groups(n, -1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] < a) groups[i] = 0;
            if (nums[i] >= a && nums[i] <= b) groups[i] = 1;
            if (nums[i] > b) groups[i] = 2;
        }
        long long res = 0;
        long long one = 0;
        long long two = 0;
        for (int i = 0; i < n; ++i) {
            if (groups[i] == 0) {
                res += (one + two);
            }
            if (groups[i] == 1) {
                res += two;
                one++;
            }
            if (groups[i] == 2) {
                two++;
            }
        }
        long long mod = 1e9 + 7;
        return res % mod;
    }
};

