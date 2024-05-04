class Solution {
public:
    int getLsm(int a, int b) {
        return a * b / __gcd(a, b);
    }
    pair<int, int> parseFraction(string& fraction) {
        int currentNumerator = -1;
        int currentDenominator = -1;
        string token;
        stringstream ss(fraction);
        while (getline(ss, token, '/')) {
            if (currentNumerator == -1) currentNumerator = stoi(token);
            else currentDenominator = stoi(token);
        }
        return make_pair(currentNumerator, currentDenominator);
    }
    pair<int, int> add(pair<int, int>& prev, pair<int, int>& next) {
        if (prev.second == -1) return next;
        int prevNumerator = prev.first;
        int prevDenominator = prev.second;
        int nextNumerator = next.first;
        int nextDenominator = next.second;
        int lsm = getLsm(prevDenominator, nextDenominator);
        int prevNumeratorLsm = prevNumerator * lsm / prevDenominator;
        int nextNumeratorLsm = nextNumerator * lsm / nextDenominator;
        int numeratorLsm = prevNumeratorLsm + nextNumeratorLsm;
        return {numeratorLsm, lsm};
    }
    void reduce(pair<int, int>& fraction) {
        int gcd = __gcd(abs(fraction.first), fraction.second);
        fraction.first = fraction.first / gcd;
        fraction.second = fraction.second / gcd;
    }
    string fractionAddition(string expression) {
        if (expression[0] != '-') expression = "+" + expression;
        vector<string> fractions;
        pair<int, int> current = {-1, -1};
        int index = 0;
        int n = expression.size();
        while (index < n) {
            if (expression[index] == '+') {
                index++;
                int start = index;
                while (index + 1< n && expression[index + 1] != '+' && expression[index + 1] != '-') {
                    index++;
                }
                // [start, index]
                string fraction = expression.substr(start, index - start + 1);
                pair<int, int> fractionNums = parseFraction(fraction);
                current = add(current, fractionNums);
                index++;
            }
            else {
                index++;
                int start = index;
                while (index + 1< n && expression[index + 1] != '+' && expression[index + 1] != '-') {
                    index++;
                }
                // [start, index]
                string fraction = expression.substr(start, index - start + 1);
                pair<int, int> fractionNums = parseFraction(fraction);
                fractionNums.first = -fractionNums.first;
                current = add(current, fractionNums);
                index++;
            }
        }
        if (current.first == 0) return "0/1";
        reduce(current);
        string res;
        res += to_string(current.first);
        res += "/";
        res += to_string(current.second);
        return res;
    }
};
