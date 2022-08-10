class Solution {
public:
    bool isNumber(char c) {
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isHex(char c) {
        if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) return true;
        return false;
    }
    string validIPAddress(string queryIP) {
        int dotCnt = 0;
        int colonCnt = 0;
        int numberCnt = 0;
        int hexCnt = 0;
        for (auto c : queryIP) {
            if (c == '.') dotCnt++;
            else if (c == ':') colonCnt++;
            else if (isNumber(c)) numberCnt++;
            else if (isHex(c)) hexCnt++;
            else return "Neither";
        }
        
        if (dotCnt > 0 && colonCnt > 0) return "Neither";
        
        if (dotCnt > 0) {
            if (dotCnt != 3) return "Neither";
            if (hexCnt) return "Neither";
            stringstream ss(queryIP);
            string token;
            if (queryIP.back() == '.') return "Neither";
            while (getline(ss, token, '.')) {
                if (token.size() == 0 || token.size() > 4) return "Neither";
                int num = stoi(token);
                if (num == 0 && token.size() > 1) return "Neither";
                if (num < 0 || num > 255) return "Neither";
                if (to_string(num).size() != token.size()) return "Neither";
            }
            return "IPv4";
        }
        
        if (colonCnt > 0) {
            if (queryIP.back() == ':') return "Neither";
            if (colonCnt != 7) return "Neither";
            stringstream ss(queryIP);
            string token;
            while (getline(ss, token, ':')) {
                if (token.size() == 0) return "Neither";
                if (token.size() > 4) return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};