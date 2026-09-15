#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<Edge>> graph(V);

    cout << "\nEnter each edge as: FROM TO WEIGHT\n";
    cout << "Example: A G 5\n\n";

    for (int i = 0; i < E; i++) {
        char from, to;
        int weight;

        cout << "Edge " << i + 1 << ": ";
        cin >> from >> to >> weight;

        int u = from - 'A';
        int v = to - 'A';

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    char startVertex;

    cout << "\nEnter starting vertex for Prim's Algorithm: ";
    cin >> startVertex;

    int start = startVertex - 'A';

    vector<bool> visited(V, false);

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    pq.push({0, {start, -1}});

    int totalCost = 0;
    int edgeCount = 0;

    cout << "\nPrim's Algorithm\n";
    cout << "Starting vertex: " << startVertex << "\n\n";

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        int weight = current.first;
        int u = current.second.first;
        int parent = current.second.second;

        if (visited[u])
            continue;

        visited[u] = true;

        if (parent != -1) {
            cout << char('A' + parent)
                 << "-"
                 << char('A' + u)
                 << " = "
                 << weight << "\n";

            totalCost += weight;
            edgeCount++;
        }

        for (const auto& edge : graph[u]) {
            if (!visited[edge.to]) {
                pq.push({
                    edge.weight,
                    {edge.to, u}
                });
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
