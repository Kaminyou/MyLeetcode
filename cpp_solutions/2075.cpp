class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int total = encodedText.size();
        if (total == 0) return "";
        int cols = total / rows;
        vector<vector<char>> grid(rows, vector<char>(cols, ' '));
        for (int i = 0; i < total; i++) {
            int r = i / cols;
            int c = i % cols;
            grid[r][c] = encodedText[i];
        }
        string res = "";
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                if (i + j >= cols) break;
                res.push_back(grid[j][i + j]);
            }
        }
        int n = res.size();
        int truncate = n - 1;
        while (res[truncate] == ' ') truncate--;
        res = res.substr(0, truncate + 1);
        return res;
    }
};
