class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool negative = false;
        if ((long long)numerator * (long long)denominator < 0) negative = true;
        long long LLnumerator = abs((long long)numerator);
        long long LLdenominator = abs((long long)denominator);
        
        // deal with dec
        long long dec = LLnumerator / LLdenominator;
        long long remain = LLnumerator % LLdenominator;
        if (remain == 0) {
            if (negative) return "-" + to_string(dec);
            return to_string(dec);
        }
        
        // deal with frac
        unordered_map<long long, int> hash;
        string frac = "";
        bool isRepeat = true;
        int repeatStart = -1;
        for (int i = 0; i < 10000; ++i) {
            remain *= 10;
            
            long long _frac = remain / LLdenominator;
            remain = remain % LLdenominator;
            
            frac += to_string(_frac);
            if (hash.find(remain) != hash.end()) {
                repeatStart = hash[remain];
                break;
            }
            if (remain == 0) {
                isRepeat = false;
                break;
            }
            hash[remain] = i;
        }
        if (isRepeat) {
            string res = to_string(dec);
            res.push_back('.');
            for (int i = 0; i <= repeatStart; i++) {
                res.push_back(frac[i]);
            }
            res.push_back('(');
            for (int i = repeatStart + 1; i < frac.size(); i++) {
                res.push_back(frac[i]);
            }
            res.push_back(')');
            if (negative) return "-" + res;
            return res;
        }
        if (negative) return "-" + to_string(dec) + "." + frac;
        return to_string(dec) + "." + frac;
    }
};

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        unordered_map<long long, int> reminder2index;
        string res;
        int index = 0;
        if (numerator * denominator < 0) {
            res.push_back('-');
            index++;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        bool flag = false;
        long long repeat = -1;
        while (true) {
            long long a = numerator / denominator;
            long long b = numerator % denominator;
            string aa = to_string(a);
            res += aa;
            if (b == 0) break;
            numerator = b * 10;
            if (reminder2index.count(numerator)) {
                repeat = numerator;
                break;
            }
            if (!flag) {
                flag = true;
                res.push_back('.');
                index++;
            }
            index += aa.size();
            reminder2index[numerator] = index;
        }
        if (repeat > -1) {
            int start = reminder2index[repeat];
            res = res.substr(0, start) + "(" + res.substr(start) + ")";
        }
        return res;
    }
};

