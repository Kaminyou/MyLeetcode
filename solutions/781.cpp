class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        vector<int> counts(1000, 0);
        for (auto& answer : answers) counts[answer]++;
        for (int i = 0; i < 1000; ++i) {
            while (counts[i]) {
                counts[i] -= min(counts[i], i + 1);
                res += i + 1;
            }
        }
        return res;
    }
};
