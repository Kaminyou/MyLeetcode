class Solution {
public:
    int minimumPushes(string word) {
        vector<int> counts(26, 0);
        for (auto& c : word) {
            counts[c - 'a']++;
        }
        sort(counts.begin(), counts.end(), greater<int>());
        int res = 0;
        int cnt = 0;
        int cost = 1;
        for (int i = 0; i < 26; ++i) {
            res += cost * counts[i];
            cnt += 1;
            if (cnt == 8) {
                cnt = 0;
                cost += 1;
            }
        }
        return res;
    }
};
