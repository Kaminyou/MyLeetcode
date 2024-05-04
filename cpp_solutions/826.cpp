class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int difficultyIdx = -1;
        int workerIdx = 0;
        int n = difficulty.size();
        
        vector<pair<int, int>> diffAndProfit;
        for (int i = 0; i < difficulty.size(); ++i) {
            diffAndProfit.push_back({difficulty[i], profit[i]});
        }
        sort(diffAndProfit.begin(), diffAndProfit.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0;
        int res = 0;
        for (auto& workerCap : worker) {
            while (difficultyIdx + 1 < n && diffAndProfit[difficultyIdx + 1].first <= workerCap) {
                difficultyIdx++;
                maxProfit = max(maxProfit, diffAndProfit[difficultyIdx].second);
            }
            res += maxProfit;
        }
        return res;
    }
};