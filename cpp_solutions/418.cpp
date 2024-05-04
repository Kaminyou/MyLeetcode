class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string temp;
        for (auto word : sentence) temp += (word + " ");
        int n = temp.size();
        int start = 0;
        for (int i = 0; i < rows; ++i) {
            // every time, start points to the first letter
            // xxxxx_xxx_xxx
            // ^
            start += cols;
            // plus cols -> point to the "next" row's header
            // [xxxxx_xx]x_xxx
            //           ^
            
            // three conditions:
            //  (a)        (b)       (c)
            // xxx_xxx   xxx_xxx   xxx_xxx
            //    ^          ^          ^
            // should become
            // xxx_xxx   xxx_xxx   xxx_xxx
            //     ^      same         ^
            
            // (a)
            if (temp[start % n] == ' ') {
                start++;
            }
            // (c)  cause condition (b) will not go into while loop
            else {
                while (start > 0 && temp[(start - 1) % n] != ' ') {
                    start--;
                }
            }
        }
        // cuase next position is the actual length
        return start / n;
    }
};