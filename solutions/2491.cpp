class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int left = 0;
        int right = n - 1;
        int target = skill[left] + skill[right];
        while (left < right) {
            if (skill[left] + skill[right] != target) return -1;
            res += skill[left] * skill[right];
            left++;
            right--;
        }
        return res;
    }
};