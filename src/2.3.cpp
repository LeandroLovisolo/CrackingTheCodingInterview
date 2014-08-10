#include <iostream>
#include <vector>

using namespace std;

struct node {
	int value;
	node *next;
};

void delete_node(node *n) {
	n->value = n->next->value;
	node *old_node = n->next;
	n->next = n->next->next;
	delete old_node;
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
	int pos = 4;
	
	node *list = vector_to_list(v);
	node *n = list;
	for(int i = 0; i < pos; i++) n = n->next;

	print_list(list);
	cout << "After deleting the " << pos << "th node:" << endl;
	delete_node(n);
	print_list(list);

	return 0;
}