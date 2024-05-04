class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        vector<pair<int, int>> queriesWithIdx;
        for (int i = 0; i < n; ++i) {
            queriesWithIdx.push_back({queries[i], i});
        }
        
        sort(nums.begin(), nums.end());
        sort(queriesWithIdx.begin(), queriesWithIdx.end());
        
        int m = nums.size();
        long long left = 0;
        long long right = 0;
        int index = 0;
        int num = queriesWithIdx[0].first;
        for (int i = 0; i < m; ++i) {
            if (nums[i] <= num) {
                left += num - nums[i];
                index = i + 1;
            }
            else {
                right += nums[i] - num;
            }
        }
        
        vector<long long> res(n, 0);
        res[queriesWithIdx[0].second] = left + right;
        
        for (int i = 1; i < n; ++i) {
            int prev = queriesWithIdx[i - 1].first;
            int current = queriesWithIdx[i].first;
            int prevIdx = index;
            while (index < m && nums[index] <= current) {
                right -= nums[index] - prev;
                left += current - nums[index];
                index++;
            }
            int currentIdx = index;
            left += (long long)prevIdx * (long long)(current - prev);
            right -= (long long)(m - currentIdx) * (long long)(current - prev);
            res[queriesWithIdx[i].second] = left + right;
        }
        return res;
    }
};

