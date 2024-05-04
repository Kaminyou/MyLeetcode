class Solution {
public:
    class compare {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }  
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (auto& num : nums) mp[num]++;

        for (auto p : mp) {
            pq.push(p);
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            res.push_back(p.first);
        }
        return res;
    }
};
