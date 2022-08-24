class Solution {
public:
    pair<int, int> parser(string half) {
        if (half[0] != '-') half = "+" + half;
        int index = 0;
        int n = half.size();
        int xParam = 0;
        int constParam = 0;
        while (index < n) {
            int flag = 1;
            if (half[index] == '-') flag = -1;
            
            index++;
            int start = index;
            while (index + 1 < n && half[index + 1] != '+' && half[index + 1] != '-') {
                index++;
            }
            string temp = half.substr(start, index - start + 1);
            int m = temp.size();
            if (temp[m - 1] == 'x') {
                if (m == 1) xParam += flag * 1;
                else {
                    int param = stoi(temp.substr(0, m - 1));
                    xParam += flag * param;
                }
            }
            else {
                int param = stoi(temp);
                constParam += flag * param;
            }
            index++;
        }
        return {xParam, constParam};
    }
    string solveEquation(string equation) {
        string token;
        stringstream ss(equation);
        
        vector<pair<int, int>> v;
        while (getline(ss, token, '=')) {
            v.push_back(parser(token));
        }
        if (v[0].first == v[1].first) {
            if (v[0].second != v[1].second) return "No solution";
            else return "Infinite solutions";
        }
        int xNum = v[0].first - v[1].first;
        int yNum = v[1].second - v[0].second;
        return "x=" + to_string(yNum / xNum);
    }
};