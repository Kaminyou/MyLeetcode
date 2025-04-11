class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; ++i) cnt += isSymmetric(i);
        return cnt;
    }
    bool isSymmetric(int num) {
        int prev = 0;
        int last = 0;
        string n = to_string(num);
        int s = n.size();
        if (s & 1) return false;
        for (int i = 0; i < s / 2; ++i) prev += n[i] - '0';
        for (int i = s / 2; i < s; ++i) last += n[i] - '0';
        return prev == last;
    }
};
