class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> dq1; // max
        deque<int> dq2; // min
        long long res = 0;
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; ++right) {
            while (!dq1.empty() && nums[dq1.back()] < nums[right]) dq1.pop_back();
            dq1.push_back(right);
            while (!dq2.empty() && nums[dq2.back()] > nums[right]) dq2.pop_back();
            dq2.push_back(right);

            while (nums[dq1.front()] - nums[dq2.front()] > 2) {
                if (dq1.front() <= left) dq1.pop_front();
                if (dq2.front() <= left) dq2.pop_front();
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
