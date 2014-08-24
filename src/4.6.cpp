#include <iostream>

using namespace std;


struct node {
	int value;
	node *parent;
	node *left;
	node *right;

	node(int value, node *parent) {
		this->value = value;
		this->parent = parent;
		this->left = NULL;
		this->right = NULL;
	}
};

node *findLeftmost(node *n) {
	if(n->left == NULL) return n;
	return findLeftmost(n->left);
}

node *findNext(node *n) {
	if(n == NULL) return NULL;
	if(n->right != NULL) return findLeftmost(n->right);

	node *current = n;
	while(current->parent != NULL && current->parent->left != current) {
		current = current->parent;
	}
	return current->parent;
}

int main() {
	node *root = new node(5, NULL);
	root->value = 5;
	root->left = new node(3, root);
	root->left->left = new node(2, root->left);
	root->left->right = new node(4, root->left);
	root->right = new node(8, root);
	root->right->left = new node(6, root->right);
	root->right->right = new node(9, root->right);

	node *current = findLeftmost(root);
	while(current != NULL) {
		cout << current->value << " " << flush;
		current = findNext(current);
	}
	cout << endl;

	return 0;
}