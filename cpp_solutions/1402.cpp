class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int res = 0;
        int prefixSum = 0;
        for (auto num : satisfaction) {
            if (prefixSum + num < 0) break;
            prefixSum += num;
            res += prefixSum;
        }
        return res;
    }
};