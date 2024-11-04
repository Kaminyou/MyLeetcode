class Solution {
public:
    string compressedString(string word) {
        string res;
        char curr = 'Z';
        int cnt = 0;
        for (auto& c : word) {
            if (curr == c && cnt < 9) {
                cnt++;
            }
            else {
                if (cnt > 0) {
                    res.push_back(cnt + '0');
                    res.push_back(curr);
                }
                cnt = 1;
                curr = c;
            }
        }
        if (cnt > 0) {
            res.push_back(cnt + '0');
            res.push_back(curr);
        }
        return res;
    }
};
