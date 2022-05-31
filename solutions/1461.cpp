class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        int size = 1 << k;
        int count = 0;
        vector<bool> exist(size, false);
        for (int i = 0; i < s.size() - k + 1; ++i) {
            int curr = 0;
            int bit = k - 1;
            for (int j = i; j < i + k; ++j) {
                curr += ((s[j] - '0') << bit);
                bit--;
            }
            if (!exist[curr]) {
                exist[curr] = true;
                count++;
            }
            
            if (count == size) return true;
        }
        return count == size;
    }
};