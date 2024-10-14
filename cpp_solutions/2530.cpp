class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while (k--) {
            int num = pq.top();
            pq.pop();
            res += num;
            num = (num + 2) / 3;
            pq.push(num);
        }
        return res;
    }
};
