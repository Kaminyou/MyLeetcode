class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> availableXO;
        availableXO.insert(0);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                availableXO.insert(nums[i] ^ nums[j]);
            }
        }
        int res = 0;
        for (int a = 0; a <= 2048; ++a) {
            for (auto b : nums) {
                int x = a ^ b;
                if (availableXO.count(x)) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

