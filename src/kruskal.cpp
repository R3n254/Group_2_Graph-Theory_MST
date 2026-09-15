#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rankValue;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return false;
        }

        if (rankValue[a] < rankValue[b]) {
            swap(a, b);
        }

        parent[b] = a;

        if (rankValue[a] == rankValue[b]) {
            rankValue[a]++;
        }

        return true;
    }
};

int main() {
    ifstream file("input/sample.txt");

    if (!file) {
        cerr << "Error: Could not open input/sample.txt\n";
        return 1;
    }

    int V, E;
    file >> V >> E;

    vector<Edge> edges;

    for (int i = 0; i < E; i++) {
        char from, to;
        int weight;

        file >> from >> to >> weight;

        edges.push_back({
            from - 'A',
            to - 'A',
            weight
        });
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);

    int totalCost = 0;
    int edgeCount = 0;

    cout << "Kruskal's Algorithm\n\n";

    for (const auto& edge : edges) {
        if (ds.unite(edge.u, edge.v)) {
            cout << char('A' + edge.u)
                 << "-"
                 << char('A' + edge.v)
                 << " = "
                 << edge.weight
                 << " (Accepted)\n";

            totalCost += edge.weight;
            edgeCount++;

            if (edgeCount == V - 1) {
                break;
            }
        }
    }

    cout << "\nTotal MST cost: " << totalCost << '\n';

    return 0;
}
