class Solution {
public:
    bool valid(vector<vector<int>>& squares, double mid) {
        double top = 0;
        double down = 0;
        for (auto& square : squares) {
            double l = square[2];
            double y = square[1];
            top += l * min(max(y + l - mid, 0.0), l);
            down += l * min(max(mid - y, 0.0), l);
        }
        return top <= down; 
    }
    double separateSquares(vector<vector<int>>& squares) {
        double left = 0;
        double right = 1e9 + 1;
        while (right - left > 0.00001) {
            double mid = left + (right - left) / 2;
            if (valid(squares, mid)) right = mid;
            else left = mid;
        }
        return left;
    }
};
