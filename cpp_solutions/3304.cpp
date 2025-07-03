class Solution {
public:
    string shift(string& s) {
        string res = s;
        int n = res.size();
        for (int i = 0; i < n; ++i) {
            res[i] = ((res[i] - 'a' + 1) % 26) + 'a';
        }
        return res;
    }
    char kthCharacter(int k) {
        string cur = "a";
        while (cur.size() < k) {
            cur = cur + shift(cur);
        }
        return cur[k - 1];
    }
};

