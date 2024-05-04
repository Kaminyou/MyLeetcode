class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        // Flush
        char c = suits[0];
        bool flag = true;
        for (auto& ch : suits) {
            if (ch != c) {
                flag = false;
                break;
            }
        }
        if (flag) return "Flush";
        
        vector<int> counts(14, 0);
        for (auto& rank : ranks) {
            counts[rank]++;
        }
        
        int maxCount = 0;
        for (int i = 0; i < 14; ++i) {
            maxCount = max(maxCount, counts[i]);
        }
        
        if (maxCount >= 3) return "Three of a Kind";
        if (maxCount >= 2) return "Pair";
        return "High Card";
    }
};