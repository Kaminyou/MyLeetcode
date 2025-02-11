class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        int m = n / k;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i += m) {
            string sub1 = s.substr(i, m);
            string sub2 = t.substr(i, m);
            mp[sub1]++;
            mp[sub2]--;
        }
        for (auto& [ss, cnt] : mp) {
            if (cnt != 0) return false;
        }
        return true;
    }
};
