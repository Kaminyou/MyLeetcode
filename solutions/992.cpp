class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostWithKDistinct(nums, k) - atMostWithKDistinct(nums, k - 1);
    }
    int atMostWithKDistinct(vector<int>& nums, int k){
        int res = 0;   
        int left = 0;
        int right = 0;
        unordered_map<int, int> count_map;
        while (right < nums.size()){
            if (count_map[nums[right]] == 0) k--;
            count_map[nums[right]]++;
            right++;
            while (k < 0){
                count_map[nums[left]]--;
                if (count_map[nums[left]] == 0) k++;
                left++;
            }
            res += right - left + 1;
        }

        return res;
    }
};
