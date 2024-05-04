class Compare {
public:
    // s1 > s2 => true
    bool operator() (const string& s1, const string&s2) {
        if (s1.size() != s2.size()) return s1.size() > s2.size();
        return s1 > s2;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> q;
        
        for (string num : nums) {
            q.push(num);
            if (q.size() > k) {
                q.pop();
            }
        }
        return q.top();
    }
};