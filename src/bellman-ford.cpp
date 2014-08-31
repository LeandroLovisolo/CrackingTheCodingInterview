// Bellman-Ford algorithm.
// http://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm

#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

typedef vector<vector<pair<int, int>>> graph;

pair<int, int> edge(int to, int weight) {
    return make_pair(to, weight);
}

tuple<bool, vector<int>, vector<int>> bellmanFord(const graph &g, int from) {
    vector<int> predecessors(g.size(), -1);
    vector<int> distances(g.size(), INT_MAX);
    distances[from] = 0;

    for(int i = 1; i < g.size(); i++) {
        for(int u = 0; u < g.size(); u++) {
            for(pair<int, int> e : g[u]) {
                if(distances[u] == INT_MAX) continue;
                if(distances[e.first] > distances[u] + e.second) {
                    distances[e.first] = distances[u] + e.second;
                    predecessors[e.first] = u;
                }
            }
        }
    }

    for(int u = 0; u < g.size(); u++) {
        for(pair<int, int> e : g[u]) {
            if(distances[e.first] > distances[u] + e.second) {
                // Negative cycle found
                return make_tuple(false, vector<int>(), vector<int>());
            }
        }
    }

    // No negative cycles
    return make_tuple(true, predecessors, distances);
}

int main() {
    //                     5            
    //               +-+-------> +-+    
    //       +-----> |1|         |2| <-+
    //       |       +++ <---+---+-+   |
    //      6|        | +    -2        |
    //       |        | |          ^   |
    //       |        | |          |   |
    //      +++      8| |   -4     |   |
    //  +-> |0|       | +---+----+ |   |
    //  |   +++       |          | |7  |
    //  |    |        |          | |   |
    //  |    |        v          v |   |
    // 2|   7|                     |   |
    //  |    |       +-+   9     +-+   |
    //  |    +-----> |4+-------> |3|   |
    //  |            +++         +-+   |
    //  |             |          |     |
    //  +------------------------+   -3|
    //                |                |
    //                +----------------+

    graph g {{edge(1, 5),  edge(4, 7) },
             {edge(2, 5),  edge(3, -4), edge(4, 8)},
             {edge(1, -2)},
             {edge(0, 2),  edge(2, 7)},
             {edge(2, -3), edge(3, 9)}};

    tuple<bool, vector<int>, vector<int>> result = bellmanFord(g, 0);
    bool noNegativeCycles = get<0>(result);
    vector<int> predecessors = get<1>(result);
    vector<int> distances = get<2>(result);

    if(noNegativeCycles) {
        cout << "Vertex\tPredecessor\tDistance" << endl;
        for(int i = 0; i < g.size(); i++)
            cout << i << "\t" << predecessors[i] << "\t\t" << distances[i] << endl;
    } else {
        cout << "Negative cycle detected." << endl;
    }

    return 0;
}