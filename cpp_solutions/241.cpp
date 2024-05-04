class Solution {
public:
    int compute(int num1, int num2, char c) {
        if (c == '+') return num1 + num2;
        if (c == '-') return num1 - num2;
        return num1 * num2;
    }
    vector<int> backtracking(vector<int>& numbers, vector<char>& operators, int left, int right) {
        if (left == right) return {numbers[left]};
        if (right - left + 1 == 2) return {compute(numbers[left], numbers[right], operators[left])};
        vector<int> res;
        for (int i = left; i < right; ++i) {
            vector<int> leftV = backtracking(numbers, operators, left, i);
            vector<int> rightV = backtracking(numbers, operators, i + 1, right);
            for (auto& l : leftV) {
                for (auto& r : rightV) {
                    int result = compute(l, r, operators[i]);
                    res.push_back(result);
                }
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        vector<char> operators;
        int index = 0;
        while (index < expression.size()) {
            if (expression[index] != '+' && expression[index] != '-' && expression[index] != '*') {
                int start = index;
                while (index + 1 < expression.size() && expression[index + 1] != '+' && expression[index + 1] != '-' && expression[index + 1] != '*') {
                    index++;
                }
                int num = stoi(expression.substr(start, index - start + 1));
                numbers.push_back(num);
            }
            else operators.push_back(expression[index]);
            index++;
        }
        int n = numbers.size();
        return backtracking(numbers, operators, 0, n - 1);
    }
};