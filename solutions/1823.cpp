class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) q.push(i);
        while (q.size() > 1) {
            for (int j = 0; j < k - 1; ++j) {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
            q.pop();
        }
        return q.front();
    }
};