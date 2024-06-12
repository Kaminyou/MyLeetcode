class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (auto num : nums) cnt[num] += 1;
        int index = 0;
        for (int i = 0; i < 3; ++i) {
            while (cnt[i]) {
                nums[index] = i;
                index++;
                cnt[i]--; 
            }
        }
    }
};
