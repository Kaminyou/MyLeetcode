class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> numsWIdx;
        int m = nums.size();
        for (int i = 0; i < m; ++i) {
            for (auto& num : nums[i]) {
                numsWIdx.push_back(make_pair(num, i));
            }
        }
        sort(numsWIdx.begin(), numsWIdx.end());
        vector<int> counts(m, 0);
        int left = 0;
        int n = numsWIdx.size();
        int numOfList = 0;
        int minInterval = INT_MAX;
        vector<int> res;
        for (int right = 0; right < n; ++right) {
            if (counts[numsWIdx[right].second] == 0) numOfList++;
            counts[numsWIdx[right].second]++;
            while (numOfList == m) {
                int interval = numsWIdx[right].first - numsWIdx[left].first + 1;
                if (interval < minInterval) {
                    minInterval = interval;
                    res = {numsWIdx[left].first, numsWIdx[right].first};
                }
                counts[numsWIdx[left].second]--;
                if (counts[numsWIdx[left].second] == 0) numOfList--;
                left++;
            }
        }
        return res;
    }
};