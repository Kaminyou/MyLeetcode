class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int slots1Index = 0;
        int slots2Index = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        while (slots1Index < slots1.size() && slots2Index < slots2.size()) {
            int minVal = max(slots1[slots1Index][0], slots2[slots2Index][0]);
            int maxVal = min(slots1[slots1Index][1], slots2[slots2Index][1]);
            
            if (maxVal - minVal >= duration) {
                return {minVal, minVal + duration};
            } 
            
            if (slots1[slots1Index][1] > slots2[slots2Index][1]) slots2Index++;
            else slots1Index++;
        }
        return {};
    }
};