class Solution {
public:
    long long createPalindrome(long long prefix, long long suffix) {
        while (suffix) {
            prefix = prefix * 10 + suffix % 10;
            suffix /= 10;
        }
        return prefix;
    }
    bool isParlindrome(long long num) {
        long long temp = num;
        long long rev = 0;
        while (num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev == temp;
    }
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        long long lSqrt = sqrt(l);
        long long rSqrt = sqrt(r);
        
        long long base = 1;
        long long num = 0;
        int res = 0;
        while (num < rSqrt) {
            num = createPalindrome(base, base);
            if (num >= lSqrt && num <= rSqrt && isParlindrome(num * num)) res++;
            num = createPalindrome(base, base / 10);
            if (num >= lSqrt && num <= rSqrt && isParlindrome(num * num)) res++;
            base++;
        }
        return res;
    }
};