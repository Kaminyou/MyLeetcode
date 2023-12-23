class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<int> st;
        int x = 0;
        int y = 0;
        st.insert((x << 15) + y);
        for (auto& c : path) {
            switch (c) {
                case 'N':
                    y += 1;
                    break;
                case 'S':
                    y -= 1;
                    break;
                case 'E':
                    x += 1;
                    break;
                case 'W':
                    x -= 1;
                    break;
            }
            int pos = (x << 15) + y;
            if (st.count(pos)) return true;
            st.insert(pos);
        }
        return false;
    }
};
