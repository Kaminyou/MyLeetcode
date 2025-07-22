class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        unordered_map<int, int> counter;
        int duplicates = 0;
        int left = 0;
        int res = 0;
        for (int right = 0; right < n; ++right) {
            if (counter[nums[right]] == 1) duplicates += 1;
            counter[nums[right]]++;
            while (duplicates != 0) {
                if (counter[nums[left]] == 2) duplicates -= 1;
                counter[nums[left]]--;
                left++;
            }
            res = max(res, prefixSum[right + 1] - prefixSum[left]);
        }
        return res;
    }
};

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int curr = 0;
        int n = nums.size();
        bool st[10001];
        for (int i = 0; i <= 10000; ++i) st[i] = false;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            while (st[nums[right]]) {
                st[nums[left]] = false;
                curr -= nums[left];
                left++;
            }
            st[nums[right]] = true;
            curr += nums[right];
            res = max(res, curr);
        }
        return res;
    }
};
