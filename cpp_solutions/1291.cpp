class Solution {
public:
    vector<int> available;
    void generate(int now) {
        int lastDigit = now % 10;
        available.push_back(now);
        if (lastDigit == 9) return;
        generate(now * 10 + lastDigit + 1);
    }
    vector<int> sequentialDigits(int low, int high) {
        for (int num = 1; num < 10; ++num) {
            generate(num);
        }
        vector<int> res;
        for (auto num : available) {
            if (num >= low & num <= high) res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
