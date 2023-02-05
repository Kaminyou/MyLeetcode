class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0;
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.push_back({nums2[i], nums1[i]});
        }
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        long long maxSum = 0;
        for (int i = 0; i < k; ++i) {
            pq.push(nums[i].second);
            maxSum += nums[i].second;
        }
        res = max(res, maxSum * nums[k - 1].first);
        for (int i = k; i < n; ++i) {
            pq.push(nums[i].second);
            maxSum += nums[i].second;
            int minElement = pq.top();
            pq.pop();
            maxSum -= minElement;
            res = max(res, maxSum * nums[i].first);
        }
        return res;
        
    }
};
