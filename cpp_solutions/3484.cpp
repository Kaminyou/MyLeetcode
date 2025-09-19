class Spreadsheet {
public:
    unordered_map<int, unordered_map<int, int>> mp;
    Spreadsheet(int rows) {
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mp[col][row] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1));
        mp[col][row] = 0;
    }
    bool isCell(string s) {
        if (s[0] - 'A' >= 0) return true;
        return false;
    }
    int getValue(string formula) {
        formula = formula.substr(1);
        int res = 0;
        stringstream ss(formula);
        string token;
        while (getline(ss, token, '+')) {
            if (isCell(token)) {
                int col = token[0] - 'A';
                int row = stoi(token.substr(1));
                res += mp[col][row];
            }
            else {
                res += stoi(token);
            }
        }
        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
