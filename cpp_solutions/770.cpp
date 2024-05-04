class Solution {
public:
    struct cmp {
        bool operator() (const vector<string>& a, const vector<string>& b) const {
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        }  
    };
    map<vector<string>, int, cmp> helper(string expression, unordered_map<string, int>& eval) {
        map<vector<string>, int, cmp> local{{{}, 1}}, res;
        string sub;
        int n = expression.size();
        for (int i = 0, sign = 1; i <= n; ++i) {
            if (i < n && expression[i] == ' ') continue;
            if (i < n && isalnum(expression[i])) sub += expression[i];
            else if (i < n && expression[i] == '(') {
                ++i;
                for (int cnt = 1; ; ++i) {
                    if (expression[i] == '(') ++cnt;
                    else if (expression[i] == ')') --cnt;
                    if (cnt == 0) break;
                    sub += expression[i];
                }
            }
            else {
                if (sub.size() == n) {
                    if (eval.count(sub)) return {{{}, eval[sub]}};
                    if (isdigit(sub[0])) return {{{}, stoi(sub)}};
                    return {{{sub}, 1}};
                }
                map<vector<string>, int, cmp> multi, t = helper(sub, eval);
                for (auto& a : local) {
                    for (auto& b : t) {
                        auto k = a.first;
                        k.insert(k.end(), b.first.begin(), b.first.end());
                        sort(k.begin(), k.end());
                        multi[k] += a.second * b.second;
                    }
                }
                local = move(multi);
                if (i == n || expression[i] != '*') {
                    for (auto& a : local) {
                        res[a.first] += sign * a.second;
                    }
                    sign = (i < n && expression[i] == '-') ? -1 : 1;
                    local = {{{}, 1}};
                }
                sub = "";
            }
        }
        return res;
    }
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;
        int n = evalvars.size();
        for (int i = 0; i < n; ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        vector<string> res;
        auto out = helper(expression, eval);
        for (auto& element : out) {
            if (element.second == 0) continue;
            res.push_back(to_string(element.second));
            for (auto& token : element.first) {
                res.back() += "*" + token;
            }
        }
        return res;
    }
};