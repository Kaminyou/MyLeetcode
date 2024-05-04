class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};
// class Solution {
// public:
//     string toBase(int n, int base) {
//         string res;
//         while (n) {
//             int remain = n % base;
//             n /= base;
//             res.push_back('0' + remain);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
//     bool isPalindromic(string& s) {
//         int left = 0;
//         int right = s.size() - 1;
//         while (left < right) {
//             if (s[left] != s[right]) return false;
//             left++;
//             right--;
//         }
//         return true;
//     }
//     bool isStrictlyPalindromic(int n) {
//         int end = n - 2;
//         for (int base = 2; base <= end; ++base) {
//             string res = toBase(n, base);
//             if (!isPalindromic(res)) return false;
//         }
//         return true;
//     }
// };