class Solution {
public:
    int M;
    int N;
    int conv(vector<vector<int>>& img, int x, int y) {
        int count = 0;
        int sum = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int _x = x + i;
                int _y = y + j;
                if (_x < 0 || _x >= M || _y < 0 || _y >= N) continue;
                count++;
                sum += img[_x][_y];
            }
        }
        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        M = img.size();
        N = img[0].size();
        vector<vector<int>> out(M, vector(N, 0));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                out[i][j] = conv(img, i, j);
            }
        }
        return out;
    }
};