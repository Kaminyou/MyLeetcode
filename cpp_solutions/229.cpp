class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
        for (auto num : nums) {
            if (num == element1) {
                count1++;
            }
            else if (num == element2) {
                count2++;
            }
            else if (count1 == 0) {
                element1 = num;
                count1++;
            }
            else if (count2 == 0) {
                element2 = num;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for (auto num : nums) {
            if (num == element1) count1++;
            if (num == element2) count2++;
        }
        vector<int> res;
        if (count1 > nums.size() / 3) res.push_back(element1);
        if (count2 > nums.size() / 3) res.push_back(element2);
        return res;
    }
};