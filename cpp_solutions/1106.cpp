class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ops;
        stack<vector<int>> values;
        vector<int> nums;
        int res;

        int n = expression.size();
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (c == '!' || c == '&' || c == '|') {
                ops.push(c);
                values.push(nums);
                nums.clear();
                i++;
            }
            else if (c == ')') {
                char op = ops.top();
                ops.pop();
                res = eval(op, nums);
                nums = values.top();
                nums.push_back(res);
                values.pop();
            }
            else if (c == 't' || c == 'f') {
                nums.push_back(c == 't');
            }
        }
        return res;
    }

    int eval(char op, vector<int>& nums) {
        int res = 0;
        if (op == '!') return !nums[0];
        if (op == '&') {
            res = 1;
            for (auto& num : nums) res &= num;
            
        }
        else {
            res = 0;
            for (auto& num : nums) res |= num;
        }
        return res;
    }
};
