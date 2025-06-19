class Solution {
public:
    int toKey(int a, int b) {
        return ((a & 1) << 1) | (b & 1);
    }
    int maxDifference(string s, int k) {
        int res = INT_MIN;
        int n = s.size();
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;
                int currA = 0, currB = 0;
                int prevA = 0, prevB = 0;
                vector<int> cache(4, INT_MAX);
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    currA += (s[right] == a);
                    currB += (s[right] == b);
                    while (right - left >= k && currB - prevB >= 2) {
                        cache[toKey(prevA, prevB)] = min(cache[toKey(prevA, prevB)], prevA - prevB);
                        left++;
                        prevA += (s[left] == a);
                        prevB += (s[left] == b);
                    }
                    int status = toKey(currA, currB);
                    int match = cache[status ^ 0b10];
                    if (match != INT_MAX) {
                        res = max(res, currA - currB - match);
                    }
                }
            }
        }
        return res;
    }
};

