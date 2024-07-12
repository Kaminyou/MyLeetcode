class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (y > x) {
            reverse(s.begin(), s.end());
            swap(x, y);
        }
        int res = 0;
        string t;
        for (auto& c : s) {
            t.push_back(c);
            if (t.size() >= 2 && t.substr(t.size() - 2) == "ab") {
                t.pop_back();
                t.pop_back();
                res += x;
            }
        }

        string w;
        for (auto& c : t) {
            w.push_back(c);
            if (w.size() >= 2 && w.substr(w.size() - 2) == "ba") {
                w.pop_back();
                w.pop_back();
                res += y;
            }
        }
        return res;
    }
};
