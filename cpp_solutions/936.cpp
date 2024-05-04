class Solution {
public:
    int replace(string& stamp, string& target, int index) {
        int n = stamp.size();
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            if (target[index + i] == '*') {
                cnt--;
            }
            else if (target[index + i] != stamp[i]) {
                return 0;
            }
        }
        fill(target.begin() + index, target.begin() + index + n, '*');
        return cnt;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        int m = stamp.size();
        vector<bool> stamped(n, false);
        
        int required = n;
        vector<int> res;
        while (required) {
            bool hasReplaced = false;
            for (int i = 0; i + m <= n; ++i) {
                if (stamped[i]) continue;
                int l = replace(stamp, target, i);
                if (l == 0) continue;
                res.push_back(i);
                hasReplaced = true;
                required -= l;
            }
            
            if (!hasReplaced) return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};