class Solution {
public:
    bool isNeighbor(string& s1, string& s2) {
        int n = s1.size();
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        int index = 0;
        unordered_map<string, int> gene2idx;
        for (auto& gene : bank) {
            gene2idx[gene] = index;
            index++;
        }
        if (gene2idx.find(end) == gene2idx.end()) return -1;
        
        int startIdx = -1;
        int endIdx = gene2idx[end];
        if (gene2idx.find(start) == gene2idx.end()) {
            gene2idx[start] = index;
            bank.push_back(start);
            startIdx = index;
        }
        else startIdx = gene2idx[start];
        
        int n = bank.size();
        vector<vector<int>> adjacency(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isNeighbor(bank[i], bank[j])) {
                    adjacency[gene2idx[bank[i]]].push_back(gene2idx[bank[j]]);
                    adjacency[gene2idx[bank[j]]].push_back(gene2idx[bank[i]]);
                }
            }
        }
        
        queue<int> q;
        q.push(startIdx);
        visited[startIdx] = true;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int currNode = q.front();
                q.pop();
                if (currNode == endIdx) return level;
                for (auto& neighbor : adjacency[currNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
            level++;
        }
        return -1;
    }
};