# Minimum Spanning Tree Algorithms

### Group Members

| No. | Name | NRP |
|---:|---|---|
| 1 | Ahmad Farras Favian Al Efasi | 5025251005 |
| 2 | Daniel Pedrosaputra | 5025251171 |

---

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

* C++ compiler supporting C++11 or later
* No external libraries are required
* A terminal or command prompt
* The programs accept graph data through manual terminal input


---

## 3. Instructions
3.1 Compile the Programs

Open a terminal in the repository folder and run:

g++ src/prim.cpp -o prim
g++ src/kruskal.cpp -o kruskal
g++ src/boruvka.cpp -o boruvka
3.2 Run Prim's Algorithm
./prim

On Windows:

prim.exe

The program will ask for:

Number of vertices
Number of edges
Each edge in the format FROM TO WEIGHT
Starting vertex

Example:

7
9
A G 5
C B 5
F E 5
E D 5
G F 6
A C 6
C E 7
B D 8
A D 10
A
3.3 Run Kruskal's Algorithm
./kruskal

On Windows:

kruskal.exe

Enter the number of vertices, number of edges, and each edge in the format:

FROM TO WEIGHT
3.4 Run Borůvka's Algorithm
./boruvka

On Windows:

boruvka.exe

Enter the number of vertices, number of edges, and each edge in the format:

FROM TO WEIGHT

### Kruskal's Algorithm

```bash
python src/kruskal.py
```

### Borůvka's Algorithm

```bash
python src/boruvka.py
```

---

## 4. Sample Run Result

### 4.1 Prim's Algorithm

For the sample graph, using vertex `A` as the starting vertex:

```text
Prim's Algorithm
Starting vertex: A

A-G = 5
G-F = 6
F-E = 5
E-D = 5
A-C = 6
C-B = 5

Total MST cost: 32
```

### 4.2 Kruskal's Algorithm

```text
Kruskal's Algorithm

A-G = 5 (Accepted)
C-B = 5 (Accepted)
F-E = 5 (Accepted)
E-D = 5 (Accepted)
G-F = 6 (Accepted)
A-C = 6 (Accepted)

Total MST cost: 32
```

### 4.3 Borůvka's Algorithm

```text
Boruvka's Algorithm

Phase 1:
A-G = 5 (Accepted)
B-C = 5 (Accepted)
D-E = 5 (Accepted)
E-F = 5 (Accepted)

Phase 2:
G-F = 6 (Accepted)
C-A = 6 (Accepted)

Total MST cost: 32
```

### 4.4 Failure Simulation

| Condition        | MST Total Cost |
| ---------------- | -------------: |
| Original Graph   |             32 |
| Edge A-G Failure |             34 |
| Node G Failure   |             28 |


---

## 5. AI Tools Usage Disclosure

**Tool:** ChatGPT

AI was used during the preparation of this assignment to help understand the assignment requirements and to determine whether Borůvka's Algorithm was suitable as the additional MST algorithm.

### Prompts Used

1. "Explain to me what I must do for the assignment [Refurbished W2 Tree and Spanning.pdf]."

2. "Is Boruvka's Algorithm usable in this case?"

3. "Make a readme file for the repository based on this report [group_2.pdf]."

4. "help me make the c++ solution for the algorithms."

---

