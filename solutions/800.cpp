class Solution {
public:
    string helper(string str) {
        string dict = "0123456789abcdef";
        int value = stoi(str, nullptr, 16);
        int index = value / 17 + (value % 17 > 8 ? 1 : 0);
        return string(2, dict[index]);
    }
    string similarRGB(string color) {
        return "#" + helper(color.substr(1, 2)) + helper(color.substr(3, 2)) + helper(color.substr(5, 2));
    }
};

class Solution {
public:
    string hexstring = "0123456789abcdef";
    unordered_map<char, int> hexChar2int;
    int hex2int(char c1, char c2) {
        return hexChar2int[c1] * 16 + hexChar2int[c2];
    }
    string getSimilar(string s) {
        int target = hex2int(s[0], s[1]);
        int diff = INT_MAX;
        char res;
        for (auto c : hexstring) {
            int current = hex2int(c, c);
            if (abs(current - target) < diff) {
                diff = abs(current - target);
                res = c;
            }
        }
        return string(2, res);
    }
    string similarRGB(string color) {
        for (int i = 0; i < 16; ++i) {
            hexChar2int[hexstring[i]] = i;
        }
        return "#" + getSimilar(color.substr(1, 2)) + getSimilar(color.substr(3, 2)) + getSimilar(color.substr(5, 2));
    }
};