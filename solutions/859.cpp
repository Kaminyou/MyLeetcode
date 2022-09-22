class Solution {
public:
    bool buddyStrings(string s, string goal) {
        vector<int> cnt(26, 0);
        int maxCnt = 0;
        vector<int> difference;
        if (s.size() != goal.size()) return false;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) difference.push_back(i);
            cnt[s[i] - 'a']++;
            maxCnt = max(maxCnt, cnt[s[i] - 'a']);
        }
        if (difference.size() == 1 || difference.size() > 2) return false;
        if (difference.size() == 0) {
            if (maxCnt >= 2) return true;
            else return false;
        }
        
        // difference.size() == 2
        if (s[difference[0]] == goal[difference[1]] && s[difference[1]] == goal[difference[0]]) return true;
        else return false;
    }
};