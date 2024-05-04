class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int index = 0;
        while (index + 1 < n) {
            if (bits[index] == 1) {
                index += 2;
            }
            else {
                index += 1;
            }
        }
        return index != n;
    }
};
