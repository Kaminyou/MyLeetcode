class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        int m = prev.size();
        int index = 0;
        string res = "";
        while (index < m) {
            int start = index;
            char c = prev[index];
            while (index + 1 < m && prev[index + 1] == c) index++;
            int cnt = index - start + 1;
            res += to_string(cnt);
            res.push_back(c);
            index++;
        }
        return res;
    }
};