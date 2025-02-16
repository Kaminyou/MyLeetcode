class Solution {
public:
    int suitable(int num) {
        vector<int> bits(32, 0);
        int index = 0;
        while (num) {
            bits[index] = num & 1;
            index++;
            num >>= 1;
        }
        // find the first zero
        int zeroIndex = -1;
        for (int i = 0; i < 32; ++i) {
            if (bits[i] == 0) {
                zeroIndex = i;
                break;
            }
        }
        bits[zeroIndex - 1] = 0;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            res += (bits[i] << i);
        }
        return res;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 2) continue;
            res[i] = suitable(nums[i]);
        }
        return res;
    }
};

