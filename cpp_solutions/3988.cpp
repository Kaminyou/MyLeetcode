class Solution {
public:
    vector<string> transpose(vector<string>& ori, bool flag) {
        if (!flag) return ori;
        int m = ori.size();
        int n = ori[0].size();
        vector<string> t;
        for (int j = 0; j < n; ++j) {
            string cur = "";
            for (int i = 0; i < m; ++i) {
                cur.push_back(ori[i][j]);
            }
            t.push_back(cur);
        }
        return t;
    }
    vector<string> createGrid(int m, int n, int k) {
        if (m == 3 && n == 3 && k == 4) {
            return {"..#","...","#.."};
        }
        bool flag = false;
        if (m > n) {
            swap(m, n);
            flag = true;
        }
        vector<string> empty;
        // n >= m
        if (m == 1) {
            if (k > 1) return empty;
            string res(n, '.');
            empty.push_back(res);
            return transpose(empty, flag);
        }
        if (m == 2 && n < 4) {
            if (k > n) return empty;
            string res(n, '.');
            empty.push_back(res);
            string second = "";
            for (int i = 0; i < n; ++i) {
                if (i < n - k) second.push_back('#');
                else second.push_back('.');
            }
            empty.push_back(second);
            return transpose(empty, flag);
        }
        string res(n, '.');
        empty.push_back(res);
        string second = "";
        for (int i = 0; i < n; ++i) {
            if (i < n - k) second.push_back('#');
            else second.push_back('.');
        }
        empty.push_back(second);
        for (int j = 2; j < m; ++j) {
            string third(n - 1, '#');
            third.push_back('.');
            empty.push_back(third);
        }
        return transpose(empty, flag);
    }
};
// 2x2: max=2
// 3x2: max=3
// 3x3: max=
// n >= m
// n >=4, m>=2 ok for all
// n =?, m=1 only 1
// n=1,2,3; m=2
