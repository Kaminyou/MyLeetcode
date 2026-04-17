class Solution {
public:
    int rev(int num) {
        int res = 0;
        while (num) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;

    }
    int minMirrorPairDistance(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, int> num2idx;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            int revNum = rev(nums[i]);
            if (num2idx.count(revNum)) {
                res = min(res, num2idx[revNum] - i);
            }
            num2idx[nums[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};

