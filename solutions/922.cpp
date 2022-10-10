class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenNext = 0;
        int oddNext = 0;
        
        int n = nums.size();
        for (int i = 0; i < nums.size(); i ++) {
            if (i & 1 && !(nums[i] & 1)) {
                // find odd
                oddNext = max(oddNext, i + 1);
                for (int j = oddNext + 1; j < n; ++j) {
                    if (nums[j] & 1) {
                        oddNext = j;
                        break;
                    }
                }
                swap(nums[i], nums[oddNext]);
            }
            else if (!(i & 1) && (nums[i] & 1)) {
                // find even
                evenNext = max(evenNext, i + 1);
                for (int j = evenNext + 1; j < n; ++j) {
                    if ((nums[j] & 1) == 0) {
                        evenNext = j;
                        break;
                    }
                }
                swap(nums[i], nums[evenNext]);
            }
        }
        return nums;
    }
};