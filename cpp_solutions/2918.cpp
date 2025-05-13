class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        int cnt1 = 0;
        long long sum2 = 0;
        int cnt2 = 0;
        for (auto& num : nums1) {
            sum1 += num;
            if (num == 0) cnt1++;
        }
        for (auto& num : nums2) {
            sum2 += num;
            if (num == 0) cnt2++;
        }
        if (cnt1 == 0 && sum1 < sum2 + cnt2) return -1;
        if (cnt2 == 0 && sum2 < sum1 + cnt1) return -1;
        return max(sum1 + cnt1, sum2 + cnt2);
    }
};

