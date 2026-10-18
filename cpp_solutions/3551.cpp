class Solution {
public:
    static int sumDigit(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    static bool compare(pair<int, int>& p1, pair<int, int>& p2) {
        int digit1 = sumDigit(p1.first);
        int digit2 = sumDigit(p2.first);
        if (digit1 != digit2) return digit1 < digit2;
        return p1.first < p2.first;
    }
    int dfs(int curr, vector<int>& indices, vector<bool>& visited) {
        if (visited[curr]) return 0;
        visited[curr] = true;
        int cnt = dfs(indices[curr], indices, visited);
        return cnt + 1;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> numWindex(n);
        for (int i = 0; i < n; ++i) {
            numWindex[i] = {nums[i], i};
        }
        sort(numWindex.begin(), numWindex.end(), compare);
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = numWindex[i].second;
        }
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            res += dfs(i, indices, visited) - 1;
        }
        return res;
    }
};
