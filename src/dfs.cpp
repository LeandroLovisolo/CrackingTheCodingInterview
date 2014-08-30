// Depth-first search algorithm.
// http://en.wikipedia.org/wiki/Depth-first_search

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> graph;

void visit(int v, const graph &g, vector<int> &visited, vector<int> &order) {
    visited[v] = true;
    order.push_back(v);
    for(int w : g[v]) {
        if(!visited[w]) visit(w, g, visited, order);
    }
}

vector<int> dfs(const graph &g) {
    vector<int> visited(g.size(), false);
    vector<int> order;

    for(int v = 0; v < g.size(); v++) {
        if(!visited[v]) visit(v, g, visited, order);
    }

    return order;
}

int main() {
    // 0-1 2-3 8
    // | |/|/| |
    // 4 5-6-7 9
    graph g {{1, 4},
             {0, 5},
             {3, 5, 6},
             {2, 6, 7},
             {0},
             {1, 2, 6},
             {2, 3, 5, 7},
             {3, 6},
             {9},
             {8}};

    vector<int> order = dfs(g);

    cout << "DFS order traversal: ";
    for(int v : order) cout << v << " ";
    cout << endl;

    return 0;
}