#include <iostream>

using namespace std;

struct node {
    int value;
    node *left;
    node *right;
};

bool isSearchTree(node *n) {
    if(n == NULL) return true;
    if(n->left != NULL  && n->left->value  > n->value) return false;
    if(n->right != NULL && n->right->value < n->value) return false;
    return isSearchTree(n->left) && isSearchTree(n->right);
}


int main() {
    // Binary search tree
    node *root = new node();
    root->value = 5;
    root->left = new node();
    root->left->value = 2;
    root->left->left = new node();
    root->left->left->value = 1;
    root->left->right = new node();
    root->left->right->value = 3;
    root->right = new node();
    root->right->value = 6;

    cout << isSearchTree(root) << endl;

    // Binary tree, not a binary search tree
    root = new node();
    root->value = 5;
    root->left = new node();
    root->left->value = 2;
    root->left->left = new node();
    root->left->left->value = 4;
    root->left->right = new node();
    root->left->right->value = 3;
    root->right = new node();
    root->right->value = 6; 

    cout << isSearchTree(root) << endl;
}