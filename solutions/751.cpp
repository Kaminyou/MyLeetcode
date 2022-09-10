class Solution {
public:
    unsigned long long ip2ll(string& ip) {
        stringstream ss(ip);
        string token;
        unsigned long long res;
        while (getline(ss, token, '.')) {
            res *= 256;
            res += stoll(token);
        }
        return res;
    }
    string ll2ip(unsigned long long ip) {
        return to_string((ip >> 24) & 255UL) + "." + to_string((ip >> 16) & 255UL) + "." + to_string((ip >> 8) & 255UL) + "." + to_string((ip >> 0) & 255UL);
    }
    unsigned long long getMaskSize(unsigned long long begin, unsigned long long end) {
        unsigned long long maskLength = 0;
        unsigned long long mask = 1;
        for (;(begin | mask) <= end && (begin & (~mask)) >= begin && maskLength < 32; ++maskLength) {
            mask = (mask << 1) | 1;
        }
        return maskLength;
    }
    
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        unsigned long long begin = ip2ll(ip);
        unsigned long long end = begin + n - 1;
        while (begin <= end) {
            unsigned long long maskLength = getMaskSize(begin, end);
            res.push_back(ll2ip(begin) + "/" + to_string(32 - maskLength));
            begin = begin + (1 << maskLength);
        }
        return res;
    }
};