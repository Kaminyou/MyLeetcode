class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        string res;
        
        bool flag = true;
        while (flag) {
            char c = strs[0][index];
            for (auto& str : strs) {
                if (str.size() <= index) {
                    flag = false;
                    break;
                }
                if (str[index] != c) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(c);
            index++;
        }
        return res;
    }
};