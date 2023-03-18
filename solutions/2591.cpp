class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        money -= children;
        vector<int> distributed(children, 1);
        for (int i = 0; i < children; ++i) {
            int use = min(money, 7);
            distributed[i] += use;
            money -= use;
        }
        if (money) {
            distributed[distributed.size() - 1] += money;
        }
        

        int count = 0;
        bool hasFour = false;
        vector<int> counts(200, 0);
        for (auto& distribute : distributed) {
            counts[distribute]++;
        }
        if (counts[8] == 0) return 0;
        if (counts[4] == 0) return counts[8];
        
        bool hasOther = false;
        for (int i = 0 ; i < 200; ++i) {
            if (i == 4) continue;
            if (i == 8) continue;
            if (counts[i] != 0) hasOther = true;
        }
        if (hasOther) return counts[8];
        return counts[8] - 1;
    }
};
