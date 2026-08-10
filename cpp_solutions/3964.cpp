class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int light = lights[i];
            if (light > 0) {
                int left = max(0, i - light);
                int right = min(n - 1, i + light) + 1;
                diff[left]++;
                diff[right]--;
            }
        }
        vector<bool> mask(n, false);
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            if (curr > 0) mask[i] = true;
        }
        
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (mask[i]) {
                res += (cnt + 3 - 1) / 3;
                cnt = 0;
            }
            else cnt++;
        }
        res += (cnt + 3 - 1) / 3;
        return res;
    }
};

