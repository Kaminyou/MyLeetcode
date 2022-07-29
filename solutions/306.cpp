class Solution {
public:
    bool backtracking(string& num, int currIdx, long long first, long long second, int count) {
        if (currIdx == num.size() && count >= 3) {
            return true;
        }
        for (int i = 1; currIdx + i <= num.size() && i < 18; ++i) {
            string currStr = num.substr(currIdx, i);
            if (currStr.size() > 1 && currStr[0] == '0') break;
            long long curr = stoll(currStr);
            if (first != -1 && second != -1) {
                if (first + second == curr) {
                    if (backtracking(num, currIdx + i, second, curr, count + 1)) return true;
                }
            }
            else if (first == -1 && second != -1) {
                if (backtracking(num, currIdx + i, second, curr, count + 1)) return true;;
            }
            else {
                if (backtracking(num, currIdx + i, -1, curr, count + 1)) return true;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return backtracking(num, 0, -1, -1, 0);
    }
};