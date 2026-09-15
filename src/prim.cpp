#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    ifstream file("input/sample.txt");

    if (!file) {
        cerr << "Error: Could not open input/sample.txt\n";
        return 1;
    }

    int V, E;
    file >> V >> E;

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < E; i++) {
        char from, to;
        int weight;

        file >> from >> to >> weight;

        int u = from - 'A';
        int v = to - 'A';

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    vector<bool> visited(V, false);

    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    int start = 0; // Start from vertex A

    pq.push({0, {start, -1}});

    int totalCost = 0;

    cout << "Prim's Algorithm\n";
    cout << "Starting vertex: A\n\n";

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
                 << " = " << weight << '\n';

            totalCost += weight;
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

    cout << "\nTotal MST cost: " << totalCost << '\n';

    return 0;
}
