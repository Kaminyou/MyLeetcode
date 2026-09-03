class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = INT_MAX;
        bool hasOdd = false;
        bool hasEven = false;
        for (auto& num : nums1) {
            minVal = min(num, minVal);
            if (num & 1) hasOdd = true;
            else hasEven = true;
        }

        if (!hasOdd) return true;
        if (!hasEven) return true;
        if (minVal & 1) return true;
        return false;
    }
};
