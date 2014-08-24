#include <iostream>
#include <vector>

using namespace std;

struct node {
    int value;
    node *next;
};

void partition_list(node *list, int x) {
    node *first_smaller = NULL,
         *last_smaller = NULL,
         *first_greater_or_equal = NULL,
         *last_greater_or_equal = NULL,
         *head = list;

    while(list != NULL) {
        if(list->value < x) {
            if(first_smaller == NULL) {
                first_smaller = list;
                last_smaller = list;
            } else {
                last_smaller->next = list;
                last_smaller = list;
            }
        } else {
            if(first_greater_or_equal == NULL) {
                first_greater_or_equal = list;
                last_greater_or_equal = list;
            } else {
                last_greater_or_equal->next = list;
                last_greater_or_equal = list;
            }
        }
        list = list->next;
    }

    if(head != first_smaller) {
        int head_value = head->value;
        node *head_next = head->next;
        head->value = first_smaller->value;
        head->next = first_smaller->next;
        first_smaller->value = head_value;
        first_smaller->next = head_next;
        first_greater_or_equal = first_smaller;
        first_smaller = head;
    }

    last_smaller->next = first_greater_or_equal;
    last_greater_or_equal->next = NULL;
}

node* vector_to_list(const vector<int> &v) {
    node *list = NULL, *prev = NULL;
    for(int i = 0; i < v.size(); i++) {
        node *current = new node;
        current->value = v[i];
        current->next = NULL;
        if(prev == NULL) {
            prev = current;
            list = current;
        } else {
            prev->next = current;
            prev = current;
        }
    }
    return list;
}

void print_list(node *list) {
    while(list != NULL) {
        cout << list->value << " ";
        list = list->next;
    }
    cout << endl;
}

int main() {
    vector<int> v = {4, 2, 0, 7, 3, 0, 6, 3};
    int x = 4;
    
    node *list = vector_to_list(v);
    print_list(list);
    cout << "After partitioning around " << x << ":" << endl;
    partition_list(list, x);
    print_list(list);

    return 0;
}