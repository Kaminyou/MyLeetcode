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