class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        int count = 0;
        for (auto& num : nums) {
            if (num < pivot) smaller.push_back(num);
            else if (num > pivot) larger.push_back(num);
            else count++;
        }
        for (int i = 0; i < count; ++i) smaller.push_back(pivot);
        for (auto& num : larger) smaller.push_back(num);
        return smaller;
    }
};