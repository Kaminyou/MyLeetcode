class Solution {
public:
    int addMinimum(string word) {
        char prev = 'z';
        int k = 0;
        int n = word.size();
        int index = 0;
        while (index < n) {
            if (word[index] <= prev) {
                k++;
            }
            prev = word[index];
            index++;
        }
        return k * 3 - n;
    }
};