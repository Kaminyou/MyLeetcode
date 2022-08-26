class Solution {
public:
    string encodeNum(int n) {
        vector<long long> counts(10, 0);
        while (n) {
            int digit = n % 10;
            n /= 10;
            counts[digit]++;
        }
        string res;
        for (int i = 0; i < 9; ++i) {
            res.push_back(counts[i] + '0');
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        long long start = 1;
        unordered_set<string> st;
        while (start <= INT_MAX / 2) {
            st.insert(encodeNum(start));
            start *= 2;
        }
        return st.find(encodeNum(n)) != st.end();
        
    }
};