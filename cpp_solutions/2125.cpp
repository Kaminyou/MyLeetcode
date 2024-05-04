class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> counts;
        for (auto& row : bank) {
            int count = 0;
            for (auto c : row) {
                if (c == '1') count++;
            }
            if (count) counts.push_back(count);
        }
        int res = 0;
        int n = counts.size();
        for (int i = 0; i < n - 1; ++i) {
            res += counts[i] * counts[i + 1];
        }
        return res;
    }
};