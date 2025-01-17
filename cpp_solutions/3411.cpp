class Solution {
public:
    bool isValid(vector<int>& counts) {
        for (int i = 2; i < 11; ++i) {
            if (counts[i] > 1) return false;
        }
        if (counts[2] > 0) {
            if (counts[4] > 0) return false;
            if (counts[6] > 0) return false;
            if (counts[8] > 0) return false;
            if (counts[10] > 0) return false;
        }
        if (counts[3] > 0) {
            if (counts[6] > 0) return false;
            if (counts[9] > 0) return false;
        }
        if (counts[4] > 0) {
            if (counts[6] > 0) return false;
            if (counts[8] > 0) return false;
            if (counts[10] > 0) return false;
        }
        if (counts[5] > 0) {
            if (counts[10] > 0) return false;
        }
        if (counts[6] > 0) {
            if (counts[8] > 0) return false;
            if (counts[9] > 0) return false;
            if (counts[10] > 0) return false;
        }
        if (counts[8] > 0) {
            if (counts[10] > 0) return false;
        }
        return true;
    }
    int maxLength(vector<int>& nums) {
        int left = 0;
        vector<int> counts(11, 0);
        int n = nums.size();
        if (n <= 2) return n;
        int res = 2;
        for (int right = 0; right < n; ++right) {
            counts[nums[right]]++;
            while (!isValid(counts)) {
                counts[nums[left++]]--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

