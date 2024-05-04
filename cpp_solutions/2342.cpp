class Solution {
public:
    int num2digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (auto& num : nums) {
            mp[num2digitSum(num)].push_back(num);
        }
        
        for (auto& element : mp) {
            sort(element.second.begin(), element.second.end(), greater<int>());
        }
        
        int res = -1;
        for (auto& element : mp) {
            if (element.second.size() == 1) continue;
            int first = element.second[0];
            int second = element.second[1];
            res = max(res, first + second);
        }
        return res;
    }
};