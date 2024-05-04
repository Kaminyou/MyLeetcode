class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        int maxDigit = -1;
        int maxIdx = -1;
        int leftIdx = -1;
        int rightIdx = -1;
        
        for (int i = numStr.size() - 1; i >= 0; --i) {
            if (numStr[i] > maxDigit) {
                maxDigit = numStr[i];
                maxIdx = i;
                continue;
            }
            if (numStr[i] < maxDigit) {
                leftIdx = i;
                rightIdx = maxIdx;
            }
        }
        if (leftIdx == -1) return num;
        swap(numStr[leftIdx], numStr[rightIdx]);
        return stoi(numStr);
    }
};

// V2
// class Solution {
// public:
//     vector<int> toVector(int num) {
//         vector<int> v;
//         while (num) {
//             v.push_back(num % 10);
//             num /= 10;
//         }
//         reverse(v.begin(), v.end());
//         return v;
//     }
//     int concat(vector<int>& v) {
//         int res = 0;
//         for (int num : v) {
//             res = res * 10 + num;
//         }
//         return res;
//     }
//     int maximumSwap(int num) {
//         vector<int> numV = toVector(num);
//         int n = numV.size();

//         for (int i = 0; i < n; ++i) {
//             int maxVal = numV[i];
//             int maxIdx = -1;
//             bool flag = false;
//             for (int j = i + 1; j < n; ++j) {
//                 if (flag) {
//                     if (numV[j] >= maxVal) {
//                         maxVal = numV[j];
//                         maxIdx = j;
//                     }
//                 }
//                 else if (numV[j] > maxVal) {
//                     maxVal = numV[j];
//                     maxIdx = j;
//                     flag = true;
//                 }
//             }
//             if (maxIdx != -1) {
//                 swap(numV[i], numV[maxIdx]);
//                 return concat(numV);
//             }
//         }
//         return concat(numV);
//     }
// };