class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st; // monotonic increasing
        for (auto num : arr) {
            if (st.empty() || num >= st.top()) {
                st.push(num);
            }
            else {
                int maxVal = st.top();
                st.pop();
                while (!st.empty() && num < st.top()) st.pop();
                st.push(maxVal);
            }
        }
        return st.size();
    }
};
// class Counter {
// private:
//     unordered_map<int, int> mp;
//     int positive;
//     int negative;
// public:
//     Counter() {
//         positive = 0;
//         negative = 0;
//     }
//     void insert(int x) {
//         if (mp[x] == -1) negative--;
//         else if (mp[x] == 0) positive++;
//         mp[x]++;
//     }
//     void remove(int x) {
//         if (mp[x] == 1) positive--;
//         else if (mp[x] == 0) negative++;
//         mp[x]--;
//     }
//     bool isZero() {
//         return (!positive) && (!negative);
//     }
// };
// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> sortedArr(n, 0);
//         for (int i = 0; i < n; ++i) sortedArr[i] = arr[i];
//         sort(sortedArr.begin(), sortedArr.end());
        
//         int res = 0;
//         Counter* counter = new Counter();
//         for (int i = 0; i < n; ++i) {
//             counter->insert(arr[i]);
//             counter->remove(sortedArr[i]);
//             if (counter->isZero()) res++;
//         }
//         return res;
//     }
// };