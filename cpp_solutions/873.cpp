class Solution {
public:
    int length(long long x, long long y, unordered_set<long long>& st) {
        int size = 2;
        bool flag = false;
        while (st.find(x + y) != st.end()) {
            flag = true;
            size++;
            int temp = x + y;
            x = y;
            y = temp;
        }
        if (flag) return size;
        return 0;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<long long> st;
        for (auto& num : arr) st.insert(num);
        int res = 0;        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, length(arr[i], arr[j], st));
            }
        }
        return res;
    }
};