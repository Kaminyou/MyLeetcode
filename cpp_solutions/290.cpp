class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;
        int n = pattern.size();
        int index = 0;
        string temp;
        stringstream ss(s);
        while (getline(ss, temp, ' ')) {
            if (index == n) return false;
            int c = pattern[index];
            if (c2w.count(c) == 0 && w2c.count(temp) == 0) {
                c2w[c] = temp;
                w2c[temp] = c;
            }
            else if (c2w.count(c) != 0 && w2c.count(temp) == 0) {
                return false;
            }
            else if (c2w.count(c) == 0 && w2c.count(temp) != 0) {
                return false;
            }
            else {
                string targetWord = c2w[c];
                int targetC = w2c[temp];
                if (targetWord != temp || targetC != c) return false;
            }
            index++;
        }
        return index == n;
    }
};