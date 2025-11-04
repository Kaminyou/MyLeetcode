class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        map<int, set<int, std::greater<int>>, std::greater<int>> freq2nums; // {freq: num}
        unordered_map<int, int> num2freq; // {num: freq}
        int left = 0;
        int n = nums.size();
        vector<int> res;
        for (int right = 0; right < n; ++right) {
            int num = nums[right];
            int prevFreq = num2freq[num];
            int nowFreq = prevFreq + 1;
            num2freq[num] = nowFreq;
            if (freq2nums[prevFreq].count(num)) {
                freq2nums[prevFreq].erase(num);
            }
            freq2nums[nowFreq].insert(num);
            if (right - left + 1 > k) {
                // remove left
                int num = nums[left];
                int prevFreq = num2freq[num];
                int nowFreq = prevFreq - 1;
                num2freq[num] = nowFreq;
                if (freq2nums[prevFreq].count(num)) {
                    freq2nums[prevFreq].erase(num);
                }
                freq2nums[nowFreq].insert(num);
                left++;
            }
            if (right - left + 1 == k) {
                int index = 0;
                int _res = 0;
                bool finish = false;
                for (auto& [k, vs] : freq2nums) {
                    for (auto& v : vs) {
                        _res += v * k;
                        index++;
                        if (index >= x) finish = true;
                        if (finish) break;
                    }
                    if (finish) break;
                }
                res.push_back(_res);
            }
        }
        return res;
    }
};
