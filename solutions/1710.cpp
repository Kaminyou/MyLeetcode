class Solution {
public:
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int n = boxTypes.size();
        int index = 0;
        int res = 0;
        while (truckSize && index < n) {
            int truckNum = min(truckSize, boxTypes[index][0]);
            res += truckNum * boxTypes[index][1];
            index++;
            truckSize -= truckNum;
        }
        return res;
    }
};