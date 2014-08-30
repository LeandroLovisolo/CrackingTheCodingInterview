// Breadth-first search algorithm.
// http://en.wikipedia.org/wiki/Breadth-first_search

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef vector<vector<int>> graph;

vector<int> bfs(const graph &g, int start) {
    vector<int> parents(g.size(), INT_MAX);
    queue<int> q;
    
    parents[start] = -1;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int w : g[v]) {
            if(parents[w] == INT_MAX) {
                q.push(w);
                parents[w] = v;
            }
        }
    }

    return parents;
}

int main() {
    // 0-1 2-3
    // | |/|/|
    // 4 5-6-7
    graph g {{1, 4},
             {0, 5},
             {3, 5, 6},
             {2, 6, 7},
             {0},
             {1, 2, 6},
             {2, 3, 5, 7},
             {3, 6}};
    int start = 1;

    vector<int> parents = bfs(g, start);

    for(int i = 0; i < parents.size(); i++) {
        cout << "Shortest path from " << i << " to " << start << ": ";
        for(int current = i; current != -1; current = parents[current])
            cout << current << " ";
        cout << endl;
    }

    return 0;
}