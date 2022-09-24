class Solution {
public:
    vector<long long> res;
    bool flag = false;
    void backtracking(string& num, int currentIdx, vector<long long>& seq) {
        if (flag) return;
        int n = num.size();
        if (currentIdx == n && seq.size() >= 3) {
            res = seq;
            flag = true;
            return;
        }
        if (seq.size() <= 1) {
            if (num[currentIdx] == '0') {
                seq.push_back(0);
                backtracking(num, currentIdx + 1, seq);
                seq.pop_back();
            }
            else {
                for (int i = 1; currentIdx + i <= n; ++i) {
                    string temp = num.substr(currentIdx, i);
                    long long value = stoll(temp);
                    if (value > INT_MAX) break;
                    seq.push_back(value);
                    backtracking(num, currentIdx + i, seq);
                    seq.pop_back();
                }
            }
        }
        else {
            if (num[currentIdx] == '0') {
                int m = seq.size();
                if (seq[m - 2] + seq[m - 1] == 0) {
                    seq.push_back(0);
                    backtracking(num, currentIdx + 1, seq);
                    seq.pop_back();
                }
            }
            else {
                for (int i = 1; currentIdx + i <= n; ++i) {
                    string temp = num.substr(currentIdx, i);
                    long long value = stoll(temp);
                    if (value > INT_MAX) break;
                    int m = seq.size();
                    if (seq[m - 2] + seq[m - 1] == value) {
                        seq.push_back(value);
                        backtracking(num, currentIdx + i, seq);
                        seq.pop_back();
                    }
                }
            }
        }
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<long long> seq;
        backtracking(num, 0, seq);
        vector<int> intRes;
        for (auto& num : res) {
            if (num > INT_MAX) return {};
            intRes.push_back(num);
        }
        return intRes;
    }
};