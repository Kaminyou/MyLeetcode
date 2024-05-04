class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res;
        for (int i = 0; i <= n; ++i) res.push_back('0' + i + 1);
        
        int index = 0;
        while (index < n) {
            if (pattern[index] == 'I') {
                index++;
            }
            else {
                int start = index;
                while (index + 1 < n && pattern[index + 1] == 'D') {
                    index++;
                }
                int end = index;
                reverse(res.begin() + start, res.begin() + end + 2);
                
                index++;
            }
        }
        return res;
    }
};