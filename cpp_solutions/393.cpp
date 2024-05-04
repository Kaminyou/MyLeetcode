class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for (auto num : data) {
            if (count == 0) {
                if ((num >> 5) == 0b110) count = 1;
                else if ((num >> 4) == 0b1110) count = 2;
                else if ((num >> 3) == 0b11110) count = 3;
                else if ((num >> 7)) return false;
            }
            else {
                if ((num >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};