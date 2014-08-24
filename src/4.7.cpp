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

int height(node *n) {
    if(n == NULL) return 0;
    return 1 + height(n->parent);
}

node *firstCommonAncestor(node *m, node *n) {
    int mh = height(m), nh = height(n);

    while(mh != nh) {
        if(mh > nh) {
            m = m->parent;
            mh--;
        } else {
            n = n->parent;
            nh--;
        }
    }

    while(m != n) {
        m = m->parent;
        n = n->parent;
    }

    return m;
}

//            11
//        [5]
//    3           9
//  2 (4)       7   10
//            (6) 8

int main() {
    node *root = new node(11, NULL);
    root->left = new node(5, root);
    root->left->left = new node(3, root->left);
    root->left->left->left = new node(2, root->left->left);
    root->left->left->right = new node(4, root->left->left);
    root->left->right = new node(9, root->left);
    root->left->right->left = new node(7, root->left->right);
    root->left->right->left->left = new node(6, root->left->right->left);
    root->left->right->left->right = new node(8, root->left->right->left);
    root->left->right->right = new node(10, root->left->right);

    cout << firstCommonAncestor(root->left->left->right,
                                root->left->right->left->left)->value << endl;

    return 0;
}