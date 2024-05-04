class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        int minHeight = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minHeight = min(minHeight, warehouse[i]);
            warehouse[i] = minHeight;
        }
        sort(boxes.begin(), boxes.end(), greater<int>());
        int res = 0;
        int boxIdx = boxes.size() - 1;
        int houseIdx = n - 1;
        while (boxIdx >= 0 && houseIdx >= 0) {
            if (warehouse[houseIdx] >= boxes[boxIdx]) {
                res++;
                houseIdx--;
                boxIdx--;
            }
            else {
                houseIdx--;
            }
        }
        return res;
    }
};