class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int wordIdx = 0;
        int n = words.size();
        vector<string> res;
        
        while (wordIdx < n) {
            int start = wordIdx;
            int length = words[wordIdx].size() + 1;
            int lengthWord = words[wordIdx].size();
            while (wordIdx + 1 < n && length + words[wordIdx + 1].size() <= maxWidth) {
                wordIdx++;
                length += words[wordIdx].size();
                length += 1;
                lengthWord += words[wordIdx].size();
            }
            
            if (wordIdx == n - 1) {
                string temp = "";
                for (int i = start; i <= wordIdx; ++i) {
                    temp += words[i];
                    temp.push_back(' ');
                }
                if (temp.size() > maxWidth) temp.pop_back();
                else {
                    int empty = maxWidth - temp.size();
                    while (empty--) temp.push_back(' ');
                }
                res.push_back(temp);
            }
            else if (start == wordIdx) {
                string temp = words[wordIdx];
                int empty = maxWidth - words[wordIdx].size();
                while (empty--) temp.push_back(' ');
                res.push_back(temp);
            }
            else {
                int chunks = wordIdx - start;
                int empty = (maxWidth - lengthWord) / chunks;
                int remain = (maxWidth - lengthWord) % chunks;
                string temp = "";
                string emptyStr(empty, ' ');
                for (int i = start; i <= wordIdx; ++i) {
                    temp += words[i];
                    if (i == wordIdx) break;
                    temp += emptyStr;
                    if (remain) {
                        remain--;
                        temp.push_back(' ');
                    }
                }
                res.push_back(temp);
            }
            wordIdx++;
        }
        return res;
    }
};