class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        
        // build graph
        vector<vector<int>> graph(26);
        vector<int> inDegrees(26, -1);
        
        // encode first one
        // edge case: only one word
        for (auto c : words[0]) {
            if (inDegrees[c - 'a'] == -1) inDegrees[c - 'a'] = 0;
        }
        
        for (int i = 1; i < n; i++) {
            string prev = words[i - 1];
            string post = words[i];
            for (auto c : post) {
                if (inDegrees[c - 'a'] == -1) inDegrees[c - 'a'] = 0;
            }
            int len = min(prev.size(), post.size());
            
            // edge case: prev > post (e.g., "bcda", "bcd")
            if (prev.substr(0, len) == post.substr(0, len) && prev.size() > post.size()) return "";
            for (int k = 0; k < len; k++) {
                if (prev[k] != post[k]) {
                    graph[prev[k] - 'a'].push_back(post[k] - 'a');
                    inDegrees[post[k] - 'a']++;
                    break;
                }
            }
        }
        
        // topological sort
        string res;
        int count = 0;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (inDegrees[i] == 0) q.push(i);
            if (inDegrees[i] >= 0) count++;
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(static_cast<char>(node + 'a'));
            for (auto neighbor : graph[node]) {
                inDegrees[neighbor]--;
                if (inDegrees[neighbor] == 0) q.push(neighbor);
            }
        }
        if (res.size() < count) return "";
        return res;
    }
};