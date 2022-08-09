class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            int j = i;
            int k = getNext(j, nums);
            while (nums[j] * nums[k] > 0 && nums[j] * nums[getNext(k, nums)] > 0) {
                if (j == k) {
                    if (getNext(j, nums) == j) break;
                    return true;
                }
                j = getNext(j, nums);
                k = getNext(getNext(k, nums), nums);
            }
            j = i;
            while (nums[j] * nums[i] > 0) {
                nums[j] = 0;
                j = getNext(j, nums);
            }
        }
        return false;
    }
    int getNext(int current, vector<int>& nums) {
        int n = nums.size();
        return (current + nums[current] >= 0) ? (current + nums[current]) % n : n + ((current + nums[current]) % n);
    }
};