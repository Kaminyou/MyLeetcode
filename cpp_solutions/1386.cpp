class Solution {
public:
    // 2345 4567 6789
    // 2345 + 6789
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count = 0;
        unordered_map<int, int> masks;
        for (auto& reservedSeat : reservedSeats) {
            masks[reservedSeat[0] - 1] |= (1 << (reservedSeat[1] - 1));
        }
        vector<int> oneMask = {0b0111100000, 0b0000011110, 0b0001111000};
        for (auto& [idx, mask] : masks) {
            if ((mask & 0b0111111110) == 0) count += 2;
            else {
                for (auto& state : oneMask) {
                    if ((mask & state) == 0) {
                        count += 1;
                        break;
                    }
                }
            }
        }
        count += 2 * (n - masks.size());
        return count;
    }
};