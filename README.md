# Minimum Spanning Tree Algorithms


### Group Members

| No. | Name                         | Student ID   |
| --: | ---------------------------- | ------------ |
|   1 | Ahmad Farras Favian Al Efasi | 5025251005   |
|   2 | Daniel Pedrosaputra          | 5025251171   |


## 1. Algorithm Explanation

### Prim's Algorithm

Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, connected, undirected graph.

It starts from a selected vertex and gradually grows the spanning tree by choosing the minimum-weight edge that connects a vertex inside the tree to a vertex outside the tree. A Min-Priority Queue can be used to efficiently select the edge with the smallest weight.

### Kruskal's Algorithm

Kruskal's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree of a weighted graph.

Instead of starting from a particular vertex, it considers all edges in increasing order of their weights. The algorithm adds an edge to the MST if adding it does not create a cycle. A Disjoint Set Union (DSU) or Union-Find data structure can be used to efficiently detect whether adding an edge would create a cycle.

### Borůvka's Algorithm

Borůvka's Algorithm is another greedy algorithm for finding a Minimum Spanning Tree.

It initially treats every vertex as a separate component. In each phase, every component selects its cheapest outgoing edge. The selected edges are then added to the MST, merging multiple components together. This process is repeated until only one connected component remains.

---

## 2. Prerequisites

- A C++ compiler that supports C++11 or later.
- No external libraries are required.
- The programs can be run manually by entering the graph data through the terminal.

---

## 3. Instructions to Run the Code

The C++ implementations are located in the `src/` directory.

The programs accept graph input manually through the terminal.

### Compile the Programs

Open a terminal in the root directory of the repository and run:

```bash
g++ src/prim.cpp -o prim
g++ src/kruskal.cpp -o kruskal
g++ src/boruvka.cpp -o boruvka

## 4. Result of Sample Run

For the original graph, all three algorithms produce a valid Minimum Spanning Tree with a total cost of **32**.

### Prim's Algorithm

Starting vertex: **A**

Selected edges:

1. A–G (5)
2. G–F (6)
3. F–E (5)
4. E–D (5)
5. A–C (6)
6. C–B (5)

**Total MST cost: 32**

### Kruskal's Algorithm

Accepted edges:

1. A–G (5)
2. C–B (5)
3. F–E (5)
4. E–D (5)
5. G–F (6)
6. A–C (6)

**Total MST cost: 32**

### Borůvka's Algorithm

Borůvka's Algorithm completes in two phases.

The final MST contains six edges with a total cost of:

**Total MST cost: 32**

### Failure Simulation

| Problem         | Prim's | Kruskal's | Borůvka's |
| --------------- | -----: | --------: | --------: |
| Original graph  |     32 |        32 |        32 |
| Edge A–G failed |     34 |        34 |        34 |
| Node G failed   |     28 |        28 |        28 |

#### Edge Failure: A–G

When edge A–G with weight 5 is unavailable, the failed edge is removed from the graph. The algorithms then reconstruct an MST using the remaining edges.

One valid replacement MST is:

* C–B (5)
* F–E (5)
* E–D (5)
* G–F (6)
* A–C (6)
* C–E (7)

**Total cost: 34**

#### Node Failure: G

When vertex G fails, vertex G and all edges incident to it are removed from the graph.

The remaining vertices are A, B, C, D, E, and F.

One valid MST is:

* C–B (5)
* F–E (5)
* E–D (5)
* A–C (6)
* C–E (7)

**Total cost: 28**

---

## 5. AI Tools Usage Disclosure

**AI Tool:** ChatGPT

AI was used during the preparation of this assignment to help understand the assignment requirements and to determine whether Borůvka's Algorithm was suitable as the additional MST algorithm.

### Prompts Used

1. "Explain to me what I must do for the assignment [Refurbished W2 Tree and Spanning.pdf]."

2. "Is Boruvka's Algorithm usable in this case?"

3. "Make a readme file for my repository based on this report [ Group_2.pdf]."
   
4. "help me build the c++ solution and input samples for each algorithm."
