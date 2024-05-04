class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int position = 0;
            for (int i = 0; i < n; i++) {
                position += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (position >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

// v2
// typedef pair<int, pair<int, int>> P; // num {x, y}
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         priority_queue<P, vector<P>, greater<P>> pq;
//         for (int i = 0; i < n; ++i) {
//             pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
//         }
        
//         int ans = -1;
//         while (k--) {
//             auto [num, idx] = pq.top();
//             auto [x, y] = idx;
//             ans = num;
//             pq.pop();
//             if (y + 1 != n) pq.push(make_pair(matrix[x][y + 1], make_pair(x, y + 1)));
//         }
//         return ans;
//     }
// };