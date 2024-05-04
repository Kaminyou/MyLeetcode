class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool commentFlag = false;
        vector<string> res;
        string temp;
        for (auto& s : source) {
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                if (!commentFlag) {
                    if (s[i] == '/') {
                        if (i + 1 < n && s[i + 1] == '/') {
                            break;
                        }
                        else if (i + 1 < n && s[i + 1] == '*') {
                            commentFlag = true;
                            i++;
                            // case: /*/
                            if (i + 1 < n && s[i + 1] == '/') i++;
                        }
                    }
                    if (!commentFlag) temp.push_back(s[i]);
                }
                else {
                    if (s[i] == '/' && i > 0 && s[i - 1] == '*') commentFlag = false;
                }
            }
            if (!commentFlag && temp.size() != 0) {
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};