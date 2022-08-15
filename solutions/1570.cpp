class SparseVector {
public:
    vector<pair<int, int>> sparseVec;
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sparseVec.push_back(make_pair(i, nums[i]));
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int s1 = sparseVec.size();
        int s2 = vec.sparseVec.size();
        int idx1 = 0;
        int idx2 = 0;
        int sum = 0;
        while (idx1 < s1 && idx2 < s2) {
            if (sparseVec[idx1].first == vec.sparseVec[idx2].first) {
                sum += sparseVec[idx1].second * vec.sparseVec[idx2].second;
                idx1++;
                idx2++;
            }
            else if (sparseVec[idx1].first > vec.sparseVec[idx2].first) idx2++;
            else idx1++;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);