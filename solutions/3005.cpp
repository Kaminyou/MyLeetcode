class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        int cntFreq = 0;
        vector<int> counts(101, 0);
        for (auto& num : nums) {
            counts[num] += 1;
            if (counts[num] == maxFreq) {
                cntFreq += 1;
            }
            if (counts[num] > maxFreq) {
                maxFreq = counts[num];
                cntFreq = 1;
            }
        }
        return maxFreq * cntFreq;
    }
};
