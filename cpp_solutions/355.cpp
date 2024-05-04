typedef pair<int, int> P;
class Twitter {
public:
    unordered_map<int, set<P, greater<P>>> id2posts; // id->{time, tweetId}
    unordered_map<int, unordered_set<int>> id2followees;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        id2posts[userId].insert(make_pair(time, tweetId));
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (id2followees[userId].find(userId) == id2followees[userId].end()) id2followees[userId].insert(userId);
        vector<int> following;
        vector<set<P, greater<P>>::iterator> currIts;
        for (auto e : id2followees[userId]) {
            following.push_back(e);
            currIts.push_back(id2posts[e].begin());
        }
        int n = currIts.size();
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            if (currIts[i] == id2posts[following[i]].end()) continue;
            auto [time, tweetId] = *(currIts[i]);
            pq.push(make_pair(time, make_pair(tweetId, i)));
            currIts[i] = next(currIts[i]);
        }
        
        int count = 10;
        vector<int> res;
        while (count && !pq.empty()) {
            auto [time, element] = pq.top();
            auto [tweetId, i] = element;
            pq.pop();
            res.push_back(tweetId);
            if (currIts[i] != id2posts[following[i]].end()) {
                auto [nextTime, nextTweetId] = *(currIts[i]);
                pq.push(make_pair(nextTime, make_pair(nextTweetId, i)));
                currIts[i] = next(currIts[i]);
            }
            count--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        id2followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        id2followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */