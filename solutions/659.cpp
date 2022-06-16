class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> numFreq;
        unordered_map<int, int> endFreq;
        for (auto& num : nums) numFreq[num]++;
        for (auto& num : nums) {
            if (numFreq[num] == 0) continue;
            if (endFreq[num - 1] > 0) {
                numFreq[num]--;
                endFreq[num - 1]--;
                endFreq[num]++;
            }
            else if (numFreq[num + 1] > 0 && numFreq[num + 2] > 0) {
                numFreq[num]--;
                numFreq[num + 1]--;
                numFreq[num + 2]--;
                endFreq[num + 2]++;
            }
            else {
                return false;
            }
        }
        return true;
    }
};