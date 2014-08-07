#include <iostream>
#include <vector>

using namespace std;

struct node {
	int value;
	node *next;
};

int kth_to_last(node *list, int k) {
	int i = 0;
	node *head = list;
	node *kth = NULL;
	while(list != NULL) {
		if(i == k) {
			kth = head;
		}
		if(i > k) {
			kth = kth->next;
		}
		list = list->next;
		i++;
	}
	if(kth == NULL) {
		return -1;
	}
	return kth->value;
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
	int k = 4;
	int kth = kth_to_last(list, k);
	print_list(list);
	cout << "k = " << k << endl;
	cout << "kth = " << kth << endl;
	return 0;
}