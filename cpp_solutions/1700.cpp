class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count = {0, 0};
        for (auto& student : students) {
            count[student]++;
        }
        
        int n = sandwiches.size();
        int i = 0;
        for (; i < n && count[sandwiches[i]]; i++) {
            count[sandwiches[i]]--;
        }
        return n - i;
    }
};