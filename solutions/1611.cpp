class Solution {
public:
    unordered_map<string, int> mp1;
    unordered_map<string, int> mp2;
    int minimumOneBitOperations(int n) {
        if (n == 0) return 0;
        string s;
        while (n) {
            s.push_back((n & 1) + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
        return minimumOneBitOperations(s);
    }
    int minimumOneBitOperations(string n) {
        if (n == "0") return 0;
        if (n == "1") return 1;
        if (n[0] == '0') return minimumOneBitOperations(n.substr(1));
        if (mp1.count(n)) return mp1[n];

        int m = n.size();
        string s = n.substr(1);
        string t = string(m - 1, '0');
        t[0] = '1';
        return mp1[n] = helper(s) + 1 + minimumOneBitOperations(t);
    }
    int helper(string n) {
        if (n == "0") return 1;
        if (n == "1") return 0;

        if (n[0] == '1') return minimumOneBitOperations(n.substr(1));
        if (mp2.count(n)) return mp2[n];

        int m = n.size();
        string s = n.substr(1);
        string t = string(m - 1, '0');
        t[0] = '1';
        return mp2[n] = helper(s) + 1 + minimumOneBitOperations(t);
    }
};
// helper: XXXX -> 1000
// dfs(1XXXX) = helper(XXXX) + 1 + dfs(1000)

// helper(1XXX) = dfs(XXX)
// helper(0XXX) = helper(XXX) + 1 + dfs(100)
