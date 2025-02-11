class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> num2index;
        int m = elements.size();
        unordered_set<int> st;
        int maxElement = *max_element(groups.begin(), groups.end());
        for (int i = 0; i < m; ++i) {
            int element = elements[i];
            if (st.count(element)) continue;
            for (int factor = 1; factor * element <= maxElement; ++factor) {
                if (num2index.find(factor * element) == num2index.end()) num2index[factor * element] = i;
            }
            st.insert(element);
        }
        int n = groups.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (num2index.find(groups[i]) != num2index.end()) res[i] = num2index[groups[i]];
        }
        return res;
    }
};
