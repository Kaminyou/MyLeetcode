class Leaderboard {
public:
    multiset<int, greater<int>> mst;
    unordered_map<int, int> id2score;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if (id2score.find(playerId) != id2score.end()) {
            mst.erase(mst.find(id2score[playerId]));
        }
        id2score[playerId] += score;
        mst.insert(id2score[playerId]);
    }
    
    int top(int K) {
        auto it = mst.begin();
        int sum = 0;
        while (K--) {
            sum += *it;
            it++;
            if (it == mst.end()) break;
        }
        return sum;
    }
    
    void reset(int playerId) {
        mst.erase(mst.find(id2score[playerId]));
        id2score.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */