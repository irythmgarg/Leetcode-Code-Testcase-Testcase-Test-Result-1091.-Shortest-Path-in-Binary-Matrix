// Problem: Shortest Path in Binary Matrix (Leetcode 1091)
// Approach: Dijkstra's queue (BFS) with Distance Matrix
// Language: C++
// Author: [Ridham Garg or irythmgarg] 🚀

class Solution {
public:
    // Utility function to check if the cell is within grid bounds
    bool isSafe(int newx, int newj, int m, int n) {
        return newx >= 0 && newx < m && newj >= 0 && newj < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();       // Rows
        int n = grid[0].size();    // Columns

        // If the start or destination is blocked, return -1
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        // Initialize a distance matrix with INT_MAX
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        // Queue for BFS traversal: stores {current path length, {row, col}}
        queue<pair<int, pair<int, int>>> q;

        // All 8 directions including diagonals
        vector<vector<int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {1, 1}, {1, 0},
            {1, -1}, {0, -1}
        };

        // Start from the top-left corner with a path length of 1
        q.push({1, {0, 0}});
        ans[0][0] = 1;

        // Perform BFS traversal
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int cost = top.first;
            int i = top.second.first;
            int j = top.second.second;

            // Explore all 8 directions
            for (auto di : dir) {
                int newi = i + di[0];
                int newj = j + di[1];

                // Check bounds and if the cell is open
                if (isSafe(newi, newj, m, n) && grid[newi][newj] == 0) {
                    // Only update if we found a shorter path
                    if (ans[newi][newj] > cost + 1) {
                        q.push({cost + 1, {newi, newj}});
                        ans[newi][newj] = cost + 1;
                    }
                }
            }
        }

        // Return the shortest path to bottom-right, or -1 if unreachable
        return ans[m - 1][n - 1] == INT_MAX ? -1 : ans[m - 1][n - 1];
    }
};
