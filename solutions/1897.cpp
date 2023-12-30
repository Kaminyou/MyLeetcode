class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> counts(26, 0);
        for (auto& word : words) {
            for (auto& c : word) {
                counts[c - 'a'] += 1;
            }
        }
        for (auto& count : counts) {
            if (count == 0) continue;
            if (count < n) return false;
            if (count % n) return false;
        }
        return true;
    }
};
