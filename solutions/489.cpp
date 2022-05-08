/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(Robot& robot, int x, int y, int currDirect, unordered_set<string>& st) {
        robot.clean();
        st.insert(to_string(x) + "_" + to_string(y));
        
        for (int i = 0; i < directions.size(); i++) {
            int _currDirect = (currDirect + i) % 4;
            int _x = x + directions[_currDirect].first;
            int _y = y + directions[_currDirect].second;
            if (st.find(to_string(_x) + "_" + to_string(_y)) == st.end() && robot.move()) {
                dfs(robot, _x, _y, _currDirect, st);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        unordered_set<string> st;
        dfs(robot, 0, 0, 0, st);
    }
};