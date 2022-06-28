class Solution {
public:
    int minDeletions(string s) {
        vector<int> counts(26, 0);
        for (auto& c : s) counts[c - 'a']++;
        sort(counts.begin(), counts.end(), greater<int>());
        int currMax = INT_MAX;
        int res = 0;
        for (auto& count : counts) {
            if (count < currMax) {
                currMax = count;
            }
            else if (count >= currMax) {
                if (currMax > 0) currMax--;
                res += (count - currMax);
            }
        }
        return res;
    }
};