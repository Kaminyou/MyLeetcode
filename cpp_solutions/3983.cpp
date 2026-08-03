class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m == 1) return true;
        if (m > n) return false;
        vector<int> leftMatch(m, -1);
        vector<int> rightMatch(m, -1);
        // left to right
        int right = 0;
        for (int left = 0; left < m; ++left) {
            while (right < n && s[left] != t[right]) right++;
            if (right < n && s[left] == t[right]) {
                leftMatch[left] = right;
                right++;
            }
        }
        // right to left
        right = n - 1;
        for (int left = m - 1; left >= 0; --left) {
            while (right >= 0 && s[left] != t[right]) right--;
            if (right >= 0 && s[left] == t[right]) {
                rightMatch[left] = right;
                right--;
            }
        }

        if (leftMatch[m - 1] != -1) return true;
        if (leftMatch[m - 2] != -1 && leftMatch[m - 2] != n - 1) return true;
        if (rightMatch[1] != -1 && rightMatch[1] != 0) return true;
        for (int i = 0; i < m - 2; ++i) {
            if (leftMatch[i] != -1 && rightMatch[i + 2] != -1 && leftMatch[i] + 1 < rightMatch[i + 2]) return true;
        }
        return false;
    }
};

