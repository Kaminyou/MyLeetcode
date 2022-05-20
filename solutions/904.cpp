class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> counts;
        
        int res = 0;
        int left = 0;
        int type = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            if (counts[fruits[right]] == 0) type++;
            counts[fruits[right]]++;
            while (type > 2) {
                if (counts[fruits[left]] == 1) type--;
                counts[fruits[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};