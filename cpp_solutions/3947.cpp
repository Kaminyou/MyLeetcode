class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<int, int> fact2cnt;
        int minPrice = INT_MAX;
        for (auto& item : items) {
            fact2cnt[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }
        vector<int> gains(n, 0);
        unordered_map<int, int> gainHash;
        vector<pair<int, int>> priceAndIdx(n);
        for (int i = 0; i < n; ++i) {
            int factor = items[i][0];
            int price = items[i][1];
            priceAndIdx[i] = {price, i};
            if (gainHash.count(factor)) {
                gains[i] = gainHash[factor];
                continue;
            }
            gains[i] += fact2cnt[factor] - 1;
            for (int j = 2; j * factor <= n; ++j) {
                gains[i] += fact2cnt[j * factor];
            }
            gainHash[factor] = gains[i];
        }

        sort(priceAndIdx.begin(), priceAndIdx.end());
        int current = 0;
        int itemNum = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int price = priceAndIdx[i].first;
            int idx = priceAndIdx[i].second;
            int gainCnt = min(gains[idx], (budget - current) / price);
            current += gainCnt * price;
            itemNum += gainCnt * 2;

            int remaining = budget - current;
            res = max(res, itemNum + remaining / minPrice);
        }
        return res;
    }
};

