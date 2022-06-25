class Solution {
public:
    // m + n => odd => find (m + n + 1) / 2 
    // m + n => even => find (m + n) / 2 + (m + n) / 2 + 1

    int binarySeaerch(int target, int l, int r, vector<int>& nums1, vector<int>& nums2) {
        // num at target th bounded by l (num) and r (num)
        int left = l;
        int right = r;
        int num = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int lower = 0;
            int higher = 0;
            lower += distance(nums1.begin(), lower_bound(nums1.begin(), nums1.end(), mid));
            lower += distance(nums2.begin(), lower_bound(nums2.begin(), nums2.end(), mid));
            higher += distance(nums1.begin(), upper_bound(nums1.begin(), nums1.end(), mid));
            higher += distance(nums2.begin(), upper_bound(nums2.begin(), nums2.end(), mid));
            if (target > lower && target <= higher) {
                num = mid;
                break;
            }
            if (lower >= target) right = mid;
            else left = mid + 1;
        }
        return num;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int target;
        if ((m + n) & 1) target = (m + n + 1) /2;
        else target = (m + n) / 2;
        
        int l = INT_MAX, r = INT_MIN;
        if (nums1.size() > 0) {
            l = min(l, nums1[0]);
            r = max(r, nums1[nums1.size() - 1]);
        }
        if (nums2.size() > 0) {
            l = min(l, nums2[0]);
            r = max(r, nums2[nums2.size() - 1]);
        }
        if (l == r) return (double)l;
        
        // what is the number at target
        int num1 = binarySeaerch(target, l, r, nums1, nums2);
        if (((m + n) & 1) == 0) {
            int num2 = binarySeaerch(target + 1, l, r, nums1, nums2);
            return ((double)num1 + (double)num2) / 2;
        }
        return (double)num1;
    }
};