class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> differences(n, 0);
        long long sum = 0;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            differences[i] = (long long)nums1[i] - (long long)nums2[i];
            if (differences[i] != 0 && k == 0) return -1;
            if (differences[i] != 0 && differences[i] % k != 0) return -1;
            if (differences[i] > 0) res += differences[i] / k;
            sum += differences[i];
        }
        if (sum != 0) return -1;
        return res;
    }
};