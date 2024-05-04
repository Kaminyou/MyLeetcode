class Solution {
public:
    int minSwaps(vector<int>& data) {
        int oneCount = 0;
        for (auto& num : data) {
            if (num == 1) oneCount++;
        }
        int res = INT_MAX;
        int zeroCount = 0;
        for (int i = 0; i < oneCount; ++i) {
            if (data[i] == 0) zeroCount++;
        }
        res = min(res, zeroCount);
        
        for (int i = oneCount; i < data.size(); ++i) {
            if (data[i] == 0) zeroCount++;
            if (data[i - oneCount] == 0) zeroCount--;
            res = min(res, zeroCount);
        }
        return res;
    }
};