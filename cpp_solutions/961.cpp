class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> count(10001, false);
        for (auto& num : nums) {
            if (count[num]) return num;
            count[num] = true;
        }
        return -1;
    }
};

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 2; i < n; ++i) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i - 2]) return nums[i];
        }
        return nums[0];
    }
};
