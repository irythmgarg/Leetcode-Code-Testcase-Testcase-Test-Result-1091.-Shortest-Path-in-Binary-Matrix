# Leetcode-Code-Testcase-Testcase-Test-Result-1091.-Shortest-Path-in-Binary-Matrix
🟩 Shortest Path in Binary Matrix (Leetcode 1091)
Problem Statement:
Given an n x n binary matrix grid, return the length of the shortest clear path from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1).
You can move in 8 possible directions (including diagonals), and a path is clear if all visited cells are 0.
If there is no such path, return -1.

🚀 Approaches Covered
✅ 1. Simple BFS (Breadth-First Search)
A classic BFS traversal from (0, 0) to (n-1, n-1), marking visited cells directly in the grid. This is the most intuitive and efficient for uniform cost traversal.
Queue stores {distance, {i, j}}
Grid itself is reused for visited marking.
Early exit when we reach the destination.
Time Complexity: O(n²)
Space Complexity: O(n²)



✅ 2. BFS with Distance Matrix
A variation of BFS where instead of marking visited in the grid, we maintain a distance matrix to store the shortest distance to each cell.
Prevents redundant visits.
More flexible when tracking exact path lengths.
No grid modification.
Time Complexity: O(n²)
Space Complexity: O(n²)



✅ 3. Dijkstra’s Algorithm Style
Instead of standard BFS, we use a min-heap (priority queue) to always expand the cell with the currently shortest path cost.
This is like running Dijkstra’s Algorithm on an unweighted graph, treating every move as a cost of 1.
Useful if cell costs vary (though in this case, they don't).
Gives a clear idea of optimal path expansion.
Time Complexity: O(n² log n) due to priority queue
Space Complexity: O(n²)



🔀 When to Use What?
Approach	Modifies Grid	Uses Priority Queue	Best For
Simple BFS	✅ Yes	❌ No	Fastest and cleanest
BFS with Distance Matrix	❌ No	❌ No	Grid needs to remain intact
Dijkstra's Algorithm Style	❌ No	✅ Yes	Weighted path generalization


🧠 Key Insights
You can move in 8 directions → makes it a more complex grid traversal.
All movements have equal weight, so BFS is optimal.
Using Dijkstra's is slightly overkill here but still valid and good practice.


Input:
grid = [
  [0,1],
  [1,0]
]
Output:
2


✍️ Author
[Ridham Garg] – Happy Coding!

