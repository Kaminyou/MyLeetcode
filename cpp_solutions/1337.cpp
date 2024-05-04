class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxQ;

        for (int i = 0; i < m; ++i) {
            int left = 0;
            int right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (mat[i][mid] == 0) right = mid;
                else left = mid + 1;
            }
            maxQ.push({left, i});
            if (maxQ.size() > k) maxQ.pop();
        }

        vector<int> res;
        while (!maxQ.empty()) {
            res.push_back(maxQ.top().second);
            maxQ.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
