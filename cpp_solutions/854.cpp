class Solution {
public:
    int kSimilarity(string s1, string s2) {
        string s1trimed;
        string s2trimed;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                s1trimed.push_back(s1[i]);
                s2trimed.push_back(s2[i]);
            }
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(s1trimed);
        visited.insert(s1trimed);
        
        int level = 0;
        int m = s1trimed.size();
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                string current = q.front();
                q.pop();
                if (current == s2trimed) return level;
                int i = level;
                while (current[i] == s2trimed[i]) i++;
                for (int j = i + 1; j < m; ++j) {
                    if (current[j] == s2trimed[i]) {
                        string next = current;
                        swap(next[i], next[j]);
                        if (visited.find(next) == visited.end()) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
