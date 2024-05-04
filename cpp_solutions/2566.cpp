class Solution {
public:
    int minMaxDifference(int num) {
        int minVal = num;
        int maxVal = num;
        string numStr = to_string(num);
        
        for (char i = '0'; i <= '9'; ++i) {
            string tempMax = numStr;
            string tempMin = numStr;
            int m = tempMax.size();
            for (int j = 0; j < m; ++j) {
                if (numStr[j] == i) {
                    tempMax[j] = '9';
                    tempMin[j] = '0';
                }
            }
            minVal = min(minVal, stoi(tempMin));
            maxVal = max(maxVal, stoi(tempMax));
        }
        return maxVal - minVal;
    }
};