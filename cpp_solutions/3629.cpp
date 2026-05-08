class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> num2minPrime(maxVal + 1, 0);
        for (int i = 0; i <= maxVal; ++i) num2minPrime[i] = i;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (num2minPrime[i] == i) {
                for (int j = i * i; j <= maxVal; j += i) {
                    if (num2minPrime[j] == j) {
                        num2minPrime[j] = i;
                    }
                }
            }
        }

        unordered_map<int, vector<int>> prime2pos;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            while (x > 1) {
                int prime = num2minPrime[x];
                prime2pos[prime].push_back(i);
                while (x % prime == 0) {
                    x /= prime;
                }
            }
        }

        int count = 0;
        vector<bool> visited(n, false);
        unordered_set<int> visitedPrime;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int node = q.front();
                if (node == n - 1) return count;
                q.pop();
                if (node - 1 >= 0 && !visited[node - 1]) {
                    q.push(node - 1);
                    visited[node - 1] = true;
                }
                if (node + 1 < n && !visited[node + 1]) {
                    q.push(node + 1);
                    visited[node + 1] = true;
                }
                if (prime2pos.count(nums[node])) {
                    if (!visitedPrime.count(nums[node])) {
                        visitedPrime.insert(nums[node]);
                        for (auto& pos : prime2pos[nums[node]]) {
                            if (visited[pos]) continue;
                            visited[pos] = true;
                            q.push(pos);
                        }
                    }

                }
            }
            count++;
        }
        return -1;
    }
};
