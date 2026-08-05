class Solution {
public:
    int N;
    int hash(int i, int j, int p) {
        return (i * N + j) * 2 + p;
    }
    vector<int> dehash(int num) {
        int p = num & 1;
        num >>= 1;
        int j = num % N;
        int i = num / N;
        return {i, j, p};
    }
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        N = n;
        vector<long long> minC(m * n * 2 + 2, LLONG_MAX / 2);
        vector<vector<int>> directions = {{1, 0, 1}, {0, 1, 1}, {-1, 0, 0}, {0, -1, 0}};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({1LL, hash(0, 0, 0)});
        while (!pq.empty()) {
            auto [cost, h] = pq.top();
            pq.pop();
            vector<int> hh = dehash(h);
            int i = hh[0];
            int j = hh[1];
            int p = hh[2];
            if (i == m - 1 && j == n - 1) return cost;
            minC[hash(i, j, p)] = cost;
            p ^= 1; // current step
            for (auto& direction : directions) {
                int x = i + direction[0];
                int y = j + direction[1];
                if (x >= m || x < 0 || y >= n || y < 0) continue;
                int c = 0;
                if (p == direction[2]) {
                    c = (x + 1) * (y + 1);
                }
                else {
                    c = penalty[i][j] + (x + 1) * (y + 1);
                }
                if (minC[hash(x, y, p)] > cost + c) {
                    pq.push({cost + c, hash(x, y, p)});
                    minC[hash(x, y, p)] = cost + c;
                }
            }

            // wait
            int c = penalty[i][j];
            if (minC[hash(i, j, p)] > cost + c) {
                pq.push({cost + c, hash(i, j, p)});
                minC[hash(i, j, p)] = cost + c;
            }
        }
        return -1;
    }
};
