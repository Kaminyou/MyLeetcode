class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> out;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            carry += digits[i];
            out.push_back(carry % 10);
            carry /= 10;
        }
        if (carry) out.push_back(carry % 10);
        reverse(out.begin(), out.end());
        return out;
    }
};