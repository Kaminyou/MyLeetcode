class Solution {
public:
    bool isSorted(string& s) {
        char c = 'a';
        for (auto& cc : s) {
            if (cc < c) return false;
            c = cc;
        }
        return true;
    }
    int minOperations(string s) {
        if (isSorted(s)) return 0;

        int n = s.size();
        if (n == 2) {
            if (s[0] < s[1]) return 0;
            return -1;
        }

        // try to do one
        string t = s.substr(0, n - 1);
        sort(t.begin(), t.end());
        t.push_back(s[n - 1]);
        if (isSorted(t)) return 1;

        t = s.substr(1, n - 1);
        sort(t.begin(), t.end());
        t = s.substr(0, 1) + t;
        if (isSorted(t)) return 1;

        // try to do two
        t = s.substr(0, n - 1);
        sort(t.begin(), t.end());
        t.push_back(s[n - 1]);
        sort(t.begin() + 1, t.end());
        if (isSorted(t)) return 2;

        t = s.substr(1, n - 1);
        sort(t.begin(), t.end());
        t = s.substr(0, 1) + t;
        sort(t.begin(), t.end() - 1);
        if (isSorted(t)) return 2;

        return 3;
    }
};

