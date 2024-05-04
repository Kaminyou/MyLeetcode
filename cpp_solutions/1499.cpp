class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // yi + yj + |xi - xj| => yi - xi + yj + xj
        
        int res = INT_MIN;
        deque<int> q;
        for (int i = 0; i < points.size(); ++i) {
            while (!q.empty() && points[q.front()][0] < points[i][0] - k) q.pop_front();
            if (!q.empty()) {
                int maxIdx = q.front();
                res = max(res, points[maxIdx][1] - points[maxIdx][0] + points[i][1] + points[i][0]);
            }
            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[i][1] - points[i][0]) q.pop_back();
            q.push_back(i);
        }
        return res;
    }
};

// V2
// class Solution {
// public:
//     int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
//         multiset<int> st;
//         int res = INT_MIN;
//         int left = 0;
//         for (int right = 0; right < points.size(); ++right) {
//             while (points[right][0] - points[left][0] > k) {
//                 int target = points[left][1] - points[left][0];
//                 st.erase(st.find(target));
//                 left++;
//             }
//             if (!st.empty()) {
//                 res = max(res, *st.rbegin() + points[right][1] + points[right][0]);
//             }
            
//             st.insert(points[right][1] - points[right][0]);
//         }
//         return res;
//     }
// };

// // yi + yj + |xi - xj| = [yi - xi] + yj + xj