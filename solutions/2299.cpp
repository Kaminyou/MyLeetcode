class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        // 8
        if (password.size() < 8) return false;
        unordered_set<char> hash;
        string specials = "!@#$%^&*()-+";
        for (auto& c : specials) hash.insert(c);
        // one lowercase, uppercase, digit, special
        bool lowercase = false;
        bool uppercase = false;
        bool digit = false;
        bool special = false;
        for (auto& c : password) {
            if ('a' <= c && c <= 'z') lowercase = true;
            if ('A' <= c && c <= 'Z') uppercase = true;
            if ('0' <= c && c <= '9') digit = true;
            if (hash.find(c) != hash.end()) special = true;
        }
        if (!lowercase || !uppercase || !digit || !special) return false;
        // conse
        for (int i = 0; i < password.size() - 1; ++i) {
            if (password[i] == password[i + 1]) return false;
        }
        return true;
    }
};