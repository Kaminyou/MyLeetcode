class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> hash(26, false);
        for (auto& c : allowed) hash[c - 'a'] = true;
        int cnt = 0;
        for (auto& word : words) {
            bool flag = true;
            for (auto& c : word) {
                if (hash[c - 'a'] == false) {
                    flag = false;
                    break;
                }
            }
            cnt += flag;
        }
        return cnt;
    }
};
