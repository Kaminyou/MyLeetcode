class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        if (n >= 8 && n <= 11) return 11;
        for (int i = 1; i < 100000; ++i) {
            string s = to_string(i);
            string r(s.rbegin(), s.rend());
            string temp = s + r.substr(1);
            int num = stoi(temp);
            if (num >= n && isPrime(num)) return num;
        }
        return -1;
    }
};