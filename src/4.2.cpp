#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

struct node {
	int value;
	vector<node*> edges;
};

unordered_set<node*> visited;

bool are_connected(node *x, node *y) {
	if(visited.find(x) != visited.end()) return false;
	visited.insert(x);
	if(x == y) return true;
	for(node *edge : x->edges) {
		if(are_connected(edge, y)) return true;
	}
	return false;
}

int main() {
	node *a = new node(),
	     *b = new node(),
	     *c = new node(),
	     *d = new node(),
	     *e = new node();

	a->edges.push_back(b);
	a->edges.push_back(c);
	b->edges.push_back(c);
	b->edges.push_back(d);
	d->edges.push_back(e);
	e->edges.push_back(b);

	assert(are_connected(a, e));

	visited.clear();

	assert(!are_connected(e, a));

	return 0;
}