class BIT {
private:
    int N;
    int M;
    vector<vector<int>> tree;
public:
    BIT(int n, int m, vector<vector<int>>& matrix) {
        N = n + 1;
        M = m + 1;
        tree.resize(N, vector<int>(M, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                update(i, j, matrix[i - 1][j - 1]);
            }
        }
    }
    int lsb(int x) {
        return x & (-x);
    }
    void update(int r, int c, int val) {
        for (int i = r; i < N; i += lsb(i)) {
            // j should be intialize in every loop
            // should not use (; j < M; j += lsb(j))
            for (int j = c; j < M; j += lsb(j)) {
                tree[i][j] += val;
            }
        }
    }
    int query(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= lsb(i)) {
            for (int j = c; j > 0; j -= lsb(j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
};
class NumMatrix {
public:
    BIT* bit;
    int N;
    int M;
    NumMatrix(vector<vector<int>>& matrix) {
        N = matrix.size();
        M = matrix[0].size();
        bit = new BIT(N, M, matrix);
    }
    
    void update(int row, int col, int val) {
        int currVal = sumRegion(row, col, row, col);
        int diff = val - currVal;
        bit->update(row + 1, col + 1, diff);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = bit->query(row2 + 1, col2 + 1);
        int b = bit->query(row2 + 1, col1);
        int c = bit->query(row1, col2 + 1);
        int d = bit->query(row1, col1);
        return a - b - c + d;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */