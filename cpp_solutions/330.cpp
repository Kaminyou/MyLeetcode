class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0;
        int count = 0;
        for (auto& num : nums) {
            while (sum + 1 < num) {
                count++;
                sum += (sum + 1);
                if (sum >= n) break;
            }
            sum += num;
            if (sum >= n) break;
        }
        while (sum < n) {
            count++;
            sum += (sum + 1);
        }
        return count;
    }
};