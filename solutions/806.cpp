class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int current = 0;
        int count = 1;
        int index = 0;
        while (index < s.size()) {
            int width = widths[s[index] - 'a'];
            if (current + width <= 100) {
                current += width;
            }
            else {
                current = width;
                count++;
            }
            index++;
        }
        return {count, current};
    }
};