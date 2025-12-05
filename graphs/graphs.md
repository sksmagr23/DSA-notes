# Graph Data Structure

### Types of Data Structures
- **Linear**: Arrays, Stacks, Queues, Linked Lists (elements arranged sequentially).
- **Non-linear**: Trees, Graphs.

### What is a Graph?
- A **graph** is a non-linear data structure consisting of:
  - **Vertices (Nodes)**: Store data.
  - **Edges**: Connections between vertices.

Example: A graph with 5 vertices.

### Types of Graphs
1. **Undirected Graph**
   - Edges are bidirectional i.e. (u, v) ≡ (v, u).
   
1. **Directed Graph**
   - Edges have direction i.e. <u, v> ≠ <v, u>.

1. **Cyclic & Acyclic**
   - **Cyclic Graph**: Contains at least one cycle (path starting and ending at same node).
   - **Acyclic Graph**: No cycles.
   - **DAG (Directed Acyclic Graph)**: Directed graph with no cycles.

### Paths in Graph
- A **path** is a sequence of vertices where consecutive vertices are connected by edges.
- Example:
  - Valid: `1 → 2 → 3 → 5`
  - Invalid:
    - `1 → 2 → 3 → 2 → 1` (node repeats)
    - `1 → 3 → 5` (missing edge between 1 and 3)

### Degree of a Graph
- **Undirected Graph**: Degree = number of edges connected to a node.
  - Property:  **Total Degree = 2 × Number of Edges**
- **Directed Graph**:
  - **Indegree** = Incoming edges.
  - **Outdegree** = Outgoing edges.

### Edge Weight
- Each edge may have a **weight** (cost, distance, time, etc.).
- If no weights are given → assume **unit weight (1)**.
- Example: In road networks, weight = travel cost between towns.

---

## Graph Representation

### Input Format
- First line: two integers `n` (nodes) and `m` (edges).
- Next `m` lines: two integers `u v` (edge between `u` and `v`).
- For **undirected graphs**: if `(u, v)` exists → `(v, u)` also exists.
- No limit on number of edges; `m` just increases.

### Ways to store graph in memory

#### 1. Adjacency Matrix
- A **2D array** of size `n × m` where `adj[i][j] = 1` if edge `(i, j)` exists, else `0`.
- For **undirected graphs**: mark both `(u, v)` and `(v, u)`.
- **Space Complexity**: `O(n²)` (costly for large sparse graphs).

```cpp
int main() {
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    int adj[n+1][n+1]; // nodes are 1-based indexed
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
```

#### 2. Adjacency List
- Each node stores a **list of its neighbors** implemented as an **array of vectors/lists**.
- **Undirected Graph**: each edge stored twice (`u→v` and `v→u`) with space complexity:- `O(2E)` (E: number of edges)
- **Directed Graph**: edge stored only once (`u→v`) with space complexity:- `O(E)`
- More efficient than adjacency matrix for **sparse graphs**.

```cpp
int main() {
    int n, m;
    cin >> n >> m;
    // adjacency list for undirected graph
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // this statement will be removed in case of directed graph
    }
    return 0;
}
```

### Weighted Graphs
- **Adjacency Matrix**: store `wt` instead of `1`.
  ```cpp
  int u, v, wt;
  cin >> u >> v >> wt;
  adj[u][v] = wt;
  adj[v][u] = wt;
  ```
- **Adjacency List**: store pairs `(neighbor, weight)`.
  ```cpp
  vector<pair<int,int>> adjList[n+1];
  ```

---

### Breadth First Search (BFS) Traversal of graph

- BFS explores the graph level by level, starting from a source node and visiting all its neighbors before moving to the next level.
- It uses a queue to keep track of nodes to visit next.
- use visited array to keep track of traversed nodes

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0); // 0-indexed nodes
        visited[0] = 1;
        queue<int> q;
        q.push(0); // starting from 0;
        vector<int> ans;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            // for neighbours
            for (int it : adj[node]){
                if (!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
```

### Depth First Search (DFS) Traversal of graph

- DFS explores as far as possible along each branch before backtracking.

```cpp
class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int> &ans) {
        visited[node] = 1;
        ans.push_back(node);
        // traverse neighbours
        for (auto it : adj[node]){
            if (!visited[it]){
                dfs(it, adj, visited, ans);
            }
        }
    }
    vector<int> dfsTraversal(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> visited(v, 0);
        vector<int> ans;
        dfs(0, adj, visited, ans); // starting from 0
        return ans;
    }
};
```

### Connected components array in an undirected graph

 - A **connected component** is a subgraph where any two vertices are connected by paths, and which is connected to no additional vertices in the main graph, as it is possible that graph is in pieces.
 - To find connected components:
   1. Perform a traversal from each unvisited node.
   2. Mark all reachable nodes as part of the same component.
   3. Repeat until all nodes are visited.

```cpp
class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<int>& visited, vector<int>& piece) {
        visited[node] = 1;
        piece.push_back(node);
        // neighbours
        for (auto nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, adj, visited, piece);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
      int m = edges.size();
      vector<int> adj[V];
      for (int i = 0; i < m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
      }
      vector<vector<int>> comp;
      vector<int> visited(V, 0);
      for (int i = 0; i < V; i++){
          if (!visited[i]){
            vector<int> piece;
            dfs(i, adj, visited, piece);
            comp.push_back(piece);
          }
      }
      return comp;
    }
};
```

### Count Provinces (Striver) - similar to connected components

```cpp
class Solution {
   public:
      void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
            vis[node] = 1; 
            for(auto it: adjLs[node]) {
                    if(!vis[it]) {
                        dfs(it, adjLs, vis); 
                    }
            }
      }
      int numProvinces(vector<vector<int>> adj, int V) {
            vector<vector<int>> adjLs(V);
            // to change adjacency matrix to list as given 0/1 matrix
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) {
                    // self nodes are not considered
                    if(adj[i][j] == 1 && i != j) {
                        adjLs[i].push_back(j); 
                        adjLs[j].push_back(i); 
                    }
                }
            }
            vector<int> vis(V, 0); 
            int cnt = 0; 
            for(int i = 0; i < V; i++) {
                // if the node is not visited
                if(!vis[i]) {
                    // counter to count the number of provinces 
                    cnt++;
                    dfs(i, adjLs, vis); 
                }
            }
            return cnt; 
      }
};
```

### Count Islands (Striver) using dfs

```cpp
class Solution {
  public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int di = -1 ; di <= 1; di++){
            for (int dj = -1; dj <= 1; dj++){
                int r = i+di;
                int c = j+dj;
                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 'L'){
                    vis[r][c] = 1;
                    dfs(r, c, grid, vis);
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 'L' && !vis[i][j]){
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};
```

### Flood Fill Algorithm (striver)

- Problem Statement: An image is represented by a 2-D array of integers, each integer representing the pixel value of the image. Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

{% raw %}
```cpp
class Solution {
public:
    void dfs(int i, int j, int color, vector<vector<int>>& image, vector<vector<int>>& ans, int original){
        ans[i][j] = color;
        int n = image.size();
        int m = image[0].size();
        vector<pair<int, int>> comb = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int k = 0; k < 4; k++){
            int r = i + comb[k].first;
            int c = j + comb[k].second;
            if (r >= 0 && r < n && c >= 0 && c < m && image[r][c] == original && ans[r][c] != color) {
                dfs(r, c, color, image, ans, original);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, color, image, ans, original);
        return ans;
    }
};
```
{% endraw %}

### Rotten oranges - BFS approach

- Problem Statement: Given an n x m grid, where each cell has the following values :
2 - represents a rotten orange , 1 - represents a Fresh orange , 0 - represents an Empty Cell .
Every minute, if a fresh orange is adjacent to a rotten orange in 4-direction ( upward, downwards, right, and left ) it becomes rotten. Return the minimum number of minutes required such that none of the cells has a Fresh Orange. If it's not possible, return -1..

{% raw %}
```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        int rotten = 0;
        int mins = 0;
        queue<pair<pair<int, int>, int>> q; // {{i, j}, time it get rotten}
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n ; i++){
            for (int j  = 0; j < m; j++) {
                if (grid[i][j] != 0) total++;
                if (grid[i][j] == 2){
                    rotten++;
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<pair<int, int>> comb = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            mins = max(mins, t);
            for (int i = 0; i < 4; i++){
                int nr = r + comb[i].first;
                int nc = c + comb[i].second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] != 2){
                    vis[nr][nc] = 2;
                    rotten++;
                    q.push({{nr, nc}, t+1});
                }
            }
        }
        return total == rotten ? mins : -1;
    }
};
```
{% endraw %}

### Cycle Detection in an Undirected Graph (DFS)

```cpp
class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, adj, vis)) return true;
            }
            else if (it != parent) return true; // visited node but not a parent node, then cycle
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[V];
        for (int i = 0; i < n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                if (dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};
```

### Distance of the nearest 1 in the grid for each cell. (BFS)

{% raw %}
```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q; // <coordinates, steps>
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (mat[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while (!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            ans[r][c] = steps;

            for (auto d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, steps+1});
                }
            }
        }

        return ans;
    }
};
```
{% endraw %}

### Surrounding Regions (DFS)

- Problem Statement: Given a 2D board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
- A region is captured by flipping all 'O's into 'X's in that surrounded region.

{% raw %}
```cpp
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++){
            int nrow = i + dr[k];
            int ncol = j + dc[k];
            if (nrow > 0 && nrow < n && ncol > 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) { // traverse first and last row
            if (!vis[0][j] && board[0][j] == 'O') dfs(0, j, vis, board);
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') dfs(n - 1, j, vis, board);
        }

        for (int i = 0; i < n; i++) { // traverse first and last column
            if (!vis[i][0] && board[i][0] == 'O') dfs(i, 0, vis, board);
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') dfs(i, m - 1, vis, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // convert enclosed 'O' to 'X'
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
```
{% endraw %}

### Word Ladder (BFS)

- Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord. Only one letter can be changed in each transformation.

{% raw %}
```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
```
{% endraw %}

### ``Bipartite Graph (BFS)``

- **A Bipartite graph is a graph which can be coloured using 2 colours such that no adjacent nodes have the same colour**.
-  Any graph with an *odd cycle* length can never be a bipartite graph.
-  Any linear graph with no cycle or any graph with an *even cycle* length will be a bipartite graph

```cpp
class Solution {
public:
    // 0/1 adjacent colouring
    bool dfs(int node, int c, vector<int> &color, vector<vector<int>>& adj){
        color[node] = c;
        for (auto it : adj[node]){
            if (color[it] == -1){ // -1 means uncoloured
                if (dfs(it, !c, color, adj) == false) return false;
            } else if (color[it] == c){ // if previously coloured and have the same colour
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) 
        int v = adj.size();
        vector<int> color(v, -1);
        for (int i = 0; i < v; i++){
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) return false; // started with 0 colour
            }
        }
        return true;
    
};
```

### Cycle Detection in a Directed Graph (DFS)

```cpp
class Solution {
public:
	bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
		vis[node] = 1;
		pathVis[node] = 1;
		for (auto it : adj[node]) {
			// when the node is not visited
			if (!vis[it]) {
				if (dfs(it, adj, vis, pathVis) == true) return true;
			}
			// if the node has been previously visited but it has to be visited on the same path
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
	
	bool isCyclic(int V, vector<vector<int>> adj) {
		vector<int> vis(V, 0);
		vector<int> pathVis(V, 0);
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				if (dfs(i, adj, vis, pathVis) == true) return true;
			}
		}
		return false;
	}
};
```

## Topological Sort Algorithm (DFS)

- Problem Statement:- Given a **Directed Acyclic Graph (DAG)** with V vertices labeled from 0 to V-1. Find any Topological Sorting of that Graph.
- *Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge from a vertex u to a vertex v (u → v), u appears before v in the ordering*.

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        // After visiting all neighbors, push this node into the stack
        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
```

### Kahn's Algorithm (BFS) for Topo Sort

- Uses indegree(number of incoming edges) - BFS approach
  
```cpp
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj) {
	    vector<int> inDegree(V, 0); // To store the In-degrees of nodes
	    for (int i=0; i<V; i++) {
            for (auto it : adj[i]) inDegree[it]++;
	    }
	    
	    queue<int> q;
	    // Add nodes with no in-degree to queue
	    for (int i=0; i<V; i++) {
            if(inDegree[i] == 0) q.push(i);
	    }
        
        vector<int> ans;
	    
	    while (!q.empty()) {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);

	        for(auto it : adj[node]) {
	            inDegree[it]--; // Decrement the in-degree of the neighbor
	            // Add the node to queue if its in-degree becomes zero
	            if(inDegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
    }
};
```
#### Cycle Detection in Directed Graph using Kahn's algo

- The key idea is that in a Directed Acyclic Graph (DAG), we can generate a valid topological ordering that includes all vertices. If there is a cycle, at least one vertex will never have an in-degree of 0, and we will not be able to process all vertices.

```cpp
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto &it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0; // Counter to track number of processed nodes

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;  // Increment processed node count

            for (auto &it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        // If processed node count is not equal to total nodes, a cycle exists
        return count != V;
    }
};
```

### Find Eventual Safe Nodes - Topo Sort

- In a directed graph, a *terminal node* is defined as a node that has no outgoing edges (i.e., its outdegree is 0). A node is a *safe node* if every possible path starting from it eventually leads to a terminal node and does not enter or contribute to any cycle. You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
- The topo sorting method naturally excludes cyclic paths, and thus helps identify nodes that are guaranteed to lead to terminal states.
- **Approach**: Topo sort generally uses indegree, whereas terminal nodes are detected using outdegree, To align this with topo sort logic, we reverse all edges in the graph so that terminal nodes become nodes with indegree 0.

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<vector<int>> adj) {
        vector<vector<int>> adjRev(V);  // Reverse adjacency list
        vector<int> indegree(V, 0);

        // Build the reverse graph and calculate indegrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);  // Reverse the direction of edges
                indegree[i]++;
            }
        }

        queue<int> q;  // Queue to store nodes with no outgoing edges (safe nodes)
        vector<int> safe;

        // Add all nodes with 0 indegree to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);  // This node is safe
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);  // If indegree becomes 0, it is a safe node
                }
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};
```

## Shortest Path in Undirected Graph with unit weight (BFS)

- Why BFS is used: All edges have unit weight. So as we explore adjacent nodes, they are at a fixed/sorted increment of distance (1, 2, 3…). This behavior naturally fits BFS because the queue automatically ensures we’re processing closer nodes first.

```cpp
class Solution {
  public:
  // Function to find the shortest path from source to all vertices
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for (auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Initialize the distance array with a large value (treated as infinity)
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto it : adj[node]){
                // If a shorter path to neighbor is found
                if (dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        vector<int> ans(V, -1);
        for (int i = 0; i < V; i++){
            if (dist[i] != 1e9) ans[i] = dist[i];
        }
        return ans;
    }
};
```

### Shortest Path in Directed Acyclic Graph

```cpp
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<int>> adj[V];
        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        
        while(q.size()){
            int node = q.front();   
            q.pop(); 
            for(auto it : adj[node]){
                int nbr = it[0] ;
                int d = it[1];
                if(dist[node] + d < dist[nbr]){
                    dist[nbr] = dist[node] + d;
                    q.push(nbr);
                }
            }
        }
        for(auto &i : dist) if (i==1e9) i = -1;
        return dist ;
    }
};
```

- ```Efficient Approach using Topo Sort with DFS```
  
  -  Processing the vertices in topological order ensures that by the time you get to a vertex, you've already processed all the vertices that can precede it which reduces the computation time significantly. 
```cpp
class Solution {
  public:
    void topoSort(int node, vector<vector<int>> adj[], vector<int> &vis, stack<int> &st) {
      vis[node] = 1;
      for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {

      vector<vector<int>> adj[V];
      for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});// Store (target node, weight)
      }

      vector<int> vis(V);
      stack<int> st;

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }

      vector<int> dist(V, 1e9);
      dist[0] = 0;

      // Process all nodes in topological order
      while (!st.empty()) {
        int node = st.top();
        st.pop();
        // Relax all outgoing edges from the current node
        for (auto it : adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < V; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};
```

## Dijkstra’s Algorithm

- In a weighted graph, the goal of Dijkstra’s algorithm is to find the shortest path from a source node to all other nodes. The idea is to always expand the closest node not yet processed.
- Using a ***priority queue (min-heap)*** ensures that we can efficiently pick the node with the smallest current distance, instead of scanning all nodes each time and taking unnecessary iterations(which in case of normal queue).

> Using Min heap Priority Queue
- The algorithm starts with the source node at distance 0. At each step, the priority queue pops the node with the smallest distance. For every neighbor of that node, if the new distance through this node is shorter than the current stored distance, we update it and push the neighbor into the priority queue. This process continues until all nodes are processed.
  
```cpp
// TC:- E.log(V)
vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Min-heap storing {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, src});// Push source into heap
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for (auto it : adj[node]) {
            int next = it.first;
            int wt = it.second;
            
            if (dist[node] + wt < dist[next]) { // Relaxation check
                dist[next] = dist[node] + wt;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}
```

* Note :- Dijkstra’s Algorithm does not work with **negative weights or negative cycles**. If negative weights are used, the distances will keep getting updated infinitely, leading to incorrect results.

> Using Sets
- A set is preferred over a priority queue because it allows easier replacement of older pairs with worse distances.
- Since sets store elements in sorted(ascending) order, the node with the smallest distance is always processed first.

```cpp
// TC:- E.log(V)
vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {

    // Create a set ds for storing the nodes as a pair {dist, node}
    set<pair<int, int>> s; 

    vector<int> dist(V, 1e9); 
    dist[s// where dist is the distance from source to the node.
    // set stores the nodes in ascending order of the distances.rc] = 0;
    s.insert({0, src}); // Insert the source node with a distance of 0.
    
    while(!s.empty()) {
        auto it = *(s.begin()); 
        int node = it.second; 
        int d = it.first; 
        s.erase(it); 
        
        for(auto it : adj[node]) {
            int nbr = it[0];
            int w = it[1];
            
            // If the new distance is smaller, update it
            if(d + w < dist[nbr]) {
                // Erase the previous entry of the adjacent node if it was visited previously with a larger cost.
                if(dist[nbr] != 1e9) st.erase({dist[nbr], nbr}); 

                dist[adjNode] = d + w; 
                st.insert({dist[adjNode], adjNode}); 
            }
        }
    }
    return dist; 
}
```

### Shortest Path in Weighted undirected graph (with printing path)

- Problem Statement: You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n, and if the path does not exist then return a list consisting of only -1.

- For path, We use here a *Parent Array* which stores the parent of each node, representing where the node came from while traversing the graph using Dijkstra’s Algorithm

```cpp
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, node}
        pq.push({0, 1});
        
        // Distance array to store shortest distances from the source node and parent array to track the path
        vector<int> dist(n+1, 1e9), parent(n+1);
        dist[1] = 0;
        for (int i = 1; i <= n ; i++) parent[i] = i; // Initialize the parent array to track the path from the source
        
        while (!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int node = i.second;
            int d = i.first;
            
            for (auto it : adj[node]){
                int nbr = it.first;
                int w = it.second;
                if (d + w < dist[nbr]) {
                    dist[nbr] = d + w;
                    pq.push({dist[nbr], nbr});
                    // Update the parent of adjNode to the current node
                    parent[nbr] = node;
                }
            }
        }
        
        if (dist[n] == 1e9) return {-1};
        
        // Store the final path in the 'path' array by backtracking from the destination node
        vector<int> path;
        int node = n;
        while (parent[node] != node){
            path.push_back(node);
            node = parent[node]; // Move to the parent node
        }
        path.push_back(1); // Add the source node to the path

        // Reverse the path to get the correct order from source to destination
        reverse(path.begin(), path.end());
        return path;
    }
};
```
