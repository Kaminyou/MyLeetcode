class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> numsLL(n);
        vector<int> leftIndex(n);
        vector<int> rightIndex(n);
        set<pair<long long, int>> st;
        int badPairCnt = 0;
        for (int i = 0; i < n; ++i) {
            numsLL[i] = nums[i];
            leftIndex[i] = i - 1;
            rightIndex[i] = i + 1;
            if (i < n - 1) {
                if (nums[i] > nums[i + 1]) badPairCnt++;
                st.insert({(long long)nums[i] + (long long)nums[i + 1], i});
            }
        }

        int res = 0;
        while (badPairCnt) {
            auto it = st.begin();
            int currIdx = it->second;
            int nextIdx = rightIndex[currIdx];
            int prevIdx = leftIndex[currIdx];
            int nextNextIdx = rightIndex[nextIdx];

            st.erase(it);
            // prev <-> curr <-> next <-> nextNext
            //            ^       ^
            if (numsLL[currIdx] > numsLL[nextIdx]) badPairCnt--;
            long long newSum = numsLL[currIdx] + numsLL[nextIdx];

            if (prevIdx >= 0) {
                if (numsLL[prevIdx] > numsLL[currIdx]) badPairCnt--;
                if (numsLL[prevIdx] > newSum) badPairCnt++;
                st.erase({numsLL[prevIdx] + numsLL[currIdx], prevIdx});
                st.insert({numsLL[prevIdx] + newSum, prevIdx});
            }

            if (nextNextIdx < n) {
                if (numsLL[nextIdx] > numsLL[nextNextIdx]) badPairCnt--;
                if (newSum > numsLL[nextNextIdx]) badPairCnt++;
                st.erase({numsLL[nextIdx] + numsLL[nextNextIdx], nextIdx});
                st.insert({numsLL[nextNextIdx] + newSum, currIdx});
            }

            numsLL[currIdx] = newSum;
            rightIndex[currIdx] = nextNextIdx;
            if (nextNextIdx < n) leftIndex[nextNextIdx] = currIdx;
            res++;
        }
        return res;
    }
};

