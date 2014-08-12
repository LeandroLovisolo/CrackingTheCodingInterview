#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

int get_height(node *tree) {
	if(tree == NULL) return 0;
	int height_left = get_height(tree->left);
	if(height_left == -1) return -1;
	int height_right = get_height(tree->right);
	if(height_right == -1) return -1;
	if(abs(height_left - height_right) > 1) return -1;
	return 1 + max(height_left, height_right);
}

bool is_balanced(node *tree) {
	return get_height(tree) != -1;
}

int main() {
	assert(is_balanced(NULL));
	assert(is_balanced(new node()));
	node *tree = new node();
	tree->left = new node();
	tree->left->left = new node();
	assert(!is_balanced(tree));
	return 0;
}