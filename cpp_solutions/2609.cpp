class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        vector<int> lengths;
        vector<char> chars;
        int index = 0;
        int n = s.size();
        while (index < n) {
            int start = index;
            int target = s[index];
            while (index + 1 < n && s[index + 1] == target) index++;
            int length = index - start + 1;
            lengths.push_back(length);
            chars.push_back(target);
            index++;
        }
        
        int m = lengths.size();
        int res = 0;
        int current = 0;
        if (chars[0] == '1') current = 1;
        for (current; current < m; current += 2) {
            int zeroCnt = lengths[current];
            if (current + 1 >= m) return res;
            int oneCnt = lengths[current + 1];
            res = max(res, min(zeroCnt, oneCnt) * 2);
        }
        return res;
    }
};