class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int distance(int x, int y) {
        return x * x + y * y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P> pq;
        for (auto point : points) {
            int dist = distance(point[0], point[1]);
            pq.push(make_pair(dist, make_pair(point[0], point[1])));
            while (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            P element = pq.top();
            pq.pop();
            res.push_back({element.second.first, element.second.second});
        }
        return res;
    }
};