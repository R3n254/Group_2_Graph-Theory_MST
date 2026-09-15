#include <iostream>
#include <vector>
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

    DisjointSet ds(V);

    int totalCost = 0;
    int components = V;
    int phase = 1;
    int edgeCount = 0;

    cout << "\nBoruvka's Algorithm\n\n";

    while (components > 1) {
        vector<int> cheapest(V, -1);

        // Find cheapest outgoing edge for each component
        for (int i = 0; i < E; i++) {
            int u = edges[i].u;
            int v = edges[i].v;

            int setU = ds.find(u);
            int setV = ds.find(v);

            if (setU == setV)
                continue;

            if (cheapest[setU] == -1 ||
                edges[i].weight < edges[cheapest[setU]].weight) {
                cheapest[setU] = i;
            }

            if (cheapest[setV] == -1 ||
                edges[i].weight < edges[cheapest[setV]].weight) {
                cheapest[setV] = i;
            }
        }

        cout << "Phase " << phase << ":\n";

        bool merged = false;

        for (int i = 0; i < V; i++) {
            if (cheapest[i] == -1)
                continue;

            Edge edge = edges[cheapest[i]];

            int setU = ds.find(edge.u);
            int setV = ds.find(edge.v);

            if (setU == setV)
                continue;

            if (ds.unite(setU, setV)) {
                cout << char('A' + edge.u)
                     << "-"
                     << char('A' + edge.v)
                     << " = "
                     << edge.weight
                     << " (Accepted)\n";

                totalCost += edge.weight;
                components--;
                edgeCount++;
                merged = true;
            }
        }

        if (!merged) {
            cout << "\nGraph is disconnected. MST cannot be formed.\n";
            return 1;
        }

        cout << "\n";
        phase++;
    }

    cout << "Total MST cost: " << totalCost << "\n";

    return 0;
}
