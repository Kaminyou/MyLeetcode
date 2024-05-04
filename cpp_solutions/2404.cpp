class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> hash(100001, 0);
        for (auto& num : nums) {
            if ((num % 2) == 0) hash[num]++;
        }
        int res = -1;
        int freq = 0;
        for (int i = 0; i <= 100000; ++i) {
            if (hash[i] > 0) {
                if (hash[i] > freq) {
                    freq = hash[i];
                    res = i;
                }
            }
        }
        return res;
    }
};