#include <iostream>
#include <vector>
#include <algorithm>
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
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges;

    cout << "\nEnter each edge as: FROM TO WEIGHT\n";
    cout << "Example: A G 5\n\n";

    for (int i = 0; i < E; i++) {
        char from, to;
        int weight;

        cout << "Edge " << i + 1 << ": ";
        cin >> from >> to >> weight;

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

    cout << "\nKruskal's Algorithm\n\n";

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

    if (edgeCount != V - 1) {
        cout << "\nGraph is disconnected. MST cannot be formed.\n";
    } else {
        cout << "\nTotal MST cost: " << totalCost << "\n";
    }

    return 0;
}
