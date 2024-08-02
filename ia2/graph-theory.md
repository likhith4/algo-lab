## 1. Explain tree and its properties with an example
A tree is a fundamental concept in graph theory , defined as connected acyclic grah. This means that a tree is a collection of nodes(or vertices) connected by edges, where there are no cycles, and there is one path between any two nodes.
### Properties of Trees:
1. Connectedness: every pair of vertices is connected by exactly one path.
2. Acyclic : there are no cycles in a tree, ensureing that no code can be revisited once it has been traversed.
3. Edges and vertices relationship : for a tree with N vertices. the number of edges E is always N-1. THis property is crucial for maintaining the acyclic nature of the structure.
4. Root and leaves: in a rooted tree , one vertex is designated as the root. Nodes with no children are referred toa s leaf nodes.
5. Height and depth: the height of a tree is defined as the maximum number of edges on the longest path from the root to a leaf. The depth of a node is the number of edges from the root to that node.
### Example of a tree.
```
        A
       / \
      B   C
     / \   \
    D   E   F
```
## 2. Explain labeled tree and unlabeled tree with an example .
Trees can be classified into two main types called as labeled and unlabeled 
### Labeled Trees:
A labeled tree is definde as a tree in which each vertex is assigned a unique identifier or label. These labels can be numbers, letters, or any distict markers that differentiate one vertex from another. The labelling allows for a clear identification of the vertices, which is essential when analyzing properties or performing operations on the tree.
#### Properties of Labeled Tree:
1. Unique Identifies: each vertex has a distinct label, making it possible to differentiate between them.
2. Counting labeled trees: the number of distinct labeled trees that can be formed with n  vertices is given by Cayley's formula which states that there are n^(n-2) labeld trees for n vertices. FOr example n=3 there are 3^(3-2)=3 labeled trees.
#### Example of labeled tree:
```
    1
   / \
  2   3
```
### Unlabeled Trees:
An unlabeled tree, in contrast is a tree where the vertices don't have unique identifiers. The focus is on the structure of the tree rather than the specific identities of the vertices. In this coase , two trees are considererd the same if they can be transformed into one another  by renaming the vertices.
#### Properties of Unlabeled trees:
1. No unique identifiers
2. Counting unlabeled trees: the number of distinct unlabeled trees with n vertices can be more complex to determine and is ofteorn given by the nth catlan number .
#### Example of unlabeled tree:
```
    *   -- here astrisks means they 
   / \      are not labeled. the 
  *   *       structure remains the
  same but we can't distinguish between the vertices.
```
## 3. What is a spanning tree and find the Minimum Spanning Tree by taking an example.
A spanning tree is a subset of a connected, undirected graph that includes all the vertices of the graph and is acyclic , meaniing it doesn't contain any cycles. A spanning tree connects all the vertices withthe minimum number of edges, which is exactly n-1 wehre n is the number of vertices in the graph.
- A minimum spanning tree(MST) is a special type of spanning tree that minimizes the total edge weight, ensuring that the sum of the weights of the edges in the tree is small as possible.
### Example Graph(MST):
```
    A
   /|\
  1 | 3
 /  |  \
B---C---D
| 2 | 4 |
 \  |   /
  5 | 6
   \|/
    E
```
### Finding the Minimum Spanning Tree
1. Sort all the  edges in increasing order of their weights.
2. Pick the smallest edge. fi it does't form a cycle with the edes already included in the MST, add it to the MST.
3. Repeat until n-1 edges in the MST

### Step-by-Step Process
Sorted Edges:
1. A-B: 1
2. B-C: 2
3. A-C: 3
4. A-D: 4
5. B-E: 5
6. C-D: 6
Select Edges:
- Add A-B (1): No cycle, include it.
- Add B-C (2): No cycle, include it.
- Add A-C (3): No cycle, include it.
- Add A-D (4): No cycle, include it.
- Skip B-E (5): Adding this edge would create a cycle with A-B and B-C.
- Skip C-D (6): Adding this edge would create a cycle with A-C and A-D.
Final MST Edges:
```
    A-B (1)
    B-C (2)
    A-C (3)
    A-D (4)
    Total weight = 1+2+3+4=10;
```
```
    A
   /|\
  1 | 3
 /  |  
B---C   
| 2 |  
 \  |   
  5 |  
   \|/
    E
```

## 4. Explain cut vertex and cut edge with an example.
### Cut Vertex:
A cut vertex in a connected graph is a vertex that, when removed along with its incident edges, increases the number of connected components in the graph. In simpler terms , if the removal of vertex disconnects the graph, that vertex is termed as cut vertex.
### Example for Cut Vertex:
```
    A
   / \
  B   C
   \ /
    D
   / \
  E   F
  Analysis:
  - if we remove the vertex D, the graph becomes disconnected. Vertices A,B,C form one compoint while E and F form another 
  - Therefore , D is a cut vertex.
```
### Cut Edge:
A cut edge ( or a bridge) is an edge in  a connected graph that, when removed, increases the number of connected components. In other words, if the removal of an edge disconnects the graph , that edge is a cut edge.
### Example for Cut Edge:
```
    A
   / \
  B   C
   \ /
    D
   / \
  E   F
  
  Analysis: 
    - if we remove the edge (B,D) the graph remoins connected because there are still paths between the vertices.
    - However , if we remove the edge (D,E) the graph becomes disconnected seperating E from the rest.
    - Therefore D,E is a cut edge.
```
## 5. Explain different representations of planar graphs.
Planar graphs are graph that can be drawn on a two dimensional plane without any edges crossing each other. Understanding the differnt representations of planar  graphs is essential for visualizing their structure and properties. The various representations are Geometric, Combinatorial, and Dual representation.
### 1. Geometric Representation:
In a geometric representation, a planar graph is depicted in a way that emphasizes its vertices and edges on a plane. This representation allows for a clear visualization of the graph's  structuer, ensuring that no edges intersect except at their  enpoints.
- Example:
```
    A
   / \
  B---C
   \ /
    D
```
### 2. Combinatorial Representation:
A combinatorial representation focuses on the relationships between vertices and edges withour necessarily providing a visual layout. This can be done using adjacency lsits or adjacecy matrices.
#### Adjacency List Example:
For a graph above , the adjacency list would look like this:
- A: B,C
- B: A,C,D
- C: A,B,D
- D: B,C
#### Adjacency Matrix Example:
```
        A B C D
    A [ 0 1 1 0 ]
    B [ 1 0 1 1 ]
    C [ 1 1 0 1 ]
    D [ 0 1 1 0 ]
```
### 3. Dual Representaion:
The dual representaion of a planar graph innvolves creating a new graph where each face of the original graph corresponds to a vertex in the duall graph . An edge exists betwee two vertices in the dual graph if and only if the corresponding faces in the original graph share a boundary.
#### Example:
```
    A
   / \
  B---C
   \ /
    D
    The faces (regions) are:
    Face 1: The area around A, B, C, and D (the outer region).
    Face 2: The area enclosed by A, B, and C.
    Face 3: The area enclosed by B, C, and D.
    Face 4: The area enclosed by A, C, and D.
    Face 5: The area enclosed by A, B, a
```
## 6. Explain pendent vertex, distance and center in a tree.
### Pendent Vertex:
A pendent vertex(also known as leaf) is a vertex in tree that has a degree of 1. This means it is connected to only one other vertex. Pendent vertices are significant in tree structures as they often represent endpoints or terminal nodes.
### Example for Pendent Vertex.
```
    A
   / \
  B   C
   \ 
    D
   / \
  E   F

  Here the pendent vertices are C,E,F.
```
### Distance:
The distance between two vertices in a tree is defined as the number of edges in the shortest path connecting them. In a tree, there is exactly one unique path between any two vertices , making the calculation straightforward.
### Example for Distance:
using the same tree the distance from A and D is 2 (A-->B-->D)
- The distance between E and C is 3 (E to D to B to A to C).
### Center:
The center of a tree is defined as the set of vertices with the minimum eccentricity. The eccentricity of a vertex is the greatest distance from the vertex to any other vertex in the tree. The center can consist of one  or two vertices. depending on the structure of the tree.
### Finding the center:
1. Calculate the eccentricity: for each vertex , determine teh maximum distance  to any other vertex.
2. Identify the center: the vertices with the minimm eccentricity are  the center
### Example:

```
Continuing with the previous tree:
1.Eccentricity Calculation:
- For vertex A: Maximum distance is 3 (to E or F).
- For vertex B: Maximum distance is 2 (to E or F).
- For vertex C: Maximum distance is 2 (to E or F).
- For vertex D: Maximum distance is 2 (to C).
- For vertex E: Maximum distance is 3 (to A).
- For vertex F: Maximum distance is 3 (to A).
2. Minimum Eccentricity: The minimum eccentricity is 2, which corresponds to vertices B, C, and D.
- Thus, the center of this tree consists of vertices B, C, and D.
```