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
