class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        unordered_map<int, int> mp;
        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        for (auto& num : aliceSizes) {
            mp[sumAlice - num * 2] = num;
        }
        for (auto& num : bobSizes) {
            if (mp.find(sumBob - 2 * num) != mp.end()) {
                return {mp[sumBob - 2 * num], num};
            }
        }
        return {};
    }
};

// N + a = M + b; exchange a, b
// N + b = sumN || M + a = sumM
// N - b = M - a
// sumN - 2 * b == sumM - 2 * a
