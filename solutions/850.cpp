class TwoDimDiff {
public:
    vector<vector<int>> grid;
    vector<vector<int>> result;
    int m;
    int n;
    TwoDimDiff(int m, int n) {
        grid.resize(m, vector<int>(n, 0));
        result.resize(m, vector<int>(n, 0));
        this->m = m;
        this->n = n;
    }
    void add(int x0, int y0, int x1, int y1, int val) {
        grid[x0][y0] += val;
        grid[x0][y1 + 1] -= val;
        grid[x1 + 1][y0] -= val;
        grid[x1 + 1][y1 + 1] += val;
    }
    void compute() {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = (i >= 1 && j >= 1 ? result[i - 1][j - 1] : 0);
                int b = (i >= 1 ? result[i - 1][j] : 0);
                int c = (j >= 1 ? result[i][j - 1] : 0);
                result[i][j] = b + c - a + grid[i][j];
            }
        }
    }
};
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long mod = 1e9 + 7;
        set<int> pointX;
        set<int> pointY;
        for (auto& rectangle : rectangles) {
            pointX.insert(rectangle[0]);
            pointY.insert(rectangle[1]);
            pointX.insert(rectangle[2]);
            pointY.insert(rectangle[3]);
        }
        int m = pointX.size();
        int n = pointY.size();
        vector<int> idx2pointX(m, 0);
        vector<int> idx2pointY(n, 0);
        unordered_map<int, int> pointX2idx;
        unordered_map<int, int> pointY2idx;
        
        int index = 0;
        for (auto element : pointX) {
            idx2pointX[index] = element;
            pointX2idx[element] = index;
            index++;
        }
        index = 0;
        for (auto element : pointY) {
            idx2pointY[index] = element;
            pointY2idx[element] = index;
            index++;
        }
        TwoDimDiff* twoDimDiff = new TwoDimDiff(m, n);
        for (auto& rectangle : rectangles) {
            int x0 = pointX2idx[rectangle[0]];
            int y0 = pointY2idx[rectangle[1]];
            int x1 = pointX2idx[rectangle[2]];
            int y1 = pointY2idx[rectangle[3]];
            twoDimDiff->add(x0, y0, x1 - 1, y1 - 1, 1);
        }
        twoDimDiff->compute();
        
        long long res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (twoDimDiff->result[i][j] > 0) {
                    long long x = idx2pointX[i + 1] - idx2pointX[i];
                    long long y = idx2pointY[j + 1] - idx2pointY[j];
                    res += x * y;
                    res %= mod;
                }
            }
        }
        return res;
    }
};