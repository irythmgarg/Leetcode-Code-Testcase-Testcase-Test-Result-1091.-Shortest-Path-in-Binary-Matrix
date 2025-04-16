// Problem: Shortest Path in Binary Matrix (Leetcode 1091)
// Approach: Dijkstra's Algorithm (Min-Heap BFS with cost tracking)
// Language: C++
// Author: [Ridham Garg or irythmgarg] 🚀

class Solution {
public:
    // Utility function to check if a cell (newx, newj) is within the grid bounds
    bool isSafe(int newx, int newj, int m, int n) {
        return newx >= 0 && newx < m && newj >= 0 && newj < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();       // Rows
        int n = grid[0].size();    // Columns

        // If the start or end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        // Distance matrix initialized to INT_MAX
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        // Min-heap priority queue: {cost, {i, j}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> q;

        // All 8 possible directions (including diagonals)
        vector<vector<int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {1, 1}, {1, 0},
            {1, -1}, {0, -1}
        };

        // Start from (0,0) with initial cost 1
        q.push({1, {0, 0}});
        ans[0][0] = 1;

        // Modified Dijkstra’s loop
        while (!q.empty()) {
            auto top = q.top();
            q.pop();

            int cost = top.first;
            int i = top.second.first;
            int j = top.second.second;

            for (auto di : dir) {
                int newi = i + di[0];
                int newj = j + di[1];

                // Check bounds and if the cell is open
                if (isSafe(newi, newj, m, n) && grid[newi][newj] == 0) {
                    // Update path only if a shorter one is found
                    if (ans[newi][newj] > cost + 1) {
                        q.push({cost + 1, {newi, newj}});
                        ans[newi][newj] = cost + 1;
                    }
                }
            }
        }

        // If destination is still unreachable, return -1
        return ans[m - 1][n - 1] == INT_MAX ? -1 : ans[m - 1][n - 1];
    }
};
