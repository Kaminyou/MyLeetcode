class Solution {
public:
    unordered_set<string> cross(unordered_set<string>& a, unordered_set<string>& b) {
        if (a.size() == 0) a.insert("");
        if (b.size() == 0) b.insert("");
        unordered_set<string> res;
        for (auto i : a) {
            for (auto j : b) {
                res.insert(i + j);
            }
        }
        return res;
    }
    unordered_set<string> merge(unordered_set<string>& a, unordered_set<string>& b) {
        unordered_set<string> res;
        for (auto i : a) {
            res.insert(i);
        }
        for (auto i : b) {
            res.insert(i);
        }
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        string s = "";
        for (auto& c : expression) {
            if (isalpha(c)) {
                s.push_back('{');
                s.push_back(c);
                s.push_back('}');
            }
            else s.push_back(c);
        }

        unordered_set<string> current;
        stack<unordered_set<string>> stStr;
        stack<int> stOp;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '{') {
                stStr.push(current);
                stOp.push(0);
                current.clear();
            }
            else if (s[i] == ',') {
                stStr.push(current);
                stOp.push(1);
                current.clear();
            }
            else if (s[i] == '}') {
                while (stOp.top() == 1) {
                    current = merge(stStr.top(), current);
                    stStr.pop();
                    stOp.pop();
                }
                if (stOp.top() == 0) {
                    current = cross(stStr.top(), current);
                    stStr.pop();
                    stOp.pop();
                }
            }
            else {
                int start = i;
                while (i + 1 < n && isalpha(s[i + 1])) i++;
                // [start, i] is valid
                string sub = s.substr(start, i + 1 - start);
                current.insert(sub);
            }
        }
        vector<string> res(current.begin(), current.end());
        sort(res.begin(), res.end());
        return res;
    }
};
