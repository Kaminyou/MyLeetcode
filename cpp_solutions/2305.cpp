class Solution {
public:
    void backtracking(vector<int>& cookies, vector<bool>& used, int leave, int chunkNum, int currSum, int criteria, int& minChunkNum) {
        if (leave == 0) {
            if (currSum > 0) chunkNum++;
            minChunkNum = min(minChunkNum, chunkNum);
        }
        for (int i = 0; i < cookies.size(); ++i) {
            if (used[i]) continue;
            
            used[i] = true;
            int tempCurrSum = currSum;
            int tempChunkNum = chunkNum;
            if (currSum + cookies[i] > criteria) {
                chunkNum++;
                currSum = cookies[i];
            }
            else if (currSum + cookies[i] == criteria) {
                chunkNum++;
                currSum = 0;
            }
            else {
                currSum += cookies[i];
            }
            backtracking(cookies, used, leave - 1, chunkNum, currSum, criteria, minChunkNum);
            
            currSum = tempCurrSum;
            chunkNum = tempChunkNum;
            used[i] = false;
        }
    }
    int criteria(vector<int>& cookies, int maxVal) {
        // given maxVal, max chuncks can be formed
        int n = cookies.size();
        int minNum = n;
        vector<bool> used(n, false);
        backtracking(cookies, used, n, 0, 0, maxVal, minNum);
        return minNum;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        // binary search unfariness
        // given unfariness, can cookie be splitted into k
        // larger unfariness => lower k
        // lower unfariness => larger k
        int sum = 0;
        int maxVal = 0;
        for (auto& cookie : cookies) {
            sum += cookie;
            maxVal = max(maxVal, cookie);
        }
        int left = maxVal;
        int right = sum;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (criteria(cookies, mid) <= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

// 1, 2, 5, 6
//       ^.    lower bound 5 >= 