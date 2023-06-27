class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>, greater<P>> pq;
        int n = nums1.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && k) {
            P p = pq.top();
            pq.pop();
            int i = p.second.first;
            int j = p.second.second;
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            k--;
        }
        return res;
    }
};