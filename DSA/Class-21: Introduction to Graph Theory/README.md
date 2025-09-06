# 📘 Basics of Graph Theory

## 1. Introduction

Graph theory is a branch of mathematics and computer science that studies relationships between objects.  
A graph consists of a set of vertices (nodes) connected by edges (links).

Graphs are widely used to model real-life systems such as:

- Social networks (people as vertices, friendships as edges).
- Road maps (cities as vertices, roads as edges).
- Computer networks (devices as vertices, connections as edges).

## 2. Fundamental Definitions

### 2.1 Graph

A graph G is defined as:  
**G = (V, E)**

where:

- V is the set of vertices.
- E is the set of edges, which are pairs of vertices.

### 2.2 Vertex (Node)

A vertex represents an object.  
Example: in a social network, each user is a vertex.

### 2.3 Edge

An edge represents a relationship or connection between two vertices.

Types of edges:

- **Undirected edge**: connection works both ways.
- **Directed edge (arc)**: connection has a direction (from one vertex to another).

### 2.4 Degree

Degree of a vertex = number of edges incident to it.

In directed graphs:

- **In-degree**: number of incoming edges.
- **Out-degree**: number of outgoing edges.

### 2.5 Path

A path is a sequence of vertices connected by edges.  
Example: `A → B → C → D`.

### 2.6 Cycle

A cycle is a path that starts and ends at the same vertex, without repeating edges or vertices (except the start/end).

### 2.7 Connected Components

A connected component is a part of a graph where every vertex is reachable from every other vertex within that part.

## 3. Types of Graphs

### 3.1 Undirected Graph

Edges have no direction.  
Example: friendship (if A is friend with B, then B is friend with A).

### 3.2 Directed Graph (Digraph)

Edges have a direction.  
Example: following on Twitter (A follows B does not mean B follows A).

### 3.3 Weighted Graph

Edges have weights/costs.  
Example: roads between cities with distances as weights.

### 3.4 Simple Graph

- No self-loops (edge from a vertex to itself).
- No multiple edges between the same pair of vertices.

### 3.5 Multigraph

Multiple edges allowed between the same pair of vertices.

### 3.6 Pseudograph

Multiple edges and self-loops are allowed.

### 3.7 2D Grid

Grid-like graph.

## 4. Special Graphs

### 4.1 Complete Graph

Every pair of vertices is connected by a unique edge.  
A complete graph with `n` vertices has: **n × (n-1) / 2** edges (undirected).

### 4.2 Bipartite Graph

- Vertices can be divided into two disjoint sets U and V.
- Every edge connects a vertex in U to one in V.
- No edge connects vertices within the same set.

### 4.3 Tree

A connected acyclic graph.

Properties:

- If there are `n` vertices, it has exactly `n-1` edges.
- There is a unique path between any two vertices.

### 4.4 Subgraph

A smaller graph formed from a subset of vertices and edges of a graph.

### 4.5 Connected Graph

A graph is connected if there exists a path between every pair of vertices.

### 4.6 Disconnected Graph

Some vertices cannot be reached from others (graph has multiple components).

## 5. Graph Representation

### 5.1 Adjacency Matrix

- A 2D matrix of size `V × V`.
- Entry `M[i][j] = 1` if an edge exists between vertex `i` and `j`, otherwise `0`.
- Space complexity: `O(V^2)`.
- Good for dense graphs.

**Code:**

```cpp
#include<bits/stdc++.h>
using namespace std;
int adjMat[1000][1000];
int main()
{
    int n, m;
    cin >> n >> m;
    for ( int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v; // u = 1, v = 2
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= n; j++ ) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    while(true) {
        int u, v;
        cin >> u >> v;
        if ( adjMat[u][v] == 1 ) {
            cout << "Edge exists" << endl;
        }
        else {
            cout << "Edge does not exist" << endl;
        }
    }
    return 0;
}
```

### 5.2 Adjacency List

- For each vertex, store a list of its neighbors.
- Space complexity: `O(V + E)`.
- Good for sparse graphs.

**Code:**

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // 1, 2

        adj[u].push_back(v); // 1 -> 2
        adj[v].push_back(u); // 2 -> 1
    }

    for ( int i = 1; i <= n; i++ ) {
        cout << i << " : ";
        for ( auto u : adj[i] ) {
            cout << u << " ";
        }
        cout << endl;
    }

    return 0;
}
```

### 5.3 Edge List

- Store all edges as a list of pairs `(u, v)`.
- Useful in algorithms like Kruskal’s MST.

**Code:**

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
        edges.push_back({v, u});
    }

    return 0;
}
```

### 5.4 Grid

**Code:**

```cpp
#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
```

## 6. Real-Life Applications of Graphs

- **Social Networks** → People and friendships.
- **Transportation Systems** → Cities and roads.
- **Web Graph** → Websites and hyperlinks.
- **Computer Networks** → Routers and connections.
- **Biological Networks** → Genes, proteins, and their interactions.

## 7. Summary

- A graph is a collection of vertices and edges.
- Important terms: vertex, edge, degree, path, cycle, connected component.
- Graph types: directed, undirected, weighted, unweighted, simple, multigraph.
- Special graphs: complete, bipartite, tree.
- Representations: adjacency matrix, adjacency list, edge list.
- Graphs are powerful models to represent and solve real-world problems.
