// Problem: Shortest Path in Binary Matrix (Leetcode 1091)
// Approach: Breadth-First Search (BFS)
// Language: C++
// Author: [Ridham Garg or irythmgarg] 🔥

class Solution {
public:
    // Check if the cell (newx, newj) is within bounds of the grid
    bool isSafe(int newx, int newj, int m, int n) {
        return newx >= 0 && newx < m && newj >= 0 && newj < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();      // Number of rows
        int n = grid[0].size();   // Number of columns

        // If starting or ending cell is blocked, return -1
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        // Direction vectors for 8 possible moves (horizontal, vertical, diagonal)
        vector<vector<int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1}, {1, 1}, {1, 0},
            {1, -1}, {0, -1}
        };

        // Queue to store {current_path_length, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});      // Start from (0,0) with path length 1
        grid[0][0] = 1;           // Mark start cell as visited

        // BFS traversal
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int cost = top.first;           // Current path length
            int i = top.second.first;       // Current row
            int j = top.second.second;      // Current column

            // If we reached the bottom-right cell, return the path length
            if (i == m - 1 && j == n - 1)
                return cost;

            // Explore all 8 directions
            for (auto di : dir) {
                int newi = i + di[0];
                int newj = j + di[1];

                // If the new cell is safe and unvisited (i.e., 0)
                if (isSafe(newi, newj, m, n) && grid[newi][newj] == 0) {
                    grid[newi][newj] = 1;               // Mark visited
                    q.push({cost + 1, {newi, newj}});   // Push new cell with updated path length
                }
            }
        }

        // If we exit the loop, no path was found
        return -1;
    }
};
