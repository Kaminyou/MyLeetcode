class Solution {
public:
    bool isLower(char c) {
        return (c >= 'a' && c <= 'z');
    }
    bool isUpper(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
    int countRequired(string& s) {
        bool hasLower = false;
        bool hasUpper = false;
        bool hasDigit = false;
        for (auto c : s) {
            if (isLower(c)) hasLower = true;
            if (isUpper(c)) hasUpper = true;
            if (isDigit(c)) hasDigit = true;
        }
        
        return 3 - hasLower - hasUpper - hasDigit;
    }
    int strongPasswordChecker(string password) {
        int n = password.size();
        int required = countRequired(password);
        if (n < 6) return max(6 - n, required);
        
        int replace = 0;
        int one = 0;
        int two = 0;
        
        int index = 0;
        while (index < n) {
            char curr = password[index];
            int length = 1;
            while (index + 1 < n && password[index + 1] == curr) {
                length++;
                index++;
            }
            
            if (length >= 3) {
                replace += length / 3;
                if (length % 3 == 0) one++; // delete one save one replacement
                if (length % 3 == 1) two++; // delete two save one replacement
            }
            
            index++;
        }
        
        if (n <= 20) return max(replace, required);
        
        int toDeleteCount = n - 20;
        replace -= min(toDeleteCount, one);
        replace -= min(max(toDeleteCount - one, 0), two * 2) / 2;
        replace -= max(toDeleteCount - one - two * 2, 0) / 3;
        return toDeleteCount + max(required, replace);
    }
};