class Solution {
public:
    int numOfDigits(int num) {
        int cnt = 0;
        while (num) {
            cnt += 1;
            num /= 10;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto& num : nums) {
            if (numOfDigits(num) & 1) continue;
            res++;
        }
        return res;
    }
};
