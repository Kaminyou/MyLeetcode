class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string temp;
        for (auto word : sentence) temp += (word + " ");
        int n = temp.size();
        int start = 0;
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (temp[start % n] == ' ') {
                start++;
            }
            else {
                while (start > 0 && temp[(start - 1) % n] != ' ') {
                    start--;
                }
            }
        }
        return start / n;
    }
};