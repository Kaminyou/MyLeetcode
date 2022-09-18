class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int idx = st.top();
                st.pop();
                if (!st.empty()) {
                    int beforeIdx = st.top();
                    int h = min(height[beforeIdx], height[i]) - height[idx];
                    int w = i - beforeIdx - 1;
                    res += h * w;
                }
            }
            st.push(i);
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;
        int currentHeight = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                currentHeight = max(currentHeight, height[left]);
                while (left + 1 < right && height[left + 1] <= currentHeight) {
                    left++;
                    res += currentHeight - height[left];
                }
                left++;
            }
            else {
                currentHeight = max(currentHeight, height[right]);
                while (right - 1 > left && height[right - 1] <= currentHeight) {
                    right--;
                    res += currentHeight - height[right];
                }
                right--;
            }
        }
        return res;
    }
};