class Solution {
public:
    int compress(vector<char>& chars) {
        int res = 0;
        int n = chars.size();
        int index = 0;
        int charIdx = 0;
        while (index < n) {
            char c = chars[index];
            int start = index;
            while (index + 1 < n && chars[start] == chars[index + 1]) index++;
            int count = index - start + 1;
            if (count == 1) {
                chars[charIdx++] = c;
                res += 1;
            }
            else {
                chars[charIdx++] = c;
                res += 1;
                string temp = to_string(count);
                res += temp.size();
                for (auto k : temp) {
                    chars[charIdx++] = k;
                }
            }
            index++;
        }
        return res;
    }
};