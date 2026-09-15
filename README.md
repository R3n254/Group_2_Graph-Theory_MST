# Minimum Spanning Tree Algorithms

## Group Members

- Ahmad Farras Favian Al Efasi - 5025251005
- Daniel Pedrosaputra - 5025251171

## 1. Algorithm Explanation

### Prim's Algorithm

Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, weighted, undirected graph.

The algorithm starts from a selected vertex and repeatedly selects the minimum-weight edge that connects a vertex inside the current tree to a vertex outside the tree.

### Kruskal's Algorithm

Kruskal's Algorithm is a greedy algorithm that finds an MST by sorting all edges in increasing order of weight.

The algorithm adds the smallest available edge as long as adding it does not create a cycle. A Disjoint Set Union (DSU) structure is used to efficiently detect cycles.

### Borůvka's Algorithm

Borůvka's Algorithm is a greedy MST algorithm that begins with every vertex as a separate component.

In each phase, every component selects its cheapest outgoing edge. These selected edges are then used to merge components. The process continues until all vertices belong to a single component.

## 2. Prerequisites

- A C++ compiler that supports C++11 or later.
- No external libraries are required.
- The programs can be run manually by entering the graph data through the terminal.

## 3. Instructions to Run the Code

The C++ implementations are located in the `src/` directory.

### Compile the Programs

Open a terminal in the root directory of the repository and run:

```bash
g++ src/prim.cpp -o prim
g++ src/kruskal.cpp -o kruskal
g++ src/boruvka.cpp -o boruvka
