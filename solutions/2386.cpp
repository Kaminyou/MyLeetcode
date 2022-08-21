typedef pair<long long, int> P;
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        long long maxSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= 0) maxSum += nums[i];
            else nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        pq.push({nums[0], 0});
        vector<long long> substracts;
        while (!pq.empty() && substracts.size() < k - 1) {
            auto [substract, index] = pq.top();
            pq.pop();
            substracts.push_back(substract);
            if (index + 1 < n) {
                pq.push({substract + nums[index + 1], index + 1});
                pq.push({substract + nums[index + 1] - nums[index], index + 1});
            }
        }
        vector<long long> res;
        res.push_back(maxSum);
        for (int i = 0; i < substracts.size(); ++i) {
            res.push_back(maxSum - substracts[i]);
        }
        return res[k - 1];
    }
};