class Solution {
public:
    bool isEqualFreq(unordered_map<int, int>& count) {
        if (count.size() >= 3) return false;
        if (count.size() == 2) {
            vector<pair<int, int>> v;
            for (auto& element : count) {
                v.push_back(element);
            }
            sort(v.begin(), v.end());
            if (v[0].first == 1 && v[0].second == 1) return true;
            else if (v[1].first - v[0].first == 1 && v[1].second == 1) return true;
            else return false;
        }
        if (count.size() == 1) {
            if (count.begin()->first == 1) return true;
            return count.begin()->second == 1;
        }
        return false;
        
    }
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> numCnt;
        unordered_map<int, int> cntCnt;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int originalCnt = numCnt[nums[i]];
            numCnt[nums[i]]++;
            int cnt = numCnt[nums[i]];
            
            cntCnt[cnt]++;
            if (originalCnt >= 1) {
                cntCnt[originalCnt]--;
                if (cntCnt[originalCnt] == 0) cntCnt.erase(originalCnt);
            }
            if (isEqualFreq(cntCnt)) res = max(res, i + 1);
        }
        return res;
    }
};
