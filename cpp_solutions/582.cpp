class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            children[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> res;
        queue<int> q;
        q.push(kill);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (auto& child : children[node]) {
                q.push(child);
            }
        }
        return res;
    }
};