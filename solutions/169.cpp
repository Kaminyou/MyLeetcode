class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        
        for (auto num : nums) {
            if (count == 0) {
                element = num;
            }
            count += (element == num) ? 1 : -1;
        }
        return element;
    }
};