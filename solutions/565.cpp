class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == -1) continue;
            
            int curr = i;
            int cnt = 0;
            while (nums[curr] != -1) {
                int temp = curr;
                curr = nums[curr];
                nums[temp] = -1;
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};