class Solution {
public:
    int minLength(string s) {
        bool find = false;
        while (true) {
            int index = s.find("AB");
            if (index != string::npos) {
                s = s.substr(0, index) + s.substr(index + 2);
                continue;
            }
            index = s.find("CD");
            if (index != string::npos) {
                s = s.substr(0, index) + s.substr(index + 2);
                continue;
            }
            break;
        }
        return s.size();
    }
};