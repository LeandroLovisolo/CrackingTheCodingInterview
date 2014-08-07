#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node {
	int value;
	node *next;
};

void remove_duplicates(node *list) {
	set<int> values;
	node *prev = NULL;
	while(list != NULL) {
		if(values.find(list->value) == values.end()) {
			values.insert(list->value);
			prev = list;
			list = list->next;
		} else {
			prev->next = list->next;
			delete list;
			list = prev->next;
		}
	}
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
	node *list = vector_to_list(v);
	cout << "Original:" << endl;
	print_list(list);
	remove_duplicates(list);
	cout << "Without duplicates:" << endl;
	print_list(list);
	return 0;
}