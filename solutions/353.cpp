typedef pair<int, int> P;
class SnakeGame {
public:
    queue<P> q;
    unordered_set<string> st;
    vector<vector<int>>* food;
    int foodIdx = 0;
    int width;
    int height;
    int score = 0;
    string encoder(int x, int y) {
        return to_string(x) + "#" + to_string(y);
    }
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = &food;
        q.push(make_pair(0, 0));
        this->width = width;
        this->height = height;
    }
    P getNext(string& direction, int x, int y) {
        if (direction == "U") return make_pair(x - 1, y);
        else if (direction == "D") return make_pair(x + 1, y);
        else if (direction == "L") return make_pair(x, y - 1);
        else return make_pair(x, y + 1);
    }
    int move(string direction) {
        auto [x, y] = q.back();
        auto [nextX, nextY] = getNext(direction, x, y);
        if (nextX < 0 || nextX >= height || nextY < 0 || nextY >= width) return -1;
        if (foodIdx < (*food).size() && nextX == (*food)[foodIdx][0] && nextY == (*food)[foodIdx][1]) {
            q.push(make_pair(nextX, nextY));
            score++;
            foodIdx++;
            st.insert(encoder(nextX, nextY));
            return score;
        }
        auto [frontX, frontY] = q.front();
        st.erase(encoder(frontX, frontY));
        q.pop();
        q.push(make_pair(nextX, nextY));
        if (st.find(encoder(nextX, nextY)) != st.end()) return -1;
        st.insert(encoder(nextX, nextY));
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */