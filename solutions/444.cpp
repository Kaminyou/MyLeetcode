class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        vector<vector<int>> adjacency(10001);
        vector<int> inDegrees(10001, 0);
        vector<bool> existed(10001, false);
        for (auto& sequence : sequences) {
            int n = sequence.size();
            existed[sequence[0]] = true;
            for (int i = 1; i < n; ++i) {
                adjacency[sequence[i - 1]].push_back(sequence[i]);
                inDegrees[sequence[i]]++;
                existed[sequence[i]] = true;
            }
        }
        
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < 10001; ++i) {
            if (existed[i] && inDegrees[i] == 0) q.push(i);
        }
        if (q.size() > 1) return false;
        while (!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();
            int count = 0;
            for (auto& neighbor : adjacency[node]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                    count++;
                    if (count > 1) return false;
                }
            }
        }
        if (res.size() != nums.size()) return false;
        int m = res.size();
        for (int i = 0; i < m; ++i) {
            if (res[i] != nums[i]) return false;   
        }
        return true;
    }
};