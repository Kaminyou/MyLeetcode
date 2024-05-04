class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> row2cols;
    unordered_map<int, unordered_map<int, int>> col2rows;
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        row2cols[point[0]][point[1]]++;
        col2rows[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int row = point[0];
        int col = point[1];
        // check row
        if (row2cols.find(row) == row2cols.end()) return 0;
        
        // iterate available cols
        for (auto& [abailableCol, colCount] : row2cols[row]) {
            int distance = abs(abailableCol - col);
            if (distance == 0) continue;
            
            // check up
            if (col2rows[col].find(row + distance) != col2rows[col].end()) {
                int rowCount = col2rows[col][row + distance];
                if (col2rows[abailableCol].find(row + distance) != col2rows[abailableCol].end()) {
                    int anchorCount = col2rows[abailableCol][row + distance];
                    res += colCount * rowCount * anchorCount;
                }
            }
            
            // check down
            if (col2rows[col].find(row - distance) != col2rows[col].end()) {
                int rowCount = col2rows[col][row - distance];
                if (col2rows[abailableCol].find(row - distance) != col2rows[abailableCol].end()) {
                    int anchorCount = col2rows[abailableCol][row - distance];
                    res += colCount * rowCount * anchorCount;
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */