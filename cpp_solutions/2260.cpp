class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> hash;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++) {
            int num = cards[i];
            if (hash.find(num) != hash.end()) {
                ans = min(ans, i - hash[num] + 1);
            }
            hash[num] = i;
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};