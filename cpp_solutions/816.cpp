class Solution {
public:
    vector<string> addPoint(string s) {
        vector<string> res;
        if (s.size() == 1) {
            res.push_back(s);
            return res;
        }
        int zeroCnt = 0;
        for (auto& c : s) {
            if (c == '0') zeroCnt++;
        }
        if (zeroCnt == 0) {
            int n = s.size();
            res.push_back(s);
            for (int i = 1; i < n; ++i) {
                res.push_back(s.substr(0, i) + "." + s.substr(i));
            }
            return res;
        }
        if (zeroCnt == s.size()) return {};
        
        // zeroCnt >= 1
        int n = s.size();
        if (s[0] == '0' && s[n - 1] != '0') return {"0." + s.substr(1)};
        if (s[0] == '0' && s[n - 1] == '0') return {};
        if (s[0] != '0' && s[n - 1] == '0') return {s};

        res.push_back(s);
        for (int i = 1; i < n; ++i) {
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return res;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        s = s.substr(1);
        s = s.substr(0, s.size() - 1);
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            vector<string> left = addPoint(s.substr(0, i));
            vector<string> right = addPoint(s.substr(i));
            for (auto& l : left) {
                for (auto& r : right) {
                    res.push_back("(" + l + ", " + r + ")");
                }
            }
        }
        return res;
    }
};
