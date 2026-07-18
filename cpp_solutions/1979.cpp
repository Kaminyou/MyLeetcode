class Solution {
public:
    int findGCD(vector<int>& nums) {
        int b = INT_MIN;
        int s = INT_MAX;
        for (auto& num : nums) {
            b = max(b, num);
            s = min(s, num);
        }
        return __gcd(b, s);
    }
};
