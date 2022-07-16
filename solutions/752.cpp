class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> deadendHash;
        for (auto& s : deadends) deadendHash.insert(s);
        if (deadendHash.find("0000") != deadendHash.end()) return -1;
        
        unordered_set<string> visited;
        visited.insert("0000");
        queue<string> q;
        q.push("0000");
        
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                string current = q.front();
                q.pop();
                if (current == target) return res;
                for (int j = 0; j < 4; ++j) {
                    for (int k = -1; k <= 1; ++k) {
                        if (k == 0) continue;
                        string next = current;
                        next[j] = ((next[j] - '0' + 10 + k) % 10) + '0';
                        if (deadendHash.count(next) || visited.count(next)) continue;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};