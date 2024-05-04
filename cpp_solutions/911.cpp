class TopVotedCandidate {
public:
    vector<int> precomputed;
    vector<int> times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> person2votes;
        int n = times.size();
        int maxVotes = 0;
        precomputed.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            person2votes[persons[i]]++;
            if (person2votes[persons[i]] >= maxVotes) {
                maxVotes = person2votes[persons[i]];
                precomputed[i] = persons[i];
            }
            else {
                precomputed[i] = precomputed[i - 1];
            }
        }
    }
    
    int q(int t) {
        auto it = upper_bound(times.begin(), times.end(), t);
        it--;
        int index = it - times.begin();
        return precomputed[index];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */