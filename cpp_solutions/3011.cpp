class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        for (int i = 0; i < n; ++i) {
            int cnt = __builtin_popcount(nums[i]);
            counts[i] = cnt;
        }
        int highest = -1;
        int tempLowest = -1;
        int tempHightest = -1;
        int currCnt = -1;
        for (int i = 0; i < n; ++i) {
            if (counts[i] == currCnt) {
                tempLowest = min(tempLowest, nums[i]);
                tempHightest = max(tempHightest, nums[i]);
            }
            else {
                if (tempLowest < highest) return false;
                highest = tempHightest;
                tempLowest = nums[i];
                tempHightest = nums[i];
                currCnt = counts[i];
            }
        }
        if (tempLowest < highest) return false;
        return true;
    }
};
