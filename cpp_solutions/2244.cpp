class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> counts;
        for (auto& task : tasks) counts[task]++;
        int res = 0;
        for (auto& [num, cnt] : counts) {
            if (cnt == 1) return -1;
            res += (cnt + 2) / 3;
        }
        return res;
    }
};
