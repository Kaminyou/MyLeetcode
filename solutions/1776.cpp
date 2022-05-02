class Solution {
public:
    double collisionTime(vector<vector<int>>& cars, int car1, int car2) {
        return static_cast<double>(cars[car2][0] - cars[car1][0]) / (cars[car1][1] - cars[car2][1]);
    }
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        // from the back to the front
        // leave those can be collided in the stack
        // (1.) slower than curr
        // (2.) collision time < collision time to more foward car
        stack<int> st;
        int n = cars.size();
        vector<double> ans(n, -1.0);
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && (cars[st.top()][1] >= cars[i][1] || (st.size() > 1 && collisionTime(cars, i, st.top()) > ans[st.top()]))) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : collisionTime(cars, i, st.top());
            st.push(i);
        }
        return ans;
    }
};