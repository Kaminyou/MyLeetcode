class Solution {
public:
    // concept:
    // if there are [16, 17, 71, 62, 12, 24, 14]
    // covert them to bit presentation
    // 16: 0000000000010000
    // 17: 0000000000010001
    // 71: 0000000001000111
    // 62: 0000000000111110
    // 12: 0000000000001100
    // 24: 0000000000011000
    // 14: 0000000000001110
    // count bits in each position
    // =>  0000000001144432
    // the max length would be the max of count array = 4
    // i.e., AND of these 4 element would not lead to zero
    int largestCombination(vector<int>& candidates) {
        // to count the number of bits of all candidates
        vector<int> bits(32, 0);
        for (auto candidate : candidates) {
            int currBitIdx = 31;
            while (candidate) {
                bits[currBitIdx--] += (candidate & 1);
                candidate >>= 1;
            }
        }
        return *max_element(bits.begin(), bits.end());
    }
};