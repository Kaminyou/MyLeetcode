class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        long long res = 0;
        while (right >= left) {
            if (right > left) {
                string l = to_string(nums[left]);
                string r = to_string(nums[right]);
                string combine = l + r;
                long long temp = stoll(combine);
                res += temp;
            }
            else if (right == left) {
                res += nums[left];
            }
            left++;
            right--;
        }
        return res;
    }
};