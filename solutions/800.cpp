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