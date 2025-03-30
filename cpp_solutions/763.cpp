class Solution {
public:
    bool isValid(vector<bool>& used, vector<int>& counts) {
        for (int i = 0; i < 26; ++i) {
            if (used[i]) {
                if (counts[i] != 0) return false;
            }
        }
        return true;
    }
    vector<int> partitionLabels(string s) {
        vector<int> counts(26, 0);
        for (auto& c : s) counts[c - 'a']++;
        vector<int> res;
        int index = 0;
        int n = s.size();
        while (index < n) {
            int start = index;
            vector<bool> used(26, false);
            used[s[index] - 'a'] = true;
            counts[s[index] - 'a']--;
            while (!isValid(used, counts) && index + 1 < n) {
                index++;
                used[s[index] - 'a'] = true;
                counts[s[index] - 'a']--;
            }
            res.push_back(index - start + 1);
            index++;
        }
        return res;
    }
};
