class Solution {
public:
    long long toKey(int freq, int num) {
        return ((((long long)freq) << 32) + (long long)num);
    }
    pair<long long, long long> toFreqAndNum(long long key) {
        long long freq = key >> 32;
        long long num = key & ((1LL << 32) - 1);
        return {freq, num};
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        // these two set maintain num & freq in the sliding window
        long long sum = 0;  // answer for the current sliding window
        set<long long, std::greater<long long>> freqAndNum; // max -> min (used for sum)
        set<long long> freqAndNumReserved; // min -> max (not used for sum)

        unordered_map<int, int> num2freq; // {num: freq}
        int left = 0;
        int n = nums.size();
        
        vector<long long> res;
        for (int right = 0; right < n; ++right) {
            int num = nums[right];
            int prevFreq = num2freq[num];
            int nowFreq = prevFreq + 1;
            num2freq[num] = nowFreq;

            long long prevKey = toKey(prevFreq, num);
            long long newKey = toKey(nowFreq, num);
            // if in the used set -> update it and update sum
            if (freqAndNum.count(prevKey)) {
                freqAndNum.erase(prevKey);
                sum -= (long long)prevFreq * num;

                freqAndNum.insert(newKey);
                sum += (long long)nowFreq * num;
            }
            // if in the non-used set -> update it
            else if (freqAndNumReserved.count(prevKey)) {
                freqAndNumReserved.erase(prevKey);
                freqAndNumReserved.insert(newKey);
            }
            // if it is a new num -> put to the non-used one
            else {
                freqAndNumReserved.insert(newKey);
            }

            // maintain the sliding window
            // remove left
            if (right - left + 1 > k) {
                int num = nums[left];
                int prevFreq = num2freq[num];
                int nowFreq = prevFreq - 1;
                num2freq[num] = nowFreq;

                long long prevKey = toKey(prevFreq, num);
                long long newKey = toKey(nowFreq, num);
                
                // if in the used set -> remove it and decrease sum
                if (freqAndNum.count(prevKey)) {
                    freqAndNum.erase(prevKey);
                    sum -= (long long)prevFreq * num;
                }
                // if in the non-used set -> remove it
                else if (freqAndNumReserved.count(prevKey)) {
                    freqAndNumReserved.erase(prevKey);
                }
                // if freq > 0 -> insert back to the non-used set
                if (nowFreq > 0) {
                    freqAndNumReserved.insert(newKey);
                }
                left++;
            }
            // update used and non-used sets by exchanging one item to
            // keep the order
            if (freqAndNum.size() > 0 && freqAndNumReserved.size() > 0) {
                long long maxKey = *freqAndNumReserved.rbegin();
                freqAndNumReserved.erase(maxKey);
                freqAndNum.insert(maxKey);
                auto [f, k] = toFreqAndNum(maxKey);
                sum += (long long)f * k;

                long long minKey = *freqAndNum.rbegin();
                freqAndNum.erase(minKey);
                freqAndNumReserved.insert(minKey);
                auto [ff, kk] = toFreqAndNum(minKey);
                sum -= (long long)ff * kk;
            }

            // if used set doesn't have x item and non-used set has something
            // put to used set and update sum
            while (freqAndNum.size() < x && freqAndNumReserved.size() > 0) {
                long long maxKey = *freqAndNumReserved.rbegin();
                freqAndNumReserved.erase(maxKey);
                freqAndNum.insert(maxKey);
                auto [f, k] = toFreqAndNum(maxKey);
                sum += (long long)f * k;
            }

            if (right - left + 1 == k) {
                res.push_back(sum);
            }
        }
        return res;
    }
};

