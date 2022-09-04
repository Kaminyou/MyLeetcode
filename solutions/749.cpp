class Solution {
public:
    int M;
    int N;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string hash(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
    pair<int, int> getArea(vector<vector<int>>& isInfected, int x, int y) {
        unordered_set<string> st;
        int edges = 0;
        
        queue<pair<int, int>> q;
        q.push({x, y});
        isInfected[x][y] = 2;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = currX + direction.first;
                int nextY = currY + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (isInfected[nextX][nextY] == 2) continue;
                if (isInfected[nextX][nextY] == 0) {
                    st.insert(hash(nextX, nextY));
                    edges++;
                }
                if (isInfected[nextX][nextY] == 1) {
                    q.push({nextX, nextY});
                    isInfected[nextX][nextY] = 2;
                }
            }
        }
        return {(int)st.size(), edges};
    }
    void protect(vector<vector<int>>& isInfected, int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        isInfected[x][y] = 3;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            for (auto& direction : directions) {
                int nextX = currX + direction.first;
                int nextY = currY + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (isInfected[nextX][nextY] == 0) continue;
                if (isInfected[nextX][nextY] == 1) {
                    q.push({nextX, nextY});
                    isInfected[nextX][nextY] = 3;
                }
            }
        }
    }
    pair<int, int> parser(string s) {
        int x = -1;
        int y = -1;
        string token;
        stringstream ss(s);
        while (getline(ss, token, '#')) {
            if (x == -1) {
                x = stoi(token);
            }
            else {
                y = stoi(token);
            }
        }
        return {x, y};
    }
    void contaminate(vector<vector<int>>& isInfected, int x, int y, unordered_set<string>& st) {
        
        queue<pair<int, int>> q;
        vector<pair<int, int>> visited;
        q.push({x, y});
        isInfected[x][y] = 2;
        while (!q.empty()) {
            auto [currX, currY] = q.front();
            q.pop();
            visited.push_back({currX, currY});
            for (auto& direction : directions) {
                int nextX = currX + direction.first;
                int nextY = currY + direction.second;
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
                if (isInfected[nextX][nextY] == 2) continue;
                if (isInfected[nextX][nextY] == 0) {
                    st.insert(hash(nextX, nextY));
                }
                if (isInfected[nextX][nextY] == 1) {
                    q.push({nextX, nextY});
                    isInfected[nextX][nextY] = 2;
                }
            }
        }
        for (auto& [i, j] : visited) isInfected[i][j] = 1;
    }
    void printMap(vector<vector<int>>& isInfected) {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << isInfected[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int containVirus(vector<vector<int>>& isInfected) {
        M = isInfected.size();
        N = isInfected[0].size();
        bool complete = false;
        int edgeSum = 0;
        while (!complete) {
            vector<vector<int>> isInfectedCopy(isInfected);
            vector<pair<int, pair<int, pair<int, int>>>> v;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (isInfectedCopy[i][j] == 1) {
                        auto [cells, edges] = getArea(isInfectedCopy, i, j);
                        v.push_back({cells, {edges, {i, j}}});
                    }
                }
            }
            sort(v.begin(), v.end());
            int n = v.size();
            if (n <= 1) complete = true;
            if (n >= 1) {
                protect(isInfected, v[n - 1].second.second.first, v[n - 1].second.second.second);
                edgeSum += v[n - 1].second.first;
            }
            
            unordered_set<string> st;
            for (int i = 0; i < n - 1; ++i) {
                contaminate(isInfected, v[i].second.second.first, v[i].second.second.second, st);
            }
            
            for (auto& element : st) {
                pair<int, int> p = parser(element);
                isInfected[p.first][p.second] = 1;
            }
            
        }
        return edgeSum;
    }
};