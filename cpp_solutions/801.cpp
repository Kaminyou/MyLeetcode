class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int currentNoSwap = 0;
        int currentSwap = 1;
        int n = nums1.size();
        for (int i = 1; i < n; ++i) {
            int nextNoSwap = INT_MAX;
            int nextSwap = INT_MAX;
            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                nextNoSwap = currentNoSwap;
                nextSwap = currentSwap + 1;
            }
            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                nextNoSwap = min(nextNoSwap, currentSwap);
                nextSwap = min(nextSwap, currentNoSwap + 1);
            }
            currentNoSwap = nextNoSwap;
            currentSwap = nextSwap;
        }
        return min(currentNoSwap, currentSwap);
    }
};

