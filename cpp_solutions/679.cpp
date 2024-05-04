class Solution {
public:
    double eps = 0.001;
    void backtracking(vector<double>& cards, bool& reach) {
        if (reach) return;
        if (cards.size() == 1 && abs(cards[0] - 24) < eps) reach = true;
        else {
            for (int i = 0; i < cards.size(); i++) {
                for (int j = 0; j < i; j++) {
                    double p = cards[i];
                    double q = cards[j];
                    vector<double> ops = {p + q, p - q, q - p, p * q};
                    if (p > eps) ops.push_back(q / p);
                    if (q > eps) ops.push_back(p / q);
                    cards.erase(cards.begin() + i);
                    cards.erase(cards.begin() + j);
                    for (auto op : ops) {
                        cards.push_back(op);
                        backtracking(cards, reach);
                        cards.pop_back();
                    }
                    cards.insert(cards.begin() + j, q);
                    cards.insert(cards.begin() + i, p);
                }
            }
        }
        
    }
    bool judgePoint24(vector<int>& cards) {
        bool reach = false;
        vector<double> cardsDouble;
        for (auto card : cards) cardsDouble.push_back(static_cast<double>(card));
        backtracking(cardsDouble, reach);
        return reach;
    }
};