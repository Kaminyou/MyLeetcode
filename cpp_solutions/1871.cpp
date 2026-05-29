class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int n = s.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        int maxIndex = 0;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return true;
                int last = min(curr + maxJump, n - 1);
                int first = max(maxIndex, curr + minJump);
                for (int index = first; index <= last; index++) {
                    if (visited[index]) continue;
                    if (s[index] == '0') {
                        q.push(index);
                    }
                    visited[index] = true;
                    maxIndex = max(maxIndex, index);
                }
            }
        }
        return false;
    }
};
