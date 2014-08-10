#include <iostream>
#include <vector>

using namespace std;

struct node {
	int value;
	node *next;
};

node* sum(node *x, node *y) {
	node *result = new node,
	     *current = result;
	current->value = 0;

	while(x != NULL || y != NULL) {
		if(x != NULL && y != NULL) {
			current->value += x->value + y->value;
			current->next = new node;
			if(current->value >= 10) {
				current->next->value = 1;
				current->value = current->value - 10;
			} else {
				current->next->value = 0;
			}
			current = current->next;
			x = x->next;
			y = y->next;
		} else {
			if(x != NULL) {
				current->value = x->value;
				x = x->next;
			} else {
				current->value = y->value;
				y = y->next;
			}
			current->next = new node;
			current->next->value = 0;
			current = current->next;
		}
	}
	current->next = NULL;

	node *prev;
	current = result;
	while(current->next != NULL) {
		prev = current;
		current = current->next;
	}
	if(prev != NULL) {
		delete current;
		prev->next = NULL;
	}

	return result;
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
	vector<int> x = {6, 5, 2};
	vector<int> y = {7, 3};
	node *xx = vector_to_list(x);
	node *yy = vector_to_list(y);

	print_list(xx);
	cout << "+" << endl;
	print_list(yy);
	cout << "----------" << endl;
	print_list(sum(xx, yy));
	cout << endl;

	return 0;
}