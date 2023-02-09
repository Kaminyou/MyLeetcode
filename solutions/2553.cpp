class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for (auto& num : nums) {
            vector<int> temp;
            while (num) {
                temp.push_back(num % 10);
                num /= 10;
            }
            reverse(temp.begin(), temp.end());
            for (auto& digit : temp) res.push_back(digit);
        }
        return res;
    }
};