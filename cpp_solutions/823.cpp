class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        long long mod = 1e9 + 7;
        unordered_map<int, long long> node2trees;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            int parent = arr[i];
            node2trees[parent] = 1;
            for (int j = 0; j < i; ++j) {
                int childA = arr[j];
                if (parent % childA != 0) continue;
                int childB = parent / childA;
                if (node2trees.find(childB) == node2trees.end()) continue;
                long long cntA = node2trees[childA];
                long long cntB = node2trees[childB];
                long long curr = cntA * cntB;
                curr %= mod;
                node2trees[parent] += curr;
                node2trees[parent] %= mod;
            }
        }
        long long res = 0;
        for (auto& element : node2trees) {
            res += element.second;
            res %= mod;
        }
        return res;
    }
};