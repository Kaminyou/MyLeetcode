class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int bits = 0;
        while (n) {
            bits++;
            n >>= 1;
        }
        return 1 << bits;
    }
};

