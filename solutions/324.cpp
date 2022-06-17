class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> counts(50001, 0);
        for (auto& num : nums) counts[num]++;
        int index;
        if (nums.size() & 1) index = nums.size() - 1;
        else index = nums.size() - 2;
        for (int i = 0; i < 50001; ++i) {
            while (counts[i]) {
                counts[i]--;
                nums[index] = i;
                index -= 2;
                if (index < 0) {
                    if (nums.size() & 1) index = nums.size() - 2;
                    else index = nums.size() - 1;
                }
            }
        }
    }
};