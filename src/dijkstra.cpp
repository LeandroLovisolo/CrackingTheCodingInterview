// Dijkstra's algorithm.
// http://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Types used to interact with the algorithm
typedef pair<int, int> edge;
typedef vector<vector<edge>> graph;
typedef vector<int> predecessors;
typedef vector<int> distances;

int minDistance(const distances &ds, const vector<bool> &processed) {
    int min_distance = INT_MAX, min_distance_index;

    for(int i = 0; i < ds.size(); i++) {
        if(!processed[i] && ds[i] < min_distance) {
            min_distance_index = i;
        }
    }

    return min_distance_index;
}

pair<predecessors, distances> dijkstra(const graph &g, int from) {
    predecessors ps(g.size(), -1);
    distances ds(g.size(), INT_MAX);
    ds[from] = 0;

    vector<bool> processed(g.size(), false);

    for(int i = 0; i < g.size(); i++) {
        int v = minDistance(ds, processed);
        processed[v] = true;

        for(edge e : g[v]) {
            if(ds[e.first] > ds[v] + e.second) {
                ds[e.first] = ds[v] + e.second;
                ps[e.first] = v;
            }
        }
    }

    return {ps, ds};
}

int main() {
    //                                  
    //               +-+   1     +-+    
    //       +-----> |1+-------> |2| <-+
    //       |       +-+         +-+   |
    //     10|       |           |     |
    //       |       | ^         | ^   |
    //       |       | |         | |   |
    //      +++      | |         | |   |
    //  +-> |0|     2| |3       4| |6  |
    //  |   +++      | |         | |   |
    //  |    |       | |         | |   |
    //  |    |       v |         v |   |
    // 7|   5|         |           |   |
    //  |    |       +-+   2     +-+   |
    //  |    +-----> |4+-------> |3|   |
    //  |            +++         +-+   |
    //  |             |          |     |
    //  +------------------------+    9|
    //                |                |
    //                +----------------+

    graph g {{{1, 10}, {4, 5}},
             {{2, 1},  {4, 2}},
             {{3, 4}},
             {{0, 7},  {2, 6}},
             {{1, 3},  {2, 9}, {3, 2}}};

    pair<predecessors, distances> result = dijkstra(g, 0);
    predecessors ps = result.first;
    distances ds = result.second;

    cout << "Vertex\tPredecessor\tDistance" << endl;
    for(int i = 0; i < g.size(); i++)
        cout << i << "\t" << ps[i] << "\t\t" << ds[i] << endl;

    return 0;
}