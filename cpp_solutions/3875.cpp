class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCnt = 0;
        int evenCnt = 0;
        for (auto& num : nums1) {
            if (num & 1) oddCnt++;
            else evenCnt++;
        }
        // all odd
        bool flag = true;
        for (auto& num : nums1) {
            if (!(num & 1)) {
                if (oddCnt == 0) {
                    flag =false;
                    break;
                }
            }
        }
        if (flag) return true;

        // all even
        flag = true;
        for (auto& num : nums1) {
            if (num & 1) {
                if (oddCnt == 0) {
                    flag =false;
                    break;
                }
            }
        }
        return flag;
    }
};

