class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int curr = q.front();
                q.pop();
                if (arr[curr] == 0) return true;
                int left = curr - arr[curr];
                int right = curr + arr[curr];
                if (left >= 0 && !visited[left]) {
                    q.push(left);
                    visited[left] = true;
                }
                if (right < n && !visited[right]) {
                    q.push(right);
                    visited[right] = true;
                }
            }
        }
        return false;
    }
};
