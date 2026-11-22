class Solution {
public:
    bool checkString(string s) {
        bool flag = true;
        for (auto& c : s) {
            if (c == 'a') {
                if (flag == false) return false;
            }
            else flag = false;
        }
        return true;
    }
};
