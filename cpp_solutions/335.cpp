class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        for (int i = 3; i < distance.size(); ++i) {
            // case 1
            //      x(i-2)
            //       ┌───┐
            // x(i-1)│   │x(i-3)
            //       └───┼──>
            //       x(i)│

            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) return true;
            
            // case 2
            //        x(i-3)
            //       ┌──────┐
            //       │      │x(i-4)
            // x(i-2)│      ^
            //       │      │x(i)
            //       └──────│
            //        x(i-1)
            if (i >= 4) {
                if (distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) return true;
            }
            
            // case 3
            //         x(i-4)  x(i-5)
            //       ┌────────┐ /
            //       │        │/
            // x(i-3)│       <│──────│
            //       │          x(i) │x(i-1)
            //       └───────────────│
            //            x(i-2)
            if (i >= 5) {
                if (distance[i - 3] > distance[i - 1] && distance[i - 2] > distance[i - 4] && distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 5] + distance[i - 1] >= distance[i - 3]) return true;
            }
        }
        return false;
    }
};