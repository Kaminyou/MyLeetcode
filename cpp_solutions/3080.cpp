typedef pair<int, int> P;
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum = 0;
        vector<long long> res;
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<P, vector<P>, greater<P>> pq;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            pq.push({nums[i], i});
        }
        for (auto query : queries) {
            if (!marked[query[0]]) {
                marked[query[0]] = true;
                sum -= nums[query[0]];
            }
            int cnt = query[1];
            while (cnt && !pq.empty()) {
                auto p = pq.top();
                pq.pop();
                int value = p.first;
                int index = p.second;
                if (marked[index]) continue;
                marked[index] = true;
                sum -= value;
                cnt--;
            }
            res.push_back(sum);
        }
        return res;
    }
};
