class Solution {
public:
    bool digitCount(string num) {
        vector<int> counts(10, 0);
        for (auto c : num) {
            counts[c - '0']++;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (counts[i] != num[i] - '0') return false;
        }
        return true;
    }
};