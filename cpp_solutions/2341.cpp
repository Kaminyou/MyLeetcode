class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> counting(101, 0);
        for (auto& num : nums) counting[num]++;
        
        int pairs = 0;
        for (int i = 0; i < 101; ++i) {
            pairs += counting[i] / 2;
        }
        int remain = nums.size() - pairs * 2;
        return {pairs, remain};
    }
};