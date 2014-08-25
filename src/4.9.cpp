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

void printPathsFromNodeThatSum(node *n, node *start, int x, int partialSum) {
    if(n == NULL) return;
    if(n->value + partialSum == x) {
        node *current = n;
        while(current != start) {
            cout << current->value << " ";
            current = current->parent;
        }
        cout << current->value << endl;
    }
    printPathsFromNodeThatSum(n->left,  start, x, partialSum + n->value);
    printPathsFromNodeThatSum(n->right, start, x, partialSum + n->value);
}

void printPathsThatSum(node *n, int x) {
    if(n == NULL) return;
    printPathsFromNodeThatSum(n, n, x, 0);
    if(n->left != NULL) printPathsThatSum(n->left, x);
    if(n->right != NULL) printPathsThatSum(n->right, x);
}

//            2
//        1         3
//    6
// 2    -2


int main() {
    node *root = new node(2, NULL);
    root->left = new node(1, root);
    root->left->left = new node(6, root->left);
    root->left->left->left = new node(2, root->left->left);
    root->left->left->right = new node(-2, root->left->left);
    root->right = new node(3, root);

    printPathsThatSum(root, 5);

    return 0;
}