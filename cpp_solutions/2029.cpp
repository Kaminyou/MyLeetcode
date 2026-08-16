class Solution {
public:
    bool win(vector<int>& counts, int sum, int turn) {
        if (counts[0] + counts[1] + counts[2] == 0) {
            if (turn == 1) return true;
            return false;
        }
        if (counts[0] > 0) {
            counts[0]--;
            return (!win(counts, sum, turn ^ 1));
        }
        if (sum % 3 == 1) {
            if (counts[1] > 0) {
                counts[1]--;
                return (!win(counts, sum + 1, turn ^ 1));
            }
            return false;
        }
        else {
            if (counts[2] > 0) {
                counts[2]--;
                return (!win(counts, sum + 2, turn ^ 1));
            }
            return false;
        }
    }
    bool stoneGameIX(vector<int>& stones) {
        vector<int> counts(3, 0);
        for (auto& stone : stones) {
            counts[stone % 3]++;
        }

        auto temp = counts;
        if (temp[1] > 0) {
            temp[1]--;
            if (!win(temp, 1, 1)) return true;
        }
        temp = counts;
        if (temp[2] > 0) {
            temp[2]--;
            if (!win(temp, 2, 1)) return true;
        }
        return false;
    }
};

