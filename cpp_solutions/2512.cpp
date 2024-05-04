class Solution {
public:
    
    unordered_set<string> negative_feedback_set;
    int value(string& feedback, unordered_set<string>& positive_feedback_set, unordered_set<string>& negative_feedback_set) {
        stringstream ss(feedback);
        string temp;
        int score = 0;
        while (getline(ss, temp, ' ')) {
            if (positive_feedback_set.find(temp) != positive_feedback_set.end()) score += 3;
            else if (negative_feedback_set.find(temp) != negative_feedback_set.end()) score -= 1;
        }
        return score;
    }
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positive_feedback_set(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negative_feedback_set(negative_feedback.begin(), negative_feedback.end());
        vector<pair<int, int>> scores;
        
        int n = student_id.size();
        for (int i = 0; i < n; ++i) {
            int score = value(report[i], positive_feedback_set, negative_feedback_set);
            scores.push_back({-score, student_id[i]});
        }
       
        sort(scores.begin(), scores.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(scores[i].second);
        }
        return res;
    }
};