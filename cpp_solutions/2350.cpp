class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<bool> existed(k, false);
        int uniqueCount = 0;
        int collection = 0;
        
        for (auto roll : rolls) {
            roll--;
            if (existed[roll] == false) {
                uniqueCount++;
                existed[roll] = true;
            }
            
            if (uniqueCount == k) {
                uniqueCount = 0;
                collection++;
                for (int j = 0; j < k; ++j) existed[j] = false;
            }
        }
        return collection + 1;
    }
};