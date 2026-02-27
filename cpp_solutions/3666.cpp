class Solution {
public:
    int minOperations(string s, int k) {
        long long ones = 0;
        long long zeros = 0;
        for (auto& c : s) {
            if (c == '0') zeros++;
            else ones++;
        }
        if (zeros == 0) return 0;
        for (int i = 1; i <= s.size(); ++i) {
            long long quota = i * k;
            long long valid = quota - zeros;
            if (valid & 1) continue;
            if (quota < zeros) continue;
            if (i & 1) {
                if (quota <= zeros * i + ones * (i - 1)) return i;
            }
            else {
                if (quota <= ones * i + zeros * (i - 1)) return i;
            }
        }
        return -1;
    }
};

