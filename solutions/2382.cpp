class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        map<int, int> segments; // to store available segments [start, end] (both inclusive)
        multiset<long long> mst; // to store available segment sums
        
        // use prefixSum enabling query segment sum in O(1)
        // to query sum[i, j] => prefixSum[j + 1] - prefixSum[i]
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // initially
        // insert segment [0, n - 1] and corresponding segment sum
        segments[0] = n - 1; // segment
        mst.insert(prefixSum[n] - prefixSum[0]); // segment sum
        
        // go through every query
        vector<long long> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int toDelete = removeQueries[i];
            
            // get the segment contain the deleted one
            auto it = segments.upper_bound(toDelete);
            --it;
            
            // get the start and end point, delete the segment and corresponding sum
            int start = it->first;
            int end = it->second;
            segments.erase(it);
            
            long long currentSum = prefixSum[end + 1] - prefixSum[start];
            mst.erase(mst.find(currentSum));
            
            // insert the new ones
            // case 1: the segment only contain the deleted one -> do nothing
            if (start == toDelete && end == toDelete) {
                if (mst.empty()) res[i] = 0;
                else res[i] = *mst.rbegin();
            }
            
            // case 2: the start point is the deleted one -> insert [start + 1, end]
            else if (start == toDelete) {
                segments[start + 1] = end;
                mst.insert(prefixSum[end + 1] - prefixSum[start + 1]);
                res[i] = *mst.rbegin();
            }
            
            // case 3: the end point is the deleted one -> insert [start, end - 1]
            else if (end == toDelete) {
                segments[start] = end - 1;
                mst.insert(prefixSum[end] - prefixSum[start]);
                res[i] = *mst.rbegin();
            }
            // case 4: the deleted one is in the middle -> insert [start, deleted - 1] and [deleted + 1, end]
            else {
                // insert [start, toDelete - 1]
                segments[start] = toDelete - 1;
                mst.insert(prefixSum[toDelete] - prefixSum[start]);
                // insert [toDelete + 1, end]
                segments[toDelete + 1] = end;
                mst.insert(prefixSum[end + 1] - prefixSum[toDelete + 1]);
                
                res[i] = *mst.rbegin();
            }
        }
        return res;
    }
};