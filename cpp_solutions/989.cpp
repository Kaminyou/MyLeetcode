class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> kNum;
        while (k) {
            kNum.push_back(k % 10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        int numIdx = 0;
        int kNumIdx = 0;
        int carry = 0;
        vector<int> res;
        while (numIdx < num.size() && kNumIdx < kNum.size()) {
            carry = carry + kNum[kNumIdx] + num[numIdx];
            res.push_back(carry % 10);
            carry /= 10;
            kNumIdx++;
            numIdx++;
        }
        while (numIdx < num.size()) {
            carry = carry + num[numIdx];
            res.push_back(carry % 10);
            carry /= 10;
            numIdx++;
        }
        while (kNumIdx < kNum.size()) {
            carry = carry + kNum[kNumIdx];
            res.push_back(carry % 10);
            carry /= 10;
            kNumIdx++;
        }
        if (carry) {
            res.push_back(carry % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// v2
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> kNum;
        while (k) {
            kNum.push_back(k % 10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        int numIdx = 0;
        int kNumIdx = 0;
        int carry = 0;
        vector<int> res;
        while (numIdx < num.size() || kNumIdx < kNum.size()) {
            if (numIdx < num.size()) {
                carry += num[numIdx];
                numIdx++;
            }
            if (kNumIdx < kNum.size()) {
                carry += kNum[kNumIdx];
                kNumIdx++;
            }
            res.push_back(carry % 10);
            carry /= 10;
        }
        while (carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};