class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string current = s;
            int n = s.size();
            for (int i = 1; i < n; ++i) {
                string concat = s.substr(i) + s.substr(0, i);
                if (concat < current) current = concat;
            }
            return current;
        }
        sort(s.begin(), s.end());
        return s;
    }
};
