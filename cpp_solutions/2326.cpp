/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int M;
    int N;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void nextPosition(vector<vector<int>>& matrix, int& currRow, int& currCol, int& direction) {
        int nextRow = currRow + directions[direction][0];
        int nextCol = currCol + directions[direction][1];
        if (nextRow >= M || nextRow < 0 || nextCol >= N || nextCol < 0 || matrix[nextRow][nextCol] != -1) {
            direction = (direction + 1) % 4;
        }
        currRow = currRow + directions[direction][0];
        currCol = currCol + directions[direction][1];
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        M = m;
        N = n;
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int currRow = 0;
        int currCol = 0;
        int direction = 0;
        // 0: right; 1:down; 2:left; 3:up
        while (head) {
            matrix[currRow][currCol] = head->val;
            nextPosition(matrix, currRow, currCol, direction);
            head = head->next;
        }
        return matrix;
    }
};