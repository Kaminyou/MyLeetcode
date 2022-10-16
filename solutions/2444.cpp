class Solution {
public:
    long long counting(long long n) {
        return n * (n + 1) / 2;
    }
    long long processing(vector<int>& nums, int start, int end, int minK, int maxK) {
        long long res = counting(end - start + 1);
        
        // no minK
        int right = start;
        while (right <= end) {
            if (nums[right] != minK) {
                int left = right;
                while (right + 1 <= end && nums[right + 1] != minK) right++;
                res -= counting(right - left + 1);   
            }
            right++;
        }
        
        // no maxK
        right = start;
        while (right <= end) {
            if (nums[right] != maxK) {
                int left = right;
                while (right + 1 <= end && nums[right + 1] != maxK) right++;
                res -= counting(right - left + 1);
            }
            right++;
        }
        
        // no minK and no maxK
        right = start;
        while (right <= end) {
            if (nums[right] != minK && nums[right] != maxK) {
                int left = right;
                while (right + 1 <= end && nums[right + 1] != minK && nums[right + 1] != maxK) right++;
                res += counting(right - left + 1);
            }
            right++;
        }
        return res;
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int index = 0;
        long long res = 0;
        while (index < n) {
            if (nums[index] <= maxK && nums[index] >= minK) {
                int start = index;
                while (index + 1 < n && nums[index + 1] <= maxK && nums[index + 1] >= minK) index++;
                // [start, index] is valid
                res += processing(nums, start, index, minK, maxK);
            }
            index++;
        }
        return res;
    }
};