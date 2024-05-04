class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> cnt;
        int maxCnt = 0;
        int index = 0;
        int n = paragraph.size();
        while (index < n) {
            if (!isalpha(paragraph[index])) {
                index++;
                continue;
            }
            int start = index;
            if (isupper(paragraph[start])) paragraph[start] = paragraph[start] - 'A' + 'a';
            while (index + 1 < n && isalpha(paragraph[index + 1])) {
                if (isupper(paragraph[index + 1])) paragraph[index + 1] = paragraph[index + 1] - 'A' + 'a';
                index++;
            }
            string temp = paragraph.substr(start, index - start + 1);
            if (st.find(temp) == st.end()) {
                cnt[temp]++;
                maxCnt = max(maxCnt, cnt[temp]);
            }
            index++;
        }
        for (auto& element : cnt) {
            if (element.second == maxCnt) return element.first;
        }
        return "";
    }
};