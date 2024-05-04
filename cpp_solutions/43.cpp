class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> cache(n + m, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int index = i + j;
                while (mul) {
                    cache[index] += mul % 10;
                    mul /= 10;
                    index++;
                }
            }
        }
        for (int i = 0; i < cache.size(); ++i) {
            if (cache[i] >= 10) {
                cache[i + 1] += cache[i] / 10;
                cache[i] = cache[i] % 10;
            }
        }
        
        string res;
        int end = cache.size() - 1;
        while (end >= 0 && cache[end] == 0) end--;
        if (end == -1) return "0";
        for (int i = 0; i <= end; i++) res.push_back(cache[i] + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};