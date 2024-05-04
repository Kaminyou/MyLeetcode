class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> stk1;
        stack<int> stk2;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            while (!stk2.empty() && nums[stk2.top()] < nums[i]) {
                res[stk2.top()] = nums[i];
                stk2.pop();
            }
            vector<int> temp;
            while (!stk1.empty() && nums[stk1.top()] < nums[i]) {
                temp.push_back(stk1.top());
                stk1.pop();
            }
            reverse(temp.begin(), temp.end());
            for (auto& idx : temp) {
                stk2.push(idx);
            }
            stk1.push(i);
        }
        return res;
    }
};

class Solution {
public:
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
    }
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<pair<int, int>> numsWithIdx;
        int n = nums.size();
        for (int i = 0; i < n; ++i) numsWithIdx.push_back({nums[i], i});
        sort(numsWithIdx.begin(), numsWithIdx.end(), cmp);
        map<int, int> mp;
        vector<int> res(n, -1);
        int index = 0;
        while (index < n) {
            int currentNum = numsWithIdx[index].first;
            int currentIdx = numsWithIdx[index].second;
            vector<int> toHash;
            toHash.push_back(currentIdx);
            bool hasValue = true;
            
            auto it = mp.upper_bound(currentIdx);
            if (it == mp.end()) {
                hasValue = false;
            }
            if (hasValue) it = next(it);
            if (it == mp.end()) {
                hasValue = false;
            }
            if (hasValue) res[currentIdx] = it->second;
            
            
            while (index + 1 < n && numsWithIdx[index + 1].first == currentNum) {
                index++;
                currentIdx = numsWithIdx[index].second;
                toHash.push_back(currentIdx);
                auto it = mp.upper_bound(currentIdx);
                if (it == mp.end()) continue;
                it = next(it);
                if (it == mp.end()) continue;
                res[currentIdx] = it->second;
            }
            index++;
            for (auto& idx : toHash) mp[idx] = currentNum;
        }
        return res;
    }
};

