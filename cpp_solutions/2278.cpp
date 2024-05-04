class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (auto c : s) {
            if (c == letter) count++;
        }
        int ans = count * 100 / s.size();
        return ans;
    }
};