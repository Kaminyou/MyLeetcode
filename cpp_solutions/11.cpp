class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int curr = min(height[left], height[right]) * (right - left);
            res = max(res, curr);
            if (height[right] >= height[left]) left++;
            else if (height[right] < height[left]) right--;
        }
        return res;
    }
};