// Bellman-Ford algorithm.
// http://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm

#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

typedef pair<int, int> edge;
typedef vector<vector<edge>> graph;
typedef vector<int> predecessors;
typedef vector<int> distances;

tuple<bool, predecessors, distances> bellmanFord(const graph &g, int from) {
    predecessors ps(g.size(), -1);
    distances ds(g.size(), INT_MAX);
    ds[from] = 0;

    for(int i = 1; i < g.size(); i++) {
        for(int u = 0; u < g.size(); u++) {
            if(ds[u] == INT_MAX) continue;
            for(edge e : g[u]) {
                if(ds[e.first] > ds[u] + e.second) {
                    ds[e.first] = ds[u] + e.second;
                    ps[e.first] = u;
                }
            }
        }
    }

    for(int u = 0; u < g.size(); u++) {
        for(edge e : g[u]) {
            if(ds[e.first] > ds[u] + e.second) {
                // Negative cycle found
                return make_tuple(false, vector<int>(), vector<int>());
            }
        }
    }

    // No negative cycles
    return make_tuple(true, ps, ds);
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

    graph g {{{1, 5},  {4, 7}},
             {{2, 5},  {3, -4}, {4, 8}},
             {{1, -2}},
             {{0, 2},  {2, 7}},
             {{2, -3}, {3, 9}}};

    tuple<bool, predecessors, distances> result = bellmanFord(g, 0);
    bool noNegativeCycles = get<0>(result);
    predecessors ps = get<1>(result);
    distances ds = get<2>(result);

    if(noNegativeCycles) {
        cout << "Vertex\tPredecessor\tDistance" << endl;
        for(int i = 0; i < g.size(); i++)
            cout << i << "\t" << ps[i] << "\t\t" << ds[i] << endl;
    } else {
        cout << "Negative cycle detected." << endl;
    }

    return 0;
}