class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long current = 0;
        long long previous = 0;
        
        for (int i = 0; i < n; ++i) {
            int x1 = points[(i + 1) % n][0] - points[(i) % n][0];
            int x2 = points[(i + 2) % n][0] - points[(i + 1) % n][0];
            int y1 = points[(i + 1) % n][1] - points[(i) % n][1];
            int y2 = points[(i + 2) % n][1] - points[(i + 1) % n][1];
            
            current = x1 * y2 - x2 * y1;
            if (current == 0) continue;
            if (current * previous < 0) return false;
            previous = current;
        }
        return true;
    }
};