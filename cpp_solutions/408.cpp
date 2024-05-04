class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int indexWord = 0;
        int indexAbbr = 0;
        int n = abbr.size();
        while (indexAbbr < n) {
            if (indexWord >= word.size()) return false;
            if (abbr[indexAbbr] >= '0' && abbr[indexAbbr] <= '9') {
                int start = indexAbbr;
                while (indexAbbr + 1 < n && abbr[indexAbbr + 1] >= '0' && abbr[indexAbbr + 1] <= '9') indexAbbr++;
                if (abbr[start] == '0') return false;
                int jump = stoi(abbr.substr(start, indexAbbr - start + 1));
                indexWord += jump;
            }
            else {
                if (!(abbr[indexAbbr] == word[indexWord])) return false;
                indexWord++;
            }
            indexAbbr++;
        }
        return indexWord == word.size();
    }
};