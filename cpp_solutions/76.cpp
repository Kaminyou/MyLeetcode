class Solution {
public:
    int char2idx(char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
        return -1;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (n > m) return "";
        
        vector<int> tCount(52, 0);
        for (auto& c : t) tCount[char2idx(c)]++;
        int remaining = n;
        
        int minLen = INT_MAX;
        int begin = -1;
        
        int left = 0;
        for (int right = 0; right < m; ++right) {
            if (tCount[char2idx(s[right])] > 0) remaining--;
            tCount[char2idx(s[right])]--;
            
            while (remaining == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    begin = left;
                }
                if (tCount[char2idx(s[left])] == 0) remaining++;
                tCount[char2idx(s[left])]++;
                left++;
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(begin, minLen);
    }
};