class Solution {
public:
    vector<int> res;
    void backtracking(string& num, int current, int n, int k) {
        if (current == n) {
            res.push_back(stoi(num));
            return;
        }
        int last = num.back() - '0';
        if (last + k <= 9) {
            num.push_back(last + k + '0');
            backtracking(num, current + 1, n, k);
            num.pop_back();
        }
        if (k != 0 && last - k >= 0) {
            num.push_back(last - k + '0');
            backtracking(num, current + 1, n, k);
            num.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i < 10; ++i) {
            string temp;
            temp.push_back(i + '0');
            backtracking(temp, 1, n, k);
        }
        return res;
    }
};