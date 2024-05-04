class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> numsOdd;
        vector<int> numsEven;
        vector<int> targetOdd;
        vector<int> targetEven;
        for (auto& num : nums) {
            if (num & 1) numsOdd.push_back(num);
            else numsEven.push_back(num);
        }
        for (auto& num : target) {
            if (num & 1) targetOdd.push_back(num);
            else targetEven.push_back(num);
        }
        long long res = 0;
        int n = numsOdd.size();
        for (int i = 0; i < n; ++i) {
            if (numsOdd[i] < targetOdd[i]) continue;
            res += (numsOdd[i] - targetOdd[i]) / 2;
        }
        n = numsEven.size();
        for (int i = 0; i < n; ++i) {
            if (numsEven[i] < targetEven[i]) continue;
            res += (numsEven[i] - targetEven[i]) / 2;
        }
        return res;
    }
};
