class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int index = 0;
        int count = 0;
        while (index < m) {
            if (flowerbed[index] == 0) {
                int start = index;
                while (index + 1 < m && flowerbed[index + 1] == 0) index++;
                int length = index - start + 1;
                if (start == 0) length++;
                if (index == m - 1) length++;
                count += (length - 1) / 2;
            }
            index++;
        }
        return count >= n;
    }
};
