class Solution {
public:
    int N;
    void dfs1(vector<vector<int>>& adjacency, int cur, int pre, vector<int>& count, vector<int>& res) {
        for (auto& neighbor : adjacency[cur]) {
            if (neighbor == pre) continue;
            dfs1(adjacency, neighbor, cur, count, res);
            count[cur] += count[neighbor];
            res[cur] += res[neighbor] + count[neighbor];
        }
        ++count[cur];
    }
    void dfs2(vector<vector<int>>& adjacency, int cur, int pre, vector<int>& count, vector<int>& res) {
        for (auto& neighbor : adjacency[cur]) {
            if (neighbor == pre) continue;
            res[neighbor] = res[cur] - count[neighbor] + (N - count[neighbor]);
            dfs2(adjacency, neighbor, cur, count, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n, 0);
        vector<int> count(n, 0);
        dfs1(adjacency, 0, -1, count, res);
        dfs2(adjacency, 0, -1, count, res);
        return res;
    }
};

class Solution {
public:
    unordered_map<string, int> edge2cnt;
    int N;
    int dfs(int node, vector<vector<int>>& adjacency, vector<bool>& visited) {
        visited[node] = true;
        int total = 1;
        for (auto& neighbor : adjacency[node]) {
            if (visited[neighbor]) continue;
            int cnt = dfs(neighbor, adjacency, visited);
            edge2cnt[to_string(node) + "#" + to_string(neighbor)] = cnt;
            edge2cnt[to_string(neighbor) + "#" + to_string(node)] = N - cnt;
            total += cnt;
        }
        return total;
    }
    void dfsEdge(int node, vector<vector<int>>& adjacency, vector<bool>& visited, int cnt, int& total) {
        visited[node] = true;
        total += cnt;
        for (auto& neighbor : adjacency[node]) {
            if (visited[neighbor]) continue;
            dfsEdge(neighbor, adjacency, visited, cnt + 1, total);
        }
    }
    void dfsAnswer(int node, vector<vector<int>>& adjacency, vector<bool>& visited, int previous, vector<int>& res) {
        visited[node] = true;
        for (auto& neighbor : adjacency[node]) {
            if (visited[neighbor]) continue;
            int next = previous - edge2cnt[to_string(node) + "#" + to_string(neighbor)] + edge2cnt[to_string(neighbor) + "#" + to_string(node)];
            res[neighbor] = next;
            dfsAnswer(neighbor, adjacency, visited, next, res);
        }
    }
    void resetVisit(vector<bool>& visited) {
        for (int i = 0; i < N; ++i) visited[i] = false;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        dfs(0, adjacency, visited);
        
        vector<int> res(n, 0);
        resetVisit(visited);
        int total = 0;
        dfsEdge(0, adjacency, visited, 0, total);
        res[0] = total;
        
        resetVisit(visited);
        dfsAnswer(0, adjacency, visited, total, res);
        return res;
    }
};

class Solution {
public:
    int dfs(int node, int parent, int depth, vector<int>& childrens, int& sum, vector<vector<int>>& adjacency) {
        sum += depth;
        int childrenCnt = 0;
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            childrenCnt += dfs(neighbor, node, depth + 1, childrens, sum, adjacency);
        }
        childrens[node] = childrenCnt;
        return childrenCnt + 1;
    }
    void dfs2(int n, int sum, int node, int parent, vector<int>& childrens, vector<vector<int>>& adjacency, vector<int>& answer) {
        answer[node] = sum;
        
        for (auto& neighbor : adjacency[node]) {
            if (neighbor == parent) continue;
            int childrenCnt = childrens[neighbor] + 1;
            int leftCnt = n - childrenCnt;
            dfs2(n, sum - childrenCnt + leftCnt, neighbor, node, childrens, adjacency, answer);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency(n);
        for (auto& edge : edges) {
            adjacency[edge[0]].push_back(edge[1]);
            adjacency[edge[1]].push_back(edge[0]);
        }

        vector<int> childrens(n, 0);
        vector<int> res(n, 0);
        int sum = 0;
        dfs(0, -1, 0, childrens, sum, adjacency);
        dfs2(n, sum, 0, -1, childrens, adjacency, res);
        return res;
    }
};