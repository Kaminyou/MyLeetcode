class Solution {
public:
    string largestGoodInteger(string num) {
        int resVal = -1;
        int index = 0;
        int n = num.size();
        while (index < n) {
            char curr = num[index];
            int start = index;
            while (index + 1 < n && num[index + 1] == curr) {
                index++;
            }
            int length = index - start + 1;
            if (length >= 3) {
                if (curr > resVal) {
                    resVal = curr;
                }
            }
            index++;
        }
        if (resVal == -1) return "";
        char c = (char)(resVal);
        string res = string(3, c);
        return res;
    }
};